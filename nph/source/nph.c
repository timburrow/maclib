/* nph - new phase adjustment based on a regression analysis on
	 parts of spectral baseline adjacent to two peak areas */

/* syntax:  nph exp_file index ll_start ll_end lr_start lr_end \
			       rl_start rl_end rr_start rr_end rp lp
*/

/*	
	compilation (Solaris):
		cc -O -o nph nph.c -lm

	1992-09-21 - r.kyburz, created
	1992-09-22 - r.kyburz, revised (completed, refined)
	2002-06-25 - r.kyburz, checked for Solaris
*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
#include <sys/utsname.h>

#ifndef M_PI 
#define M_PI 3.14159265358979323846 
#endif

#define MAXPATHL 1024
#define NLIMITS 8

#define STARTSTEP 5.0
#define DIVIDER   3.0
#define STEPLIMIT 0.1

static char rev[] =     "nph.c 3.2";
static char revdate[] = "2010-11-08_14:45";


static char cmd[] = "nph";
static int  debug = 0;
static int  swap  = 0;

/*------------+
| Definitions |
+------------*/

/* defining structures */
struct fileHeader
{
  int nblocks, ntraces, np, ebytes, tbytes, bbytes;
  short vers_id, status;
  int nblockheaders;
};
struct blockHeader
{
  short scale, status, index, mode;
  int ctcount;
  float lpval, rpval, lvl, tlt;
};


/* defining variables */
struct fileHeader fheader;
struct blockHeader bheader;
FILE *data;
FILE *outfile;
int ok, indx = 0, ix;
int iterations = 0;
int decrements = 0;
int limits[NLIMITS];
double lp, rp, sqsum, rms, startrms, diff;
double lpos, rpos, delta1, delta2;
char dataname[MAXPATHL];
char outputname[MAXPATHL];
float *llnoise, *lrnoise;
float *rlnoise, *rrnoise;
struct complex
{
  float real, imag;
};
struct complex *spectrum;
struct linregr
{
  double n, x, y, xy, x2;
  double slope, intercept;
};
struct linregr lreg, rreg;


/*-----------------------------------------------------------------+
| swapbytes - Byte swapping for big-endian vs. little-endian issue |
+-----------------------------------------------------------------*/

void swapbytes(void *data, int size, int num)
{
  unsigned char *c, cs;
  int i, j;
  c = (unsigned char *) data;
  for (j = 0; j < num; j++)
  {
    for (i = 0; i < size/2; i++)
    {
      cs = c[size * j + i];
      c[size * j + i] = c[size * j + (size - (i + 1))];
      c[size * j + (size - (i + 1))] = cs;
    }
  }
}


/*--------------+
| ============= |
| MAIN FUNCTION |
| ============= |
+--------------*/


