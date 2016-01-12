# convolute\n
 convolute - Generates Shifted Laminar Pulses (S.L. Patt, J. Magn. Reson.,
 96, 94
 (1992)) which allow simultaneous excitation of one or more non-zero
 frequencies with any shaped excitation (including hard). convolute
 generates shapes in which all excitation frequencies have the same
 excitation phase, while convolutep allows different starting phases
 for different frequencies. addshapes adds (convolutes) two different
 waveforms together.

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
Date submitted:         1991-08-12
                        1994-06-04 p.sandor (fixed multifreq. phase relations)

File name:              convolute, convolutep, addshapes
Directory:              maclib
Description: Generates Shifted Laminar Pulses (S.L. Patt, J. Magn. Reson., 96,
  94 (1992)) which allow simultaneous excitation of one or more non-zero
  frequencies with any shaped excitation (including hard). convolute generates
  shapes in which all excitation frequencies have the same excitation phase,
  while convolutep allows different starting phases for different frequencies.
  addshapes adds (convolutes) two different waveforms together.

Related files:          manual/convolute, manual/convolutep, manual/addshapes

Existing VnmrJ / VNMR files which are superseded or
otherwise affected by this submission:  
Hardware configuration limitations:     Requires waveform generators
Known software version compatibility:

**This software has not been tested on OpenVnmrJ. Use at your own risk.**

To install this user contribution:  
Download the repository from GitHub and checkout the tag of the contribution you want.
Typically tags end in the version (e.g. -v1.0)

     git clone https://github.com/OpenVnmrJ/maclib  
     cd maclib  
     git checkout convolute-v1.0


You may also make a new branch and cherry-pick the multiple tags:  

     git checkout -b mybranch
     git cherry-pick  convolute-v1.0

then read convolute.README   

In most cases, use extract to install the contribution:  

    extract maclib/convolute