# bcdc\n
 bcdc - "bcdc" uses the "bc" command in a way that prevents flattening
 broad signals that "region" failed to integrate: "bcdc" does an
 individual, linear correction on every baseline (= not integrated)
 region. Useful for automatic integration in automation, especially
 if samples contain broad signals from exchangeable protons. "bcdc"
 was written in cooperation with / based on suggestions by Cornelius
 de Korte, Solvay Pharmaceuticals, Weesp NL.

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

File name:      bcdc.tar.Z
Directory:      maclib
Description:    "bcdc" uses the "bc" command in a way that prevents flattening
                broad signals that "region" failed to integrate: "bcdc" does
                an individual, linear correction on every baseline (= not
                integrated) region. Useful for automatic integration in
                automation, especially if samples contain broad signals from
                exchangeable protons.
                "bcdc" was written in cooperation with / based on suggestions
                by Cornelius de Korte, Solvay Pharmaceuticals, Weesp NL.

Related files:  maclib/bcdc     manual/bcdc

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
     git checkout bcdc-v1.0


You may also make a new branch and cherry-pick the multiple tags:  

     git checkout -b mybranch
     git cherry-pick  bcdc-v1.0

then read bcdc.README   

In most cases, use extract to install the contribution:  

    extract maclib/bcdc