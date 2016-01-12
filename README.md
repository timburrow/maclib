# set_vt\n
 set_vt - Changes the temperature in a "safe" manner

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
Date submitted:         1995-03-10

File name:              set_vt
Directory:              maclib
Description:            Changes the temperature in a "safe" manner

Related files:          manual

Existing VnmrJ / VNMR files which are superseded or
otherwise affected by this submission:  None
Hardware configuration limitations:     None
Known software version compatibility:   Any

**This software has not been tested on OpenVnmrJ. Use at your own risk.**

To install this user contribution:  
Download the repository from GitHub and checkout the tag of the contribution you want.
Typically tags end in the version (e.g. -v1.0)

     git clone https://github.com/OpenVnmrJ/maclib  
     cd maclib  
     git checkout set_vt-v1.0


You may also make a new branch and cherry-pick the multiple tags:  

     git checkout -b mybranch
     git cherry-pick  set_vt-v1.0

then read set_vt.README   

In most cases, use extract to install the contribution:  

    extract maclib/set_vt