# llbc\n
 llbc - "llbc" can be used to apply a "bc"  baseline correction to C13 and
 other spectra with narrow lines and possibly substantial noise, where
 "region" typically can't be used (or will fail to integrate small
 signals). "llbc" sets up integral regions based on a line listing
 (assuming threshold is pre-adjusted), then does a "bc" ("bc(1,80)")
 before restoring the original integral reset points. For integrating
 such spectra you may want to use the contribution "maclib/dlli".

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
Date submitted: 2002-06-25 - extracted from earlier "packages/extend"

File name:      llbc.tar.Z
Directory:      maclib
Description:    "llbc" can be used to apply a "bc"  baseline correction to C13
                and other spectra with narrow lines and possibly substantial
                noise, where "region" typically can't be used (or will fail
                to integrate small signals). "llbc" sets up integral regions
                based on a line listing (assuming threshold is pre-adjusted),
                then does a "bc" ("bc(1,80)") before restoring the original
                integral reset points.
                For integrating such spectra you may want to use the
                contribution "maclib/dlli".

Related files:  maclib/llbc     manual/llbc

Existing VnmrJ / VNMR files which are superseded or
otherwise affected by this submission:  none
Hardware configuration limitations:     n.a.
Known software version compatibility:   VNMR 4.1 - 6.1
Known OS version compatibility:         n.a.

**This software has not been tested on OpenVnmrJ. Use at your own risk.**

To install this user contribution:  
Download the repository from GitHub and checkout the tag of the contribution you want.
Typically tags end in the version (e.g. -v1.0)

     git clone https://github.com/OpenVnmrJ/maclib  
     cd maclib  
     git checkout llbc-v1.0


You may also make a new branch and cherry-pick the multiple tags:  

     git checkout -b mybranch
     git cherry-pick  llbc-v1.0

then read llbc.README   

In most cases, use extract to install the contribution:  

    extract maclib/llbc