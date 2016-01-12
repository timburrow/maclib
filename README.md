# mds\n
 mds - Macros that simultaneously display or plot 1D segments in positions
 that were previously defined and saved with "s1", "s2", "s3", etc.

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
Date submitted: 2005-11-07 - Re-submitted, from "packages.61/tools"

File name:      mds
Directory:      maclib
Description:    Macros that simultaneously display or plot 1D segments in
                positions that were previously defined and saved with "s1",
                "s2", "s3", etc.

Related files:  maclib/mpl      manual/mds      manual/mpl

Existing VnmrJ / VNMR files which are superseded or
otherwise affected by this submission:  none
Hardware configuration limitations:     n.a.
Known software version compatibility:   VNMR 5.1 - VnmrJ 2.1A

**This software has not been tested on OpenVnmrJ. Use at your own risk.**

To install this user contribution:  
Download the repository from GitHub and checkout the tag of the contribution you want.
Typically tags end in the version (e.g. -v1.0)

     git clone https://github.com/OpenVnmrJ/maclib  
     cd maclib  
     git checkout mds-v1.0


You may also make a new branch and cherry-pick the multiple tags:  

     git checkout -b mybranch
     git cherry-pick  mds-v1.0

then read mds.README   

In most cases, use extract to install the contribution:  

    extract maclib/mds