# csll\n
 csll - Produces a line list in a form compatible with CSEARCH from Sadtler
 (allegedly), using DEPT and 1D spectra.

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
Date submitted:         1995-04-07
                        1995-10-18 r.kyburz, fixed bug

File name:              csll
Directory:              maclib
Description:            Produces a line list in a form compatible with CSEARCH
                        from Sadtler (allegedly), using DEPT and 1D spectra.

Related files:          maclib/csll, manual/csll

Existing VnmrJ / VNMR files which are superseded or
otherwise affected by this submission:  Previous version of csll
Hardware configuration limitations:     
Known software version compatibility:

**This software has not been tested on OpenVnmrJ. Use at your own risk.**

To install this user contribution:  
Download the repository from GitHub and checkout the tag of the contribution you want.
Typically tags end in the version (e.g. -v1.0)

     git clone https://github.com/OpenVnmrJ/maclib  
     cd maclib  
     git checkout csll-v1.0


You may also make a new branch and cherry-pick the multiple tags:  

     git checkout -b mybranch
     git cherry-pick  csll-v1.0

then read csll.README   

In most cases, use extract to install the contribution:  

    extract maclib/csll