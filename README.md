# XT1\n
 XT1 - XT1 produces a series of displays (w/ optional plots) of exponential
 decays for crosspeak intensities from a series of hsqcT1 experiments,
 including F1,F2 values and relaxation times for each crosspeak. Usage:
 XT1<any arg if plots desired>

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

Submitter:      George A. Gray, Varian
Date submitted: 1993-01-11

File name:      XT1
Directory:      maclib
Description:    XT1 produces a series of displays (w/ optional plots) of
		exponential decays for crosspeak intensities from a series of
		hsqcT1 experiments, including F1,F2 values and relaxation
		times for each crosspeak. Usage:
			XT1<any arg if plots desired>

Related files:  manual/XT1, psglib/hsqcT1 (load separately)

Existing VnmrJ / VNMR files which are superseded or
otherwise affected by this submission:  none
Hardware configuration limitations:     third rf channel/wfg
Known software version compatibility:   VnmrS 4.1

**This software has not been tested on OpenVnmrJ. Use at your own risk.**

To install this user contribution:  
Download the repository from GitHub and checkout the tag of the contribution you want.
Typically tags end in the version (e.g. -v1.0)

     git clone https://github.com/OpenVnmrJ/maclib  
     cd maclib  
     git checkout XT1-v1.0


You may also make a new branch and cherry-pick the multiple tags:  

     git checkout -b mybranch
     git cherry-pick  XT1-v1.0

then read XT1.README   

In most cases, use extract to install the contribution:  

    extract maclib/XT1