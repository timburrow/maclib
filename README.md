# xarray\n
 xarray - Analogon to the "array" macro, but for entering exponential
 parameter
 arrays. Similar to "array" - now a standard VNMR / VnmrJ macro),
 "xarray" can be called without argument or by just giving a
 parameter name as single argument, invoking an interactive mode;
 typically, however, the macro will be used with four arguments:
 xarray<('parametername'<,#steps,start,finalvalue>)> Note that
 unlike with "array", the last argument is NOT a stepsize (or rather
 multiplier), but the size of the last array element; the multiplier
 will be calculated by "xarray". Example: xarray('nt',10,2,1024) results
 in nt=2,4,8,16,32,64,128,256,512,1024 and xarray('d2',8,0.1,10) defines
 an array d2=.1,.19307,.372759,.719686,1.3895,2.6827,5.17947,10 This
 macro has been recovered from an earlier package contribution by the
 author, "packages.51/extend".

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
Date submitted: 2011-03-12 - original submission

File name:      xarray
Directory:      maclib
Description:    Analogon to the "array" macro, but for entering exponential
		parameter arrays. Similar to "array" - now a standard VNMR /
		VnmrJ macro), "xarray" can be called without argument or by
		just giving a parameter name as single argument, invoking an
		interactive mode; typically, however, the macro will be used
		with four arguments:
			xarray<('parametername'<,#steps,start,finalvalue>)>
		Note that unlike with "array", the last argument is NOT a
		stepsize (or rather multiplier), but the size of the last
		array element; the multiplier will be calculated by "xarray".
		Example:
			xarray('nt',10,2,1024)
		results in
			nt=2,4,8,16,32,64,128,256,512,1024
		and
			xarray('d2',8,0.1,10)
		defines an array
			d2=.1,.19307,.372759,.719686,1.3895,2.6827,5.17947,10
		This macro has been recovered from an earlier package
		contribution by the author, "packages.51/extend".

Related files:  manual/xarray

Existing VnmrJ / VNMR files which are superseded or
otherwise affected by this submission:  none
Hardware configuration limitations:     n.a.
Known software version compatibility:   VNMR 5.1 -  VnmrJ 3.1
Known OS version compatibility:         n.a.

**This software has not been tested on OpenVnmrJ. Use at your own risk.**

To install this user contribution:  
Download the repository from GitHub and checkout the tag of the contribution you want.
Typically tags end in the version (e.g. -v1.0)

     git clone https://github.com/OpenVnmrJ/maclib  
     cd maclib  
     git checkout xarray-v1.0


You may also make a new branch and cherry-pick the multiple tags:  

     git checkout -b mybranch
     git cherry-pick  xarray-v1.0

then read xarray.README   

In most cases, use extract to install the contribution:  

    extract maclib/xarray