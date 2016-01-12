# wndwfunc\n
 wndwfunc - window function setup macros

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

Submitter:      Krish Krishnamurthy, Agilent
Date submitted: 1996-10-25
                1996-12-02 (added missing macro "gaussian")

File name:      wndwfunc
Directory:      maclib
Description:    window function setup macros

Related files:  maclib/gaussian   manual/gaussian
                maclib/pi3ssbsq   manual/pi3ssbsq
                maclib/pi4ssbsq   manual/pi4ssbsq
                maclib/sqcosine   manual/sqcosine
                maclib/sqsinebell manual/sqsinebell

Existing VnmrJ / VNMR files which are superseded or
otherwise affected by this submission:  none
Hardware configuration limitations:     
Known software version compatibility:   VNMR 3.2 and later
Known OS version compatibility:         n.a.

**This software has not been tested on OpenVnmrJ. Use at your own risk.**

To install this user contribution:  
Download the repository from GitHub and checkout the tag of the contribution you want.
Typically tags end in the version (e.g. -v1.0)

     git clone https://github.com/OpenVnmrJ/maclib  
     cd maclib  
     git checkout wndwfunc-v1.0


You may also make a new branch and cherry-pick the multiple tags:  

     git checkout -b mybranch
     git cherry-pick  wndwfunc-v1.0

then read wndwfunc.README   

In most cases, use extract to install the contribution:  

    extract maclib/wndwfunc