main (argc, argv)
  int argc;
  char *argv[];
{
  struct utsname *s_uname;

  if (argc >= 2)
  {
    if ((!strcasecmp(argv[1], "-v")) || (!strcasecmp(argv[1], "-version")))
    {
      (void) printf("%s (%s)\n", rev, revdate);
      exit(0);
    }
  }


  /*-------------------+
  | checking arguments |
  +-------------------*/

  /* number of arguments: 12 exactly */
  if ((argc < 13) || (argc > 13))
  {
    fprintf(stderr,
      "Usage:  nph exp_file index [8 noise delimiters] rp lp\n");
    exit(1);
  }

  /*------------------------------------------------------+
  | check current system architecture (for byte swapping) |
  +------------------------------------------------------*/

  s_uname = (struct utsname *) malloc(sizeof(struct utsname));
  ok = uname(s_uname);
  if (ok >= 0)
  {
    if (debug)
    {
      (void) fprintf(stderr, "\nExtracted \"uname\" information:\n");
      (void) fprintf(stderr, "   s_uname->sysname:   %s\n", s_uname->sysname);
      (void) fprintf(stderr, "   s_uname->nodename:  %s\n", s_uname->nodename);
      (void) fprintf(stderr, "   s_uname->release:   %s\n", s_uname->release);
      (void) fprintf(stderr, "   s_uname->version:   %s\n", s_uname->version);
      (void) fprintf(stderr, "   s_uname->machine:   %s\n", s_uname->machine);
    }

    /* PC / Linux or Mac / Intel / MacOS X marchitecture */
    if ((char *) strstr(s_uname->machine, "86") != (char *) NULL)
    {
      if (debug)
      {
        (void) fprintf(stderr, "   Intel x86 architecture:");
      }
      swap = 1;
    }

    /* Sun / SPARC architecture */
    else if (!strncasecmp(s_uname->machine, "sun", 3))
    {
      if (debug)
      {
        (void) fprintf(stderr,
                "   \"%s\" (Sun SPARC) architecture:", s_uname->machine);
      }
      swap = 0;
    }

    /* PowerMac / MacOS X */
    else if (!strncasecmp(s_uname->machine, "power macintosh", 15))
    {
      if (debug)
      {
        (void) printf("   \"%s\" architecture (PowerPC / MacOS X):",
                s_uname->machine);
      }
      swap = 0;
    }

    /* OTHER ARCHITECTURES */
    else
    {
      if (debug)
      {
        (void) fprintf(stderr, "   \"%s\" architecture:", s_uname->machine);
      }
      swap = 1;
    }

    if (debug)
    {
      if (swap)
      {
        (void) fprintf(stderr, "  SWAPPING BYTES on Varian data\n");
      }
      else
      {
        (void) fprintf(stderr, "  NOT swapping bytes on Varian data\n");
      }
    }
  }
  else
  {
    (void) fprintf(stderr,
        "%s:  unable to determine system architecture, aborting.\n", cmd);
    exit(1);
  }


  /* arg1:  experiment directory */
  strcpy(dataname, argv[1]);
  strcat(dataname, "/datdir/data");
  strcpy(outputname, argv[1]);
  strcat(outputname, "/nph.out");

  /* arg2:  spectrum index */
  ok = sscanf(argv[2], "%d", &indx);
  if ((!ok) || (indx < 0))
  { 
    fprintf(stderr, "nph:  argument #2 must be a positive integer!\n");
    exit(1); 
  }

  /* arg3 - arg10:  noise limits */
  for (ix = 0; ix < NLIMITS; ix++)
  {
    ok = sscanf(argv[ix + 3], "%d", &limits[ix]);
    if ((!ok) || (limits[ix] < 0))
    {
      fprintf(stderr,
	"nph:  argument #%d must be a positive integer!\n", ix+3);
      exit(1);
    }
  }
  /* sort noise limits */
  sort_limits();

  /* arg11 / arg12:  current phase values */
  ok = sscanf(argv[11], "%lf", &rp);
  if (!ok)
  { 
    fprintf(stderr, "nph:  argument #11 must be numeric!\n"); 
    exit(1); 
  } 
  ok = sscanf(argv[12], "%lf", &lp);
  if (!ok)
  { 
    fprintf(stderr, "nph:  argument #12 must be numeric!\n"); 
    exit(1); 
  } 
 

  /*------------------+
  | check file access |
  +------------------*/

  /* open fid file and read file header */
  data = fopen(dataname, "r");
  if ( data == NULL )
  {
    fprintf(stderr, "nph: problem opening file %s\n", dataname);
    exit(1);
  }

  /* open diagnostics output file */
  outfile = fopen(outputname, "w");
  if ( outfile == NULL )
  {
    fprintf(stderr, "nph: problem creating output file %s\n", outputname);
    fclose(data);
    exit(1);
  }

  /* read file header */
  if ( fread(&fheader, 1, sizeof(fheader), data ) == 0 )
  {
    fprintf(stderr, "nph:  problem reading %s (1)\n", dataname);
    fclose(outfile);
    fclose(data);
    exit(1);
  }
  if (swap)
  {
    swapbytes(&fheader.nblocks,       sizeof(int),   1);
    swapbytes(&fheader.ntraces,       sizeof(int),   1);
    swapbytes(&fheader.np,            sizeof(int),   1);
    swapbytes(&fheader.ebytes,        sizeof(int),   1);
    swapbytes(&fheader.tbytes,        sizeof(int),   1);
    swapbytes(&fheader.bbytes,        sizeof(int),   1);
    swapbytes(&fheader.vers_id,       sizeof(short), 1);
    swapbytes(&fheader.status,        sizeof(short), 1);
    swapbytes(&fheader.nblockheaders, sizeof(int),   1);
  }

  /* check data status */
  if (fheader.ntraces != 1)
  {
    fprintf(stderr, "nph:  not implemented for ntraces > 1\n");
    fclose(outfile);
    fclose(data);
    exit(1);
  }
  if ((fheader.status & 0x1b) != 0x1b) 
  {
    fprintf(stderr, "nph:  %s does not contain a spectrum\n");
    fclose(outfile);
    fclose(data);
    exit(1);
  }
  if ((fheader.status & 0x800) != 0x800) 
  {
    fprintf(stderr, "nph:  only works on 1D spectra\n");
    fclose(outfile);
    fclose(data);
    exit(1);
  }

  /* skip traces, if necessary */
  if ( fseek(data, (indx - 1) * fheader.bbytes, 1) != 0 )
  {
    fprintf(stderr, "nph:  problem reading %s (2)\n", dataname);
    fclose(outfile);
    fclose(data);
    exit(1);
  }

  /* read block header */
  ok = fread(&bheader, 1, sizeof(bheader), data);
  if (!ok)
  {
    fprintf(stderr, "nph:  problem reading %s (3)\n", dataname);
    fclose(outfile);
    fclose(data);
    exit(1);
  }
  if (swap)
  {
    swapbytes(&bheader.scale,   sizeof(short), 1);
    swapbytes(&bheader.status,  sizeof(short), 1);
    swapbytes(&bheader.index,   sizeof(short), 1);
    swapbytes(&bheader.mode,    sizeof(short), 1);
    swapbytes(&bheader.ctcount, sizeof(int),   1);
    swapbytes(&bheader.lpval,   sizeof(float), 1);
    swapbytes(&bheader.rpval,   sizeof(float), 1);
    swapbytes(&bheader.lvl,     sizeof(float), 1);
    swapbytes(&bheader.tlt,     sizeof(float), 1);
  }

  if ((bheader.status & 0x1b) != 0x1b) 
  {
    fprintf(stderr, "nph:  %s does not contain a spectrum\n");
    fclose(outfile);
    fclose(data);
    exit(1);
  }
  if ((bheader.status & 0x100) != 0x100)
  {
    fprintf(stderr, "nph:  only works on 1D spectra\n");
    fclose(outfile);
    fclose(data);
    exit(1);
  }
  if (bheader.mode != 0x1)
  {
    fprintf(stderr, "nph:  only works for 1D spectra in ph mode\n");
    fclose(outfile);
    fclose(data);
    exit(1);
  }

  /* allocate memory space for spectrum and calculated noise regions */
  spectrum = (struct complex *)malloc(fheader.tbytes);
  if (spectrum == NULL)
  {
    fprintf(stderr, "nph:  unable to allocate buffer memory.\n");
    fclose(outfile);
    fclose(data);
    exit(1);
  }
  llnoise = (float *) malloc((limits[1] - limits[0] + 1)*sizeof(float));
  lrnoise = (float *) malloc((limits[3] - limits[2] + 1)*sizeof(float));
  rlnoise = (float *) malloc((limits[5] - limits[4] + 1)*sizeof(float));
  rrnoise = (float *) malloc((limits[7] - limits[6] + 1)*sizeof(float));
  if ((llnoise == NULL) || (lrnoise == NULL) ||
      (rlnoise == NULL) || (rrnoise == NULL))
  {
    fprintf(stderr, "nph:  unable to allocate buffer memory.\n");
    freebuffers();
    fclose(outfile);
    fclose(data);
    exit(1);
  }

  /* read spectrum */
  ok = fread(spectrum, 1, fheader.tbytes, data);
  if (!ok)
  { 
    fprintf(stderr, "nph:  problem reading spectrum from %s\n", dataname);
    freebuffers();
    fclose(outfile);
    fclose(data);
    exit(1);
  }
  if (swap)
    swapbytes(&spectrum, sizeof(float), fheader.np);


  /* close spectrum file */
  fclose(data);

  iterate();

  fclose(outfile);
  printf("%6.1f\n%6.1f\n", rp, lp);

  /* free memory buffers */
  freebuffers();

  return(0);
}

