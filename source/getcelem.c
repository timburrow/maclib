/* getcelem.c */
/* VJ Tz 990210 */
/* cc getcelem.c -O -o getcelem */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STMX	256

typedef struct
{
  long nblocks;
  long ntraces;
  long np;
  long ebytes;
  long tbytes;
  long bbytes;
  short vers_id;
  short status;
  long nbheaders;
}
datafilehead;

#define S_DATA		0x1
#define S_SPEC		0x2
#define S_32		0x4
#define S_FLOAT		0x8
#define S_COMPLEX	0x10
#define S_HYPERCOMPLEX	0x20
#define S_ACQPAR	0x80
#define S_SECND		0x100
#define S_TRANSF	0x200
#define S_NP		0x800
#define S_NF		0x1000
#define S_NI		0x2000
#define S_NI2		0x4000

void prdtflhd(datafilehead dtflhd)
{
  printf("nblocks  :%d\n", dtflhd.nblocks);
  printf("ntraces  :%d\n", dtflhd.ntraces);
  printf("np       :%d\n", dtflhd.np);
  printf("ebytes   :%d\n", dtflhd.ebytes);
  printf("tbytes   :%d\n", dtflhd.tbytes);
  printf("nbytes   :%d\n", dtflhd.bbytes);
  printf("vers_id  :%d\n", dtflhd.vers_id);
  printf("nbheaders:%d\n", dtflhd.nbheaders);

  printf("S_DATA         :%d\n", dtflhd.status & S_DATA);
  printf("S_SPEC         :%d\n", dtflhd.status & S_SPEC);
  printf("S_32           :%d\n", dtflhd.status & S_32);
  printf("S_FLOAT        :%d\n", dtflhd.status & S_FLOAT);
  printf("S_COMPLEX      :%d\n", dtflhd.status & S_COMPLEX);
  printf("S_HYPERCOMPLEX :%d\n", dtflhd.status & S_HYPERCOMPLEX);
  printf("S_ACQPAR       :%d\n", dtflhd.status & S_ACQPAR);
  printf("S_SECND        :%d\n", dtflhd.status & S_SECND);
  printf("S_TRANSF       :%d\n", dtflhd.status & S_TRANSF);
  printf("S_NP           :%d\n", dtflhd.status & S_NP);
  printf("S_NF           :%d\n", dtflhd.status & S_NF);
  printf("S_NI           :%d\n", dtflhd.status & S_NI);
  printf("S_NI2          :%d\n", dtflhd.status & S_NI2);
}

typedef struct
{
  short scale;
  short status;
  short index;
  short mode;
  long ctcount;
  float lpval;
  float rpval;
  float lvl;
  float tlt;
}
datablockhead;

#define MORE_BLOCKS	0x80
#define NP_CMPLX	0x100
#define NF_CMPLX	0x200
#define NI_CMPLX	0x400
#define NI2_CMPLX	0x800

void prdtblhd(datablockhead dtblhd)
{
  printf("scale   :%d\n", dtblhd.scale);
  printf("index   :%d\n", dtblhd.index);
  printf("mode    :%d\n", dtblhd.mode);
  printf("ctcount :%d\n", dtblhd.ctcount);
  printf("lpval   :%f\n", dtblhd.lpval);
  printf("rpval   :%f\n", dtblhd.rpval);
  printf("lvl     :%f\n", dtblhd.lvl);
  printf("tlt     :%f\n", dtblhd.tlt);

  printf("S_DATA         :%d\n", dtblhd.status & S_DATA);
  printf("S_SPEC         :%d\n", dtblhd.status & S_SPEC);
  printf("S_32           :%d\n", dtblhd.status & S_32);
  printf("S_FLOAT        :%d\n", dtblhd.status & S_FLOAT);
  printf("S_COMPLEX      :%d\n", dtblhd.status & S_COMPLEX);
  printf("S_HYPERCOMPLEX :%d\n", dtblhd.status & S_HYPERCOMPLEX);

  printf("MORE_BLOCKS    :%d\n", dtblhd.status & MORE_BLOCKS);
  printf("NP_CMPLX       :%d\n", dtblhd.status & NP_CMPLX);
  printf("NF_CMPLX       :%d\n", dtblhd.status & NF_CMPLX);
  printf("NI_CMPLX       :%d\n", dtblhd.status & NI_CMPLX);
  printf("NI2_CMPLX      :%d\n", dtblhd.status & NI2_CMPLX);
}

typedef struct
{
  short s_spare1;
  short status;
  short s_spare2;
  short s_spare3;
  long l_spare1;
  float lpval1;
  float rpval1;
  float f_spare1;
  float f_spare2;
}
hypercmplxbhead;

#define NP_PHMODE	0x1
#define NP_AVMODE	0x2
#define NP_PWRMODE	0x4
#define NF_PHMODE	0x10
#define NF_AVMODE	0x20
#define NF_PWRMODE	0x40
#define NI_PHMODE	0x100
#define NI_AVMODE	0x200
#define NI_PWRMODE	0x400
#define NI2_PHMODE	0x1000
#define NI2_AVMODE	0x2000
#define NI2_PWRMODE	0x4000
#define U_HYPERCOMPLEX	0x2


main(argc, argv)
int argc;
char *argv[];
{
  char fl[STMX];
  datafilehead dtflhd;
  datablockhead dtblhd;
  FILE *fi;
  int nblocks, ebytes, ntraces, np, i, j;
  long ctmx, idmx;
  void *fid;

  if (argc > 1)
  {
    strcpy(fl, argv[1]);
  }
  else
  {
    sprintf(fl, "%s%s%s", "/vnmr/fidlib/", "fid1d", ".fid/fid");
  }

  ctmx = 0;
  idmx = 0;
  /* printf("*** fl %s\n",fl); */
  fi = fopen(fl, "r");

  fread(&dtflhd, 32, 1, fi);
  /* prdtflhd(dtflhd); */

  nblocks = dtflhd.nblocks;
  ntraces = dtflhd.ntraces;
  /* printf("*** nblocks*ntraces %d\n",nblocks*ntraces); */

  ebytes = dtflhd.ebytes;
  np = dtflhd.np;
  fid = malloc(ebytes * np);
  for (i = 0; i < nblocks; i++)
  {
    fread(&dtblhd, 28, 1, fi);
    if (dtblhd.ctcount > ctmx)
      ctmx = dtblhd.ctcount;
    if ((idmx == dtblhd.index) || (idmx + 1 == dtblhd.index))
    {
      idmx = dtblhd.index;
    }
    else
    {
      if (dtblhd.ctcount > 0)
	idmx = i + 1;
    }
    /* prdtblhd(dtblhd); */
    for (j = 0; j < ntraces; j++)
    {
      fread(fid, ebytes, np, fi);
    }
  }
  fclose(fi);
  printf("%d\n%d\n", idmx, ctmx);
/*printf("%d\n%d\n", idmx * ntraces, ctmx);*/
}
