#Userlib/maclib
This repository contains the userlib/maclib contributions for VnmrJ as
packaged in VnmrJ 4.2

##NOTES & CAUTIONS
* Many of these contributions were incorporated into the core VnmrJ
software years ago, so may be redundant with core capabilities
* Most of the contributions are obsolete.
* Though many contributions work, there is often a better way of doing
things in the more modern software
* These contributions are not guaranteed to work
* These tools may work on some systems but not others. Many will only
work with certain versions of VnmrJ, VNMR, RHEL, or Solaris.
* Use these tools at your own risk. Some of them, such as pulse sequences,
could potentially damage hardware, and neither Agilent nor UO is
responsible for such damage.
* Though this is the User Library, users' contributions are mixed
with those from Varian and Agilent staff. On Spinsights, similar
Agilent-provided materials like Chempack are available in Toolkit, and
shared materials from users/customers are here in User Library. Agilent
staff still do contribute to the currently active User Library, but,
like all other contributions, those are personal materials that they
have developed and find useful, and they are not officially supported by
Agilent or guaranteed to work.
* The last update to this file was performed on February 1, 2013, and it
will not be updated again.
* This initially should only contain contributions from Agilent and/or
Varian but your contributions are welcome

##Downloading
You may download this repository from GitHub at:
https://github.com/OpenVnmrJ/maclib.git

##Updating and adding
- Fork on GitHub
- Do not add your contribution to the master branch
- If updating contribution, checkout the tag of the contribution, update
and commit on the contribution branch
- If adding a new contribution, checkout a new branch with the name of
the contribution, push the new branch to your repository, add and commit
on the new branch
- Tag your update of change with the name of the contribution, followed
by a version, for example, mymacro-v1.1
- Push your branch to your fork; remember to push the tags too
- Make a pull request to the OpenVnmrJ repository

##Contributions

Below is a list of each contribution. To access a contributions, check
out its tag

##acq3dpl
>acquires 3D spectra as a series of f1f3 planes (no 3D processing with
VnmrJ / VNMR, but gives faster access to the first 3D plane).

---
To install the contribution, checkout the tag acq3dpl-v1.0:

    git checkout acq3dpl-v1.0

then read acq3dpl.README

Usually use extract to install the contribution:

    extract maclib/acq3dpl

##batchprocess
>

---
To install the contribution, checkout the tag batchprocess-v1.0:

    git checkout batchprocess-v1.0

then read batchprocess.README

Usually use extract to install the contribution:

    extract maclib/batchprocess

##bcdc
>"bcdc" uses the "bc" command in a way that prevents flattening
broad signals that "region" failed to integrate: "bcdc" does an
individual, linear correction on every baseline (= not integrated)
region. Useful for automatic integration in automation, especially
if samples contain broad signals from exchangeable protons. "bcdc"
was written in cooperation with / based on suggestions by Cornelius
de Korte, Solvay Pharmaceuticals, Weesp NL.

---
To install the contribution, checkout the tag bcdc-v1.0:

    git checkout bcdc-v1.0

then read bcdc.README

Usually use extract to install the contribution:

    extract maclib/bcdc

##calcphase
>Calculate phase of spectrum based on the first complex point of the
FID. This is primarily designed for cases in which the first point
of the FID occurs exactly at time zero, i.e., an echo. In this case,
calcphase may produces answers which are more reliable than aph
or aph0.

---
To install the contribution, checkout the tag calcphase-v1.0:

    git checkout calcphase-v1.0

then read calcphase.README

Usually use extract to install the contribution:

    extract maclib/calcphase

##compareandplot
>compares 2D displays with trace='f1' and trace='f2' for same
cross-peaks and plots

---
To install the contribution, checkout the tag compareandplot-v1.0:

    git checkout compareandplot-v1.0

then read compareandplot.README

Usually use extract to install the contribution:

    extract maclib/compareandplot

##comparedim
>Compare / plot f1 and f2 symmetry equivalents of a COSY-type 2D
expansion

---
To install the contribution, checkout the tag comparedim-v1.0:

    git checkout comparedim-v1.0

then read comparedim.README

Usually use extract to install the contribution:

    extract maclib/comparedim

##compare
>compares 2D displays with trace='f1' and trace='f2' for same
cross-peaks

---
To install the contribution, checkout the tag compare-v1.0:

    git checkout compare-v1.0

then read compare.README

Usually use extract to install the contribution:

    extract maclib/compare