sort_limits()
{
  register int i, j, tmp;
  for (i = NLIMITS - 1; i > 0; i--)
  {
    for (j = 0; j < i; j++)
    {
      if (limits[j] > limits[j+1])
      {
        tmp = limits[j];
	limits[j] = limits[j+1];
	limits[j+1] = tmp;
      }
    }
  }
}

freebuffers()
{
  free(llnoise);
  free(lrnoise);
  free(rlnoise);
  free(rrnoise);
  free(spectrum);
}


/*==============================================================+
||  DO REGRESSION ANALYSIS AND CALCULATE RMS NOISE DIFFERENCE  ||
+==============================================================*/

double rmsbase(lnoise, rnoise, limit1, limit2, limit3, limit4)
  float *lnoise;
  float *rnoise;
  int limit1, limit2, limit3, limit4;
{
  register int ix;
  register double rmsvalue;

  /* do left side regression analysis */
  lreg.n = (double) (limit2 - limit1 + 1);
  lreg.x = 0.0;
  lreg.x2 = 0.0;
  lreg.y = 0.0;
  lreg.xy = 0.0;
  for (ix = limit1; ix <= limit2; ix++)
  {
    lreg.x += (double) ix;
    lreg.x2 += (double) (ix * ix);
    lreg.y += ((double) (lnoise[ix - limit1]));
    lreg.xy += ((double) (lnoise[ix - limit1])) * ((double) ix);
  }
  lreg.slope =  (lreg.xy * lreg.n - lreg.x * lreg.y);
  lreg.slope /= (lreg.x2 * lreg.n - lreg.x * lreg.x);
  lreg.intercept =  (lreg.x2 * lreg.y - lreg.x * lreg.xy);
  lreg.intercept /= (lreg.x2 * lreg.n - lreg.x * lreg.x );

  /* do right side regression analysis */
  rreg.n = (double) (limit4 - limit3 + 1);
  rreg.x = 0.0;
  rreg.x2 = 0.0;
  rreg.y = 0.0;
  rreg.xy = 0.0;
  for (ix = limit3; ix <= limit4; ix++)
  {
    rreg.x += (double) ix;
    rreg.x2 += (double) (ix * ix);
    rreg.y += ((double) (rnoise[ix - limit3]));
    rreg.xy += (double) (rnoise[ix - limit3]) * ((double) ix);
  }
  rreg.slope =  (rreg.xy * rreg.n - rreg.x * rreg.y);
  rreg.slope /= (rreg.x2 * rreg.n - rreg.x * rreg.x);
  rreg.intercept =  (rreg.x2 * rreg.y - rreg.x * rreg.xy);
  rreg.intercept /= (rreg.x2 * rreg.n - rreg.x * rreg.x );

  /* calculate sum of squared differences */
  sqsum = 0.0;
  for (ix = limit2 + 1; ix < limit3; ix++)
  {
    diff = (lreg.intercept + lreg.slope * ((double) ix)) -
           (rreg.intercept + rreg.slope * ((double) ix));
    sqsum += (diff * diff);
  }
  rmsvalue = sqrt(sqsum/((double) (limit3 - limit2 - 2)));

  return(rmsvalue);
}


