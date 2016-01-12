# getcelem\n
 getcelem - The macro getcelem analyzes vnmrsys/exp*/acqfil/fid: it returns
 the
 number of completed FIDs (celem) and completed transients (ct) in an
 experiment, which may occasionally be set to 0 after an acquisition,
 or after stopping or aborting an experiment prematurely. "getcelem"
 sets them to their correct value.

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

Your name:              Akinori Tezuka
                        4-16-36 Shibaura
                        Minato-ku, Tokyo 108-0023
                        Japan
Date submitted:         1999-06-07

File name:              getcelem
Directory:              maclib
Description:            The macro getcelem analyzes vnmrsys/exp*/acqfil/fid:
                        it returns the number of completed FIDs (celem) and
                        completed transients (ct) in an experiment, which may
                        occasionally be set to 0 after an acquisition, or
                        after stopping or aborting an experiment prematurely.
                        "getcelem" sets them to their correct value.

Related files:          source/getcelem.c   bin/getcelem   manual/getcelem

Existing VnmrJ / VNMR files which are superseded or
otherwise affected by this submission:  none
Hardware configuration limitations:     none
Known software version compatibility:   Sun workstations
Known OS version compatibility:         none

Special instructions for installation:

**This software has not been tested on OpenVnmrJ. Use at your own risk.**

To install this user contribution:  
Download the repository from GitHub and checkout the tag of the contribution you want.
Typically tags end in the version (e.g. -v1.0)

     git clone https://github.com/OpenVnmrJ/maclib  
     cd maclib  
     git checkout getcelem-v1.0


You may also make a new branch and cherry-pick the multiple tags:  

     git checkout -b mybranch
     git cherry-pick  getcelem-v1.0

then read getcelem.README   

In most cases, use extract to install the contribution:  

    extract maclib/getcelem