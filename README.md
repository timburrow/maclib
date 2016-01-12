# pl2d\n
 pl2d - enhanced plcosy and plhxcor macros (broken out from
 packages.extend);
 the enhancements include: - added test for running acquisition (to
 avoid data corruption, see buglist) - avoids overlap of 1D traces
 with parameters - bugs in 1D scaling fixed - plot area now properly
 optimized, in particular if no 1D traces are plotted - compatible
 with other parameter styles (bpa, pap) - 1D experiments do not have
 to be specified upon first call if they are in default numbers (1H:
 exp1, 13C: exp2), as described in the manual. - upscaling of 1D traces
 through an optional argument.

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
Date submitted: 1995-12-06
                1996-04-26 (fixed for automation mode)
                1998-07-10 (fixed acquisition check for newer releases)
                1999-01-27 (fixed acquisition check for datastations)
                1999-02-08 (fixed for 1D spectra acquired at different
                            frequency, uses parstyle)
                1999-09-27 (fixed bugs in plhxcor)
                2001-05-31 (added optional upscaling of 1D traces)

File name:      pl2d
Directory:      maclib
Description:    enhanced plcosy and plhxcor macros (broken out from
                packages.extend); the enhancements include:
                 - added test for running acquisition (to avoid data
                        corruption, see buglist)
                 - avoids overlap of 1D traces with parameters
                 - bugs in 1D scaling fixed
                 - plot area now properly optimized, in particular if no 1D
                        traces are plotted
                 - compatible with other parameter styles (bpa, pap)
                 - 1D experiments do not have to be specified upon first call
                        if they are in default numbers (1H: exp1, 13C: exp2),
                        as described in the manual.
                 - upscaling of 1D traces through an optional argument.

Related files:  maclib/plcosy   maclib/plhxcor   manual/plcosy   manual/plhxcor

Existing VnmrJ / VNMR files which are superseded or
otherwise affected by this submission:  none
Hardware configuration limitations:     n.a.
Known software version compatibility:   6.1B and later
Known OS version compatibility:         n.a.

**This software has not been tested on OpenVnmrJ. Use at your own risk.**

To install this user contribution:  
Download the repository from GitHub and checkout the tag of the contribution you want.
Typically tags end in the version (e.g. -v1.0)

     git clone https://github.com/OpenVnmrJ/maclib  
     cd maclib  
     git checkout pl2d-v1.0


You may also make a new branch and cherry-pick the multiple tags:  

     git checkout -b mybranch
     git cherry-pick  pl2d-v1.0

then read pl2d.README   

In most cases, use extract to install the contribution:  

    extract maclib/pl2d