##convolute
>Generates Shifted Laminar Pulses (S.L. Patt, J. Magn. Reson., 96, 94
(1992)) which allow simultaneous excitation of one or more non-zero
frequencies with any shaped excitation (including hard). convolute
generates shapes in which all excitation frequencies have the same
excitation phase, while convolutep allows different starting phases
for different frequencies. addshapes adds (convolutes) two different
waveforms together.

---
To install the contribution, checkout the tag convolute-v1.0:

    git checkout convolute-v1.0

then read convolute.README

Usually use extract to install the contribution:

    extract maclib/convolute

##csll
>Produces a line list in a form compatible with CSEARCH from Sadtler
(allegedly), using DEPT and 1D spectra.

---
To install the contribution, checkout the tag csll-v1.0:

    git checkout csll-v1.0

then read csll.README

Usually use extract to install the contribution:

    extract maclib/csll

##dlli
>Creates (and displays) a line listing with integrals for each
individual line found. Used also for exporting line listings into
the SpecInfo spectral database software. For performing a baseline
correction prior to calling "dlli" or "nlli" we recommend using
"maclib/bcdc".

---
To install the contribution, checkout the tag dlli-v1.0:

    git checkout dlli-v1.0

then read dlli.README

Usually use extract to install the contribution:

    extract maclib/dlli

##dpconi
>Trivial macro to start an interactive dpcon display

---
To install the contribution, checkout the tag dpconi-v1.0:

    git checkout dpconi-v1.0

then read dpconi.README

Usually use extract to install the contribution:

    extract maclib/dpconi

##drawshape
>Draws waveforms (amplitude and phase) on the screen or plotter

---
To install the contribution, checkout the tag drawshape-v1.0:

    git checkout drawshape-v1.0

then read drawshape.README

Usually use extract to install the contribution:

    extract maclib/drawshape

##dshpl
>displays horizontal plane at cursor position in a 3D data set

---
To install the contribution, checkout the tag dshpl-v1.0:

    git checkout dshpl-v1.0

then read dshpl.README

Usually use extract to install the contribution:

    extract maclib/dshpl

##dsvpl
>displays vertical plane at cursor position in a 3D data set

---
To install the contribution, checkout the tag dsvpl-v1.0:

    git checkout dsvpl-v1.0

then read dsvpl.README

Usually use extract to install the contribution:

    extract maclib/dsvpl

##fpdc
>Does "fp" with dc correction on the individual traces

---
To install the contribution, checkout the tag fpdc-v1.0:

    git checkout fpdc-v1.0

then read fpdc.README

Usually use extract to install the contribution:

    extract maclib/fpdc

##fpi
>Report integral values from arrayed spectra (in analogy to the "fp"
command)

---
To install the contribution, checkout the tag fpi-v1.0:

    git checkout fpi-v1.0

then read fpi.README

Usually use extract to install the contribution:

    extract maclib/fpi

##getcelem
>The macro getcelem analyzes vnmrsys/exp*/acqfil/fid: it returns the
number of completed FIDs (celem) and completed transients (ct) in an
experiment, which may occasionally be set to 0 after an acquisition,
or after stopping or aborting an experiment prematurely. "getcelem"
sets them to their correct value.

---
To install the contribution, checkout the tag getcelem-v1.0:

    git checkout getcelem-v1.0

then read getcelem.README

Usually use extract to install the contribution:

    extract maclib/getcelem

##getxpk
>Extract cross-peak intensities from one or more NOESY spectra, based
on a single "manually" measured data set. This material was found
in Magnetic Moments, Vol. IV, No. 2, p. 18; corrections published
subsequent to that issue are incorporated into the macros.

---
To install the contribution, checkout the tag getxpk-v1.0:

    git checkout getxpk-v1.0

then read getxpk.README

Usually use extract to install the contribution:

    extract maclib/getxpk

##lcdatast
>Expands the functionality of the "lcdatast" macro to properly adjust
the UV chromatogram on the SUN screen for expansions of on-flow or
stop-flow measurements (with the standard macro, the UV is always
displayed for the whole time of the chromatography). The contribution
also makes "lcdatast" label intensities in the UV chromatogram
correctly.

---
To install the contribution, checkout the tag lcdatast-v1.0:

    git checkout lcdatast-v1.0

then read lcdatast.README

Usually use extract to install the contribution:

    extract maclib/lcdatast

##llbc
>"llbc" can be used to apply a "bc"  baseline correction to C13 and
other spectra with narrow lines and possibly substantial noise, where
"region" typically can't be used (or will fail to integrate small
signals). "llbc" sets up integral regions based on a line listing
(assuming threshold is pre-adjusted), then does a "bc" ("bc(1,80)")
before restoring the original integral reset points. For integrating
such spectra you may want to use the contribution "maclib/dlli".

