# calcphase\n
 calcphase - Calculate phase of spectrum based on the first complex point of
 the
 FID. This is primarily designed for cases in which the first point
 of the FID occurs exactly at time zero, i.e., an echo. In this case,
 calcphase may produces answers which are more reliable than aph
 or aph0.

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

Your name:              Steve Patt
                        For support questions please contact
                                Rolf Kyburz (rolf.kyburz@agilent.com)
Date submitted:         1992-08-24

File name:              calcphase
Directory:              maclib
Description:            Calculate phase of spectrum based on the first complex
                        point of the FID. This is primarily designed for cases
                        in which the first point of the FID occurs exactly at
                        time zero, i.e., an echo. In this case, calcphase may
                        produces answers which are more reliable than aph or
                        aph0.

Related files:

Existing VnmrJ / VNMR files which are superseded or
otherwise affected by this submission:  none
Hardware configuration limitations:     none
Known software version compatibility:   All

**This software has not been tested on OpenVnmrJ. Use at your own risk.**

To install this user contribution:  
Download the repository from GitHub and checkout the tag of the contribution you want.
Typically tags end in the version (e.g. -v1.0)

     git clone https://github.com/OpenVnmrJ/maclib  
     cd maclib  
     git checkout calcphase-v1.0


You may also make a new branch and cherry-pick the multiple tags:  

     git checkout -b mybranch
     git cherry-pick  calcphase-v1.0

then read calcphase.README   

In most cases, use extract to install the contribution:  

    extract maclib/calcphase