/*============+
||  ITERATE  ||
+============*/

iterate()
{
  fprintf(outfile,
     "phasing   ix     rp     lp    step    rms l/h     slope1     slope2\n");
  fprintf(outfile,
     "--------- --- ------ ------  ----- -----------  ---------  ---------\n");
  lpos = ((double) (limits[1] + limits[2]))/2.0;
  rpos = ((double) (limits[5] + limits[6]))/2.0;
  delta1 = rpos - lpos;
  delta2 = ((double) (fheader.np - 1))/2.0 - rpos;
  startrms = 0.0;
  rp_iterate_hifield(STARTSTEP/1.0, DIVIDER, 3.0*STEPLIMIT);
  iterate_lofield(STARTSTEP/1.0, DIVIDER, 3.0*STEPLIMIT);
  iterate_hifield(STARTSTEP/2.0, DIVIDER, 2.0*STEPLIMIT);
  iterate_lofield(STARTSTEP/2.0, DIVIDER, 2.0*STEPLIMIT);
  iterate_hifield(STARTSTEP/4.0, DIVIDER, 1.0*STEPLIMIT);
  iterate_lofield(STARTSTEP/4.0, DIVIDER, 1.0*STEPLIMIT);
  iterate_hifield(STARTSTEP/8.0, DIVIDER, 1.0*STEPLIMIT);
  fprintf(outfile,"\nnumber of iteration steps           = %3d\n",iterations);
  fprintf(outfile,  "number of step size decrementations = %3d\n",decrements);
}