---
To install the contribution, checkout the tag llbc-v1.0:

    git checkout llbc-v1.0

then read llbc.README

Usually use extract to install the contribution:

    extract maclib/llbc

##loadbiopack
>Install utility for BioPack; STRONGLY RECOMMENDED for a smooth
installation of "psglib/BioPack" from within VNMR or VnmrJ, see below
for instructions.

---
To install the contribution, checkout the tag loadbiopack-v1.0:

    git checkout loadbiopack-v1.0

then read loadbiopack.README

Usually use extract to install the contribution:

    extract maclib/loadbiopack

##lsbru
>Sets "lp" for data from Bruker "D" series spectrometers (DPX/DRX/DMX,
Avance), based on the "decim" and "dspfvs" parameters ("lp" can
be 25000 degrees and more with such non-time corrected, digitally
filtered FIDs).

---
To install the contribution, checkout the tag lsbru-v1.0:

    git checkout lsbru-v1.0

then read lsbru.README

Usually use extract to install the contribution:

    extract maclib/lsbru

##macrocalls
>VNMR macro debugging utilities that permit finding macro calls in
the specified macro, or macros calling the specified macro. Also
recursive searches (for macro calls in submacros, or macros calling
a parent macro etc.) are possible. The complete VNMR macro path is
taken into account.

---
To install the contribution, checkout the tag macrocalls-v1.0:

    git checkout macrocalls-v1.0

then read macrocalls.README

Usually use extract to install the contribution:

    extract maclib/macrocalls

##makehard
>Makes various hard pulse shapes

---
To install the contribution, checkout the tag makehard-v1.0:

    git checkout makehard-v1.0

then read makehard.README

Usually use extract to install the contribution:

    extract maclib/makehard

##mds
>Macros that simultaneously display or plot 1D segments in positions
that were previously defined and saved with "s1", "s2", "s3", etc.

---
To install the contribution, checkout the tag mds-v1.0:

    git checkout mds-v1.0

then read mds.README

Usually use extract to install the contribution:

    extract maclib/mds

