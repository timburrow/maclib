# acq3dpl\n
 acq3dpl - acquires 3D spectra as a series of f1f3 planes (no 3D processing
 with
 VnmrJ / VNMR, but gives faster access to the first 3D plane).

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
Date submitted: 1994-09-19
                2005-12-02 - now ready to use experiments up to 9999;
                             better FID file naming (numeric sorting)

File name:      acq3dpl
Directory:      maclib
Description:    acquires 3D spectra as a series of f1f3 planes
                (no 3D processing with VnmrJ / VNMR, but gives faster access
                to the first 3D plane).

Related files:  maclib/continue3d       manual/acq3dpl  manual/continue3d

Existing VnmrJ / VNMR files which are superseded or
otherwise affected by this submission:  none
Hardware configuration limitations:     n.a.
Known software version compatibility:   VNMR 6.1 - VnmrJ 2.1 (untested)
Known OS version compatibility:         n.a.

**This software has not been tested on OpenVnmrJ. Use at your own risk.**

To install this user contribution:  
Download the repository from GitHub and checkout the tag of the contribution you want.
Typically tags end in the version (e.g. -v1.0)

     git clone https://github.com/OpenVnmrJ/maclib  
     cd maclib  
     git checkout acq3dpl-v1.0


You may also make a new branch and cherry-pick the multiple tags:  

     git checkout -b mybranch
     git cherry-pick  acq3dpl-v1.0

then read acq3dpl.README   

In most cases, use extract to install the contribution:  

    extract maclib/acq3dpl