iterate_lofield(startstep, divider, steplimit)
  double startstep, divider, steplimit;
{
  double direction, startdir, lastrms, corr;
  double step = startstep;
  int niter;
  calc_noise(llnoise, limits[0], limits[1]);
  calc_noise(lrnoise, limits[2], limits[3]);
  rms = rmsbase(llnoise, lrnoise, limits[0], limits[1], limits[2], limits[3]);
  if ( lreg.slope + rreg.slope > 0 )
     direction = 1.0;
  else
     direction = -1.0;
  startdir = direction;
  step = startstep;
  niter = 0;
  lastrms = rms;
  if (startrms == 0) startrms = rms;
  fprintf(outfile,"lowfield  %2d: %6.1f %6.1f %6.2f %9.6f   %10.3g %10.3g\n",
	niter, rp, lp, step * direction, rms / startrms,
	lreg.slope, rreg.slope);
  do
  {
    niter++;
    corr = ((double) direction) * step;
    rp = rp - corr * delta2 / delta1;
    lp = lp + corr * ((double) (fheader.np/2 - 1)) / delta1;
    calc_noise(llnoise, limits[0], limits[1]);
    calc_noise(lrnoise, limits[2], limits[3]);
    rms = rmsbase(llnoise, lrnoise, limits[0], limits[1], limits[2], limits[3]);
    if (rms > lastrms)
    {
      direction *= -1.0;
      if (! ((step == startstep) && (direction != startdir)))
      {
        step /= divider;
	decrements++;
      }
    }
    fprintf(outfile,"lowfield  %2d: %6.1f %6.1f %6.2f %9.6f   %10.3g %10.3g\n",
	niter, rp, lp, step * direction, rms / startrms,
	lreg.slope, rreg.slope);
    lastrms = rms;
  }
  while (step >= steplimit);
  /* revert last step */
  step *= divider;
  corr = ((double) direction) * step;
  rp = rp - corr * delta2 / delta1;
  lp = lp + corr * ((double) (fheader.np/2 - 1)) / delta1;
  iterations += niter;
}

