# batchprocess\n
 batchprocess -

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

Your name:	Dave Russell, Agilent Technologies
Date submitted:	20011-01-11

File name:	batchprocess
Directory:	maclib
Description:	Automatic processing macro to integrate specific peaks
		("/vnmr/fidlib/Clindamycin/Clindamycin_PROTON_01.fid") in this
		case), calculate concentration, and write the results into a
		CSV file. Instruction in header.
		Acknowledgement: The "batchprocess" macro was written by Krish
		Krishnamurthy, Agilent.

Related files:	batchprocess.pdf	maclib/qEst2csv
		manual/batchprocess	manual/qEst2csv

Existing VnmrJ / VNMR files which are superseded or
otherwise affected by this submission:	none
Hardware configuration limitations:	n.a.  
Known software version compatibility:	VnmrJ 3.x or Chempack 4.1

**This software has not been tested on OpenVnmrJ. Use at your own risk.**

To install this user contribution:  
Download the repository from GitHub and checkout the tag of the contribution you want.
Typically tags end in the version (e.g. -v1.0)

     git clone https://github.com/OpenVnmrJ/maclib  
     cd maclib  
     git checkout batchprocess-v1.0


You may also make a new branch and cherry-pick the multiple tags:  

     git checkout -b mybranch
     git cherry-pick  batchprocess-v1.0

then read batchprocess.README   

In most cases, use extract to install the contribution:  

    extract maclib/batchprocess