##nph
>"nph" is an alternative phasing method for phasing "difficult" data,
such as C13 spectra from oil fractions. This method was first published
by Larry W. Sterna & Victor P. Tong from the Shell Westhollow Research
Center in Houston (FUEL 70, 941 (1991). It can also be used for other
spectra, provided they feature a large group of signal at either ends
of the spectrum, separated by some flat baseline in-between. This
VNMR implementation was first done in 1992 for M. Laenen, Shell,
Grand Couronne, France.

---
To install the contribution, checkout the tag nph-v1.0:

    git checkout nph-v1.0

then read nph.README

Usually use extract to install the contribution:

    extract maclib/nph

##piv
>"piv" acts the same way as "pir", except that it avoids label
overlap by writing numbers vertically and offset horizontally if
necessary. Related functions "pivn" and "dpiv"/"dpivn" are also
provided. This contribution is included with standard VnmrJ 2.2C/D
software and with Chempack 4.1 ("chempack/CP4").

---
To install the contribution, checkout the tag piv-v1.0:

    git checkout piv-v1.0

then read piv.README

Usually use extract to install the contribution:

    extract maclib/piv

##pl2d
>enhanced plcosy and plhxcor macros (broken out from packages.extend);
the enhancements include: - added test for running acquisition (to
avoid data corruption, see buglist) - avoids overlap of 1D traces
with parameters - bugs in 1D scaling fixed - plot area now properly
optimized, in particular if no 1D traces are plotted - compatible
with other parameter styles (bpa, pap) - 1D experiments do not have
to be specified upon first call if they are in default numbers (1H:
exp1, 13C: exp2), as described in the manual. - upscaling of 1D traces
through an optional argument.

---
To install the contribution, checkout the tag pl2d-v1.0:

    git checkout pl2d-v1.0

then read pl2d.README

Usually use extract to install the contribution:

    extract maclib/pl2d

##plot6
>plots 3d planes 6 at a time and displays concurrently

---
To install the contribution, checkout the tag plot6-v1.0:

    git checkout plot6-v1.0

then read plot6.README

Usually use extract to install the contribution:

    extract maclib/plot6

##savez
>a simple macro to autosave fids each bs

---
To install the contribution, checkout the tag savez-v1.0:

    git checkout savez-v1.0

then read savez.README

Usually use extract to install the contribution:

    extract maclib/savez

##setdof
>a simple macro to set 13C offsets

---
To install the contribution, checkout the tag setdof-v1.0:

    git checkout setdof-v1.0

then read setdof.README

Usually use extract to install the contribution:

    extract maclib/setdof

##set_vt
>Changes the temperature in a "safe" manner

---
To install the contribution, checkout the tag set_vt-v1.0:

    git checkout set_vt-v1.0

then read set_vt.README

Usually use extract to install the contribution:

    extract maclib/set_vt

##stack3d
>displays up to 64 3d planes at once

---
To install the contribution, checkout the tag stack3d-v1.0:

    git checkout stack3d-v1.0

then read stack3d.README

Usually use extract to install the contribution:

    extract maclib/stack3d

##stack4
>displays 3d planes 4 at a time with 3rd dimension labeled

---
To install the contribution, checkout the tag stack4-v1.0:

    git checkout stack4-v1.0

then read stack4.README

Usually use extract to install the contribution:

    extract maclib/stack4

##svspec
>Saves spectra into files.

---
To install the contribution, checkout the tag svspec-v1.0:

    git checkout svspec-v1.0

then read svspec.README

Usually use extract to install the contribution:

    extract maclib/svspec

##useroperator
>Examples for "useroperatorlogin" and "useroperatorlogout" macros. These
(optional) macros will be called by the "dousermacro" command in
"operatorlogin" and "operatorlogout", respectively. They are intended
as examples of how a user macro might be used to customize a local
installation - there are no manual files, a guide for customization
is given via comments in these macros. Acknowledgement: These macros
were proposed by Scott Burt, Brigham Young University, Provo, UT

---
To install the contribution, checkout the tag useroperator-v1.0:

    git checkout useroperator-v1.0

then read useroperator.README

Usually use extract to install the contribution:

    extract maclib/useroperator

##wndwfunc
>window function setup macros

---
To install the contribution, checkout the tag wndwfunc-v1.0:

    git checkout wndwfunc-v1.0

then read wndwfunc.README

Usually use extract to install the contribution:

    extract maclib/wndwfunc

##writespec
>Writes a spectrum in ASCII format into a file

---
To install the contribution, checkout the tag writespec-v1.0:

    git checkout writespec-v1.0

then read writespec.README

Usually use extract to install the contribution:

    extract maclib/writespec

##writetrace
>Creates an ASCII file from a 1D spectral trace (f1 or f2 traces from
phasefile). A second macro, "writexy", does the same, except that
it creates a file with x,y output. A new utility, "import1Dspec"
reads 1D ASCII spectra such as from "writetrace" or "writexy" (i.e.,
Y .. Y or X,Y .. X,Y data) into the current experiment in VnmrJ /
VNMR. NOTE: ALL features of this contribution are also found in
"bin/harhandler" - if the latter is installed you do NOT need to
install "maclib/writetrace" as well.

---
To install the contribution, checkout the tag writetrace-v1.0:

    git checkout writetrace-v1.0

then read writetrace.README

Usually use extract to install the contribution:

    extract maclib/writetrace

##xarray
>Analogon to the "array" macro, but for entering exponential parameter
arrays. Similar to "array" - now a standard VNMR / VnmrJ macro),
"xarray" can be called without argument or by just giving a
parameter name as single argument, invoking an interactive mode;
typically, however, the macro will be used with four arguments:
xarray<('parametername'<,#steps,start,finalvalue>)> Note that
unlike with "array", the last argument is NOT a stepsize (or rather
multiplier), but the size of the last array element; the multiplier
will be calculated by "xarray". Example: xarray('nt',10,2,1024) results
in nt=2,4,8,16,32,64,128,256,512,1024 and xarray('d2',8,0.1,10) defines
an array d2=.1,.19307,.372759,.719686,1.3895,2.6827,5.17947,10 This
macro has been recovered from an earlier package contribution by the
author, "packages.51/extend".

---
To install the contribution, checkout the tag xarray-v1.0:

    git checkout xarray-v1.0

then read xarray.README

Usually use extract to install the contribution:

    extract maclib/xarray

##XT1
>XT1 produces a series of displays (w/ optional plots) of exponential
decays for crosspeak intensities from a series of hsqcT1 experiments,
including F1,F2 values and relaxation times for each crosspeak. Usage:
XT1<any arg if plots desired>

---
To install the contribution, checkout the tag XT1-v1.0:

    git checkout XT1-v1.0

then read XT1.README

Usually use extract to install the contribution:

    extract maclib/XT1

##zoomplot2d
>Create a full size plot of a COSY-type 2D spectrum where the noise is
left out, and the areas which can have signals are blown up (zoomed)
accordingly.

---
To install the contribution, checkout the tag zoomplot2d-v1.0:

    git checkout zoomplot2d-v1.0

then read zoomplot2d.README

Usually use extract to install the contribution:

    extract maclib/zoomplot2d