iterate_hifield(startstep, divider, steplimit)
  double startstep, divider, steplimit;
{
  double direction, startdir, lastrms, corr;
  double step = startstep;
  int niter;
  calc_noise(rlnoise, limits[4], limits[5]);
  calc_noise(rrnoise, limits[6], limits[7]);
  rms = rmsbase(rlnoise, rrnoise, limits[4], limits[5], limits[6], limits[7]);
  if ( lreg.slope + rreg.slope > 0 )
     direction = 1.0;
  else
     direction = -1.0;
  niter = 0;
  startdir = direction;
  niter = 0;
  lastrms = rms;
  if (startrms == 0) startrms = rms;
  fprintf(outfile,"highfield %2d: %6.1f %6.1f %6.2f   %9.6f %10.3g %10.3g\n",
	niter, rp, lp, step * direction, rms / startrms,
	lreg.slope, rreg.slope);
  do
  {
    niter++;
    corr = ((double) direction) * step;
    rp = rp + corr * (delta1 + delta2)/delta1;
    lp = lp - corr * ((double) (fheader.np/2 - 1)) / delta1;
    calc_noise(rlnoise, limits[4], limits[5]);
    calc_noise(rrnoise, limits[6], limits[7]);
    rms = rmsbase(rlnoise, rrnoise, limits[4], limits[5], limits[6], limits[7]);
    if (rms > lastrms)
    {
      direction *= -1.0;
      if (! ((step == startstep) && (direction != startdir)))
      {
        step /= divider;
	decrements++;
      }
    }
    fprintf(outfile,"highfield %2d: %6.1f %6.1f %6.2f   %9.6f %10.3g %10.3g\n",
	niter, rp, lp, step * direction, rms / startrms,
	lreg.slope, rreg.slope);
    lastrms = rms;
  }
  while (step >= steplimit);
  /* revert last step */
  step *= divider;
  corr = ((double) direction) * step;
  rp = rp + corr * (delta1 + delta2)/delta1;
  lp = lp - corr * ((double) (fheader.np/2 - 1)) / delta1;
  iterations += niter;
}

rp_iterate_hifield(startstep, divider, steplimit)
  double startstep, divider, steplimit;
{
  double direction, startdir, lastrms, corr;
  double step = startstep;
  int niter;
  calc_noise(rlnoise, limits[4], limits[5]);
  calc_noise(rrnoise, limits[6], limits[7]);
  rms = rmsbase(rlnoise, rrnoise, limits[4], limits[5], limits[6], limits[7]);
  if ( lreg.slope + rreg.slope > 0 )
     direction = 1.0;
  else
     direction = -1.0;
  niter = 0;
  startdir = direction;
  niter = 0;
  lastrms = rms;
  if (startrms == 0) startrms = rms;
  fprintf(outfile,"highfield %2d: %6.1f %6.1f %6.2f   %9.6f %10.3g %10.3g\n",
	niter, rp, lp, step * direction, rms / startrms,
	lreg.slope, rreg.slope);
  do
  {
    niter++;
    corr = ((double) direction) * step;
    rp = rp + corr;
    calc_noise(rlnoise, limits[4], limits[5]);
    calc_noise(rrnoise, limits[6], limits[7]);
    rms = rmsbase(rlnoise, rrnoise, limits[4], limits[5], limits[6], limits[7]);
    if (rms > lastrms)
    {
      direction *= -1.0;
      if (! ((step == startstep) && (direction != startdir)))
      {
        step /= divider;
	decrements++;
      }
    }
    fprintf(outfile,"highfield %2d: %6.1f %6.1f %6.2f   %9.6f %10.3g %10.3g\n",
	niter, rp, lp, step * direction, rms / startrms,
	lreg.slope, rreg.slope);
    lastrms = rms;
  }
  while (step >= steplimit);
  /* revert last step */
  step *= divider;
  corr = ((double) direction) * step;
  rp = rp + corr;
  iterations += niter;
}

calc_noise(noise, start, end)
  float *noise;
  int start, end;
{
  register int i;
  register double phase;
  register double width = (double) (fheader.np / 2 - 1);
  register double mult = M_PI / 180.0;
  for (i = start; i <= end; i++)
  {
    phase = rp + lp * (width - (double) i) / width;
    phase *= mult;
    noise[i - start] = spectrum[i].real * (float) cos(phase) +
		       spectrum[i].imag * (float) sin(phase);
  }
}
