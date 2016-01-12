# macrocalls\n
 macrocalls - VNMR macro debugging utilities that permit finding macro calls
 in
 the specified macro, or macros calling the specified macro. Also
 recursive searches (for macro calls in submacros, or macros calling
 a parent macro etc.) are possible. The complete VNMR macro path is
 taken into account.

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
Date submitted: 2003-02-05
                2003-02-07 - Fixed bug in tokenizer
                2004-01-14 - Fixed minor typos in manuals
                2004-06-15 - Minor fix in install script
                2004-09-14 - Suppress response from "appmode=..."
                2004-11-25 - Suppress more unwanted response
                2005-11-06 - Fixed shell script syntax issue
                2008-03-20 - Install script, "head" call changed for RHEL 5.1

File name:      macrocalls.tar.Z
Directory:      maclib
Description:    VNMR macro debugging utilities that permit finding macro calls
                in the specified macro, or macros calling the specified macro.
                Also recursive searches (for macro calls in submacros, or
                macros calling a parent macro etc.) are possible. The complete
                VNMR macro path is taken into account.

Acknowledgement: The author would like to thank Bruce Adams (Varian) for
                 initial suggestions that led to this set of utilities.

Related files:  bin/macrocalls, bin/stripcomment, manual/macrocalls,
                maclib/findsubmacros, maclib/findparentmacros,
                manual/findsubmacros, manual/findparentmacros,
                source/stripcomment.c

Existing VnmrJ / VNMR files which are superseded or
otherwise affected by this submission:  none
Hardware configuration limitations:     n.a.
Known software version compatibility:   VNMR 6.1B and higher
Known OS version compatibility:         Solaris 8, 9
Special instructions for installation:

**This software has not been tested on OpenVnmrJ. Use at your own risk.**

To install this user contribution:  
Download the repository from GitHub and checkout the tag of the contribution you want.
Typically tags end in the version (e.g. -v1.0)

     git clone https://github.com/OpenVnmrJ/maclib  
     cd maclib  
     git checkout macrocalls-v1.0


You may also make a new branch and cherry-pick the multiple tags:  

     git checkout -b mybranch
     git cherry-pick  macrocalls-v1.0

then read macrocalls.README   

In most cases, use extract to install the contribution:  

    extract maclib/macrocalls