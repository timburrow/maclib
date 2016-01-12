# lsbru\n
 lsbru - Sets "lp" for data from Bruker "D" series spectrometers
 (DPX/DRX/DMX,
 Avance), based on the "decim" and "dspfvs" parameters ("lp" can
 be 25000 degrees and more with such non-time corrected, digitally
 filtered FIDs).

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
Date submitted: 1995-10-26
                2002-03-07 - enhanced / updated: now sets "lp", not "lsfid"
                2006-04-10 - expansions for TopSpin 1.3 data

File name:      lsbru
Directory:      maclib
Description:    Sets "lp" for data from Bruker "D" series spectrometers
                (DPX/DRX/DMX, Avance), based on the "decim" and "dspfvs"
                parameters ("lp" can be 25000 degrees and more with such
                non-time corrected, digitally filtered FIDs).

Related files:  manual/lsbru

Existing VnmrJ / VNMR files which are superseded or
otherwise affected by this submission:  none
Hardware configuration limitations:     n.a.
Known software version compatibility:   VNMR 6.1C, VnmrJ
Known OS version compatibility:         n.a.

**This software has not been tested on OpenVnmrJ. Use at your own risk.**

To install this user contribution:  
Download the repository from GitHub and checkout the tag of the contribution you want.
Typically tags end in the version (e.g. -v1.0)

     git clone https://github.com/OpenVnmrJ/maclib  
     cd maclib  
     git checkout lsbru-v1.0


You may also make a new branch and cherry-pick the multiple tags:  

     git checkout -b mybranch
     git cherry-pick  lsbru-v1.0

then read lsbru.README   

In most cases, use extract to install the contribution:  

    extract maclib/lsbru