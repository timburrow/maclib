# writetrace\n
 writetrace - Creates an ASCII file from a 1D spectral trace (f1 or f2
 traces from
 phasefile). A second macro, "writexy", does the same, except that
 it creates a file with x,y output. A new utility, "import1Dspec"
 reads 1D ASCII spectra such as from "writetrace" or "writexy" (i.e.,
 Y .. Y or X,Y .. X,Y data) into the current experiment in VnmrJ /
 VNMR. NOTE: ALL features of this contribution are also found in
 "bin/harhandler" - if the latter is installed you do NOT need to
 install "maclib/writetrace" as well.

 Copyright 2016 University of Oregon

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

   http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.

                                SUBMISSION FORM

Submitter:      Rolf Kyburz, Agilent Technologies
Date submitted: 1993-08-19
                1995-06-24 Made work for 1D and arrayed 1D spectra
                1996-05-14 added writexy facility
                1996-06-29 added Solaris 2.x compatibility, fixed bugs in
                              connection with large 2D spectra
                1997-09-22 added IRIX compatibility
                1999-08-10 change default trace to current one
                2000-11-06 fixed bug with writexy and trace='f1'
                2001-01-18 fixed writexy bugs with 1D & Bruker data
                2002-05-16 adjustments for JCAMP-DX export software
                2004-10-28 more precision in numeric ASCII output
                2004-10-29 added "import1Dspec" for 1D ASCII spectra
                2004-11-12 fixed bugs in "import1Dspec" utility
                2006-02-19 "writetrace" / "writexy" Linux-compatible
                2006-02-20 "import1Dspec" now also Linux-compatible
                2006-02-22 Fixed bug in "writetrace" utility
                2006-02-24 Fixed compiler issues under MacOS X & Linux
                2007-03-15 Adjusted for Chempack / VnmrJ 2.2C compatibility;
                           fixed byte swapping for Intel-based Macs (courtesy
                           Pascal Mercier, Chenomx)
                2007-03-20 Fixed bugs in C architecture determination
                2007-05-12 Fixed bug in "writetrace" / "writexy" macros
                2008-03-20 Install script, "head" call adjusted for RHEL 5.1
                2008-07-08 C modules updated to current version
                2010-05-31 Minor enhancement in "writetrace" debugging output
		2011-02-08 Added option for X column in ppm in "writexy"

File name:      writetrace
Directory:      maclib
Description:    Creates an ASCII file from a 1D spectral trace (f1 or f2 traces
                from phasefile). A second macro, "writexy", does the same,
                except that it creates a file with x,y output.
                A new utility, "import1Dspec" reads 1D ASCII spectra such as
                from "writetrace" or "writexy" (i.e., Y .. Y or X,Y .. X,Y
                data) into the current experiment in VnmrJ / VNMR.
                NOTE: ALL features of this contribution are also found in
                      "bin/harhandler" - if the latter is installed you do NOT
                      need to install "maclib/writetrace" as well.


Related files:  bin/import1Dspec    bin/writetrace    maclib/getbinpath
                maclib/import1Dspec maclib/writexy    maclib/writejxy
                manual/import1Dspec manual/writetrace manual/writexy
                manual/writejxy     source/import1Dspec.c  source/writetrace.c

Existing VnmrJ / VNMR files which are superseded or
otherwise affected by this submission:  none
Hardware configuration limitations:     n.a.
Known software version compatibility:   VNMR 6.1 - VnmrJ 2.2C
Known OS version compatibility:         Solaris 2.x - 9, RHEL 4, MacOS X 10.4
Special instructions for installation:
    If you are downloading from the Internet, store
    the file writetrace.tar.Z in /vnmr/userlib/maclib, then use
        cd /vnmr/userlib

**This software has not been tested on OpenVnmrJ. Use at your own risk.**

To install this user contribution:  
Download the repository from GitHub and checkout the tag of the contribution you want.
Typically tags end in the version (e.g. -v1.0)

     git clone https://github.com/OpenVnmrJ/maclib  
     cd maclib  
     git checkout writetrace-v1.0


You may also make a new branch and cherry-pick the multiple tags:  

     git checkout -b mybranch
     git cherry-pick  writetrace-v1.0

then read writetrace.README   

In most cases, use extract to install the contribution:  

    extract maclib/writetrace