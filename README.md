# dlli\n
 dlli - Creates (and displays) a line listing with integrals for each
 individual line found. Used also for exporting line listings into
 the SpecInfo spectral database software. For performing a baseline
 correction prior to calling "dlli" or "nlli" we recommend using
 "maclib/bcdc".

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
Date submitted: 1997-03-15
                1999-11-22 updated for VNRM 6.1: uses reffrq for ppm units,
                           if found and non-zero.

File name:      dlli
Directory:      maclib
Description:    Creates (and displays) a line listing with integrals for each
                individual line found. Used also for exporting line listings
                into the SpecInfo spectral database software.
                For performing a baseline correction prior to calling "dlli"
                or "nlli" we recommend using "maclib/bcdc".

Related files:  maclib/nlli     manual/dlli     manual/nlli

Existing VnmrJ / VNMR files which are superseded or
otherwise affected by this submission:  none
Hardware configuration limitations:     n.a.
Known software version compatibility:   5.1 - 6.1B
Known OS version compatibility:         n.a.

**This software has not been tested on OpenVnmrJ. Use at your own risk.**

To install this user contribution:  
Download the repository from GitHub and checkout the tag of the contribution you want.
Typically tags end in the version (e.g. -v1.0)

     git clone https://github.com/OpenVnmrJ/maclib  
     cd maclib  
     git checkout dlli-v1.0


You may also make a new branch and cherry-pick the multiple tags:  

     git checkout -b mybranch
     git cherry-pick  dlli-v1.0

then read dlli.README   

In most cases, use extract to install the contribution:  

    extract maclib/dlli