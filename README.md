# piv\n
 piv - "piv" acts the same way as "pir", except that it avoids label
 overlap by writing numbers vertically and offset horizontally if
 necessary. Related functions "pivn" and "dpiv"/"dpivn" are also
 provided. This contribution is included with standard VnmrJ 2.2C/D
 software and with Chempack 4.1 ("chempack/CP4").

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
Date submitted: 2000-09-08
                2000-09-11 - Adjusted for new integration in VNMR 5.3 & higher
                2000-09-19 - Added missing macro "plotinfo"
                2002-12-17 - Adjusted for VnmrJ
                2008-04-20 - Adjusted to comply with VnmrJ 2.2C
                2008-09-22 - Adjusted color selection to follow VnmrJ 2.2C/D

File name:      piv.tar.Z
Directory:      maclib
Description:    "piv" acts the same way as "pir", except that it avoids label
                overlap by writing numbers vertically and offset horizontally
                if necessary. Related functions "pivn" and "dpiv"/"dpivn" are
                also provided.
                This contribution is included with standard VnmrJ 2.2C/D
                software and with Chempack 4.1 ("chempack/CP4").

Related files:  maclib/dpiv     maclib/dpivn    maclib/piv      maclib/pivn
                manual/dpiv     manual/dpivn    manual/piv      manual/pivn
                maclib/plotinfo

Existing VnmrJ / VNMR files which are superseded or
otherwise affected by this submission:  none
Hardware configuration limitations:     n.a.
Known software version compatibility:   VNMR 4.1 - 6.1, VnmrJ 1.1B - 2.2D
Known OS version compatibility:         n.a.

**This software has not been tested on OpenVnmrJ. Use at your own risk.**

To install this user contribution:  
Download the repository from GitHub and checkout the tag of the contribution you want.
Typically tags end in the version (e.g. -v1.0)

     git clone https://github.com/OpenVnmrJ/maclib  
     cd maclib  
     git checkout piv-v1.0


You may also make a new branch and cherry-pick the multiple tags:  

     git checkout -b mybranch
     git cherry-pick  piv-v1.0

then read piv.README   

In most cases, use extract to install the contribution:  

    extract maclib/piv