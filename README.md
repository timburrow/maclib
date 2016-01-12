# loadbiopack\n
 loadbiopack - Install utility for BioPack; STRONGLY RECOMMENDED for a
 smooth
 installation of "psglib/BioPack" from within VNMR or VnmrJ, see below
 for instructions.

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
Date submitted: 2002-10-19
                2002-12-18 - gg: various additions & expansions
                2003-01-16 - various enhancements
                2003-02-14 - Message in case of missing BioPack files
                2003-03-09 - Improved message at end of installation
                2003-05-09 - Latest "extract" script, minor updates
                2003-11-13 - Adjusted VnmrJ online instructions
                2004-04-15 - Adjusted online instructions
                2004-06-17 - Includes current version of "extract"
                2004-06-25 - Increased text buffer in pop-up window
                2004-09-03 - Macro is now compatible with Linux;
                             added latest version of "extract" script.
                2004-10-24 - Fixed potential problem with VnmrJ LX
                2005-01-13 - Fixed Linux-related issues in "extract"
                2005-03-04 - Added latest version of "extract" script.
                2005-05-22 - Added latest version of "extract" script.
                2005-09-12 - Increased Xterm window buffer
                2005-09-23 - Fixed potential installation permission issues
                2005-09-27 - Installation to cope with altered permissions
                2006-12-21 - Secured against bad permissions in "/vnmr/bin"
                2007-05-24 - Fixed for VnmrJ SE
                2007-06-23 - Adjusted for VnmrJ 2.2C
                2007-06-25 - Corrections for VnmrJ 2.2C
                2007-12-21 - Correction of an install issue under VnmrJ 2.2C
                2008-02-14 - Added corrected version of "userlib/extract"
                2008-02-16 - Updated banner text during installation
                2008-03-22 - Updated to latest version of "userlib/extract",
                             further clarified banner text in installation
                2009-01-12 - Updated to latest version of "userlib/extract"
                2009-02-28 - Enhanced final banner text for VnmrJ 2.2C & up
                2010-03-30 - Modification to avoid hanging installations
                2011-02-18 - Includes latest version of "userlib/extract"

File name:              loadbiopack
Directory:              maclib
Description:            Install utility for BioPack; STRONGLY RECOMMENDED
                        for a smooth installation of "psglib/BioPack" from
                        within VNMR or VnmrJ, see below for instructions.

Related files:          userlib/extract

Existing VnmrJ / VNMR files which are superseded or
otherwise affected by this submission:  userlib/extract
Hardware configuration limitations:     (use for psglib/BioPack only)
Known software version compatibility:   VNMR 6.1C up to VnmrJ 2.3A
Known OS version compatibility:         Solaris 7 - 9, RHEL 4.x/5.x
Special instructions for installation and use:
        For a local installation perform the following steps:
                cd /vnmr/userlib
                ./extract maclib/loadbiopack
        Users other than "vnmr1" may need to enter the password for vnmr1, as
        "loadbiopack" installs the latest version of "/vnmr/userlib/extract".
        This is a harmless update and does not affect the use of VnmrJ / VNMR
        from any other accounts. "loadbiopack" is meant to be installed BY
        THE USER WHO WANTS TO INSTALL BIOPACK: "vnmr1" can install it in
        "/vnmr" (by adding "/vnmr" to the "extract" command line above) or in
        the local account; users other than "vnmr1" MUST do their own
        installation of "loadbiopack" (in the local account).
        The action of using "extract" to replace itself may lead to an error
        message - this can be ignored.
        "maclib/loadbiopack" must be installed prior to ANY installation of
        BioPack, and it also must be reinstalled prior to a reinstallation of
        "psglib/BioPack" - however, "loadbiopack" is NOT needed for the
        installation of BioPack updates ("psglib/BPupdate").

-------------------------------------------------------------------------------
Usage:
======
        IMPORTANT: PRIOR TO calling "loadbiopack" (see below) you MUST
        download "psglib/BioPack" from the on-line user library. The file
        "BioPack.tgz" MUST be stored in "/vnmr/userlib/psglib". If you are
        files "BioPack_dg.tgz" (mandatory), "BioPack_spincad.tgz" (not for
        VNMR 6.1B) and "BioPack_VnmrJ.tgz" (VnmrJ only) IN THE SAME DIRECTORY.

        VnmrJ 1.1B & up: Once "maclib/loadbiopack" is installed, you should
                         see a menu item "Load Biopack" in the "Utilities"
                         menu. If this is missing, exit and restart VnmrJ. To
                         install BioPack, simply select that menu item.
        VNMR 6.1C:       Once "maclib/loadbiopack" is installed, call
                         "loadbiopack" from the VNMR command line to install
                         BioPack (this also works in VnmrJ).

        For the VnmrJ / VNMR master user (vnmr1), "loadbiopack" installs
        "psglib/BioPack" in "/vnmr", for other users a local installation
        ("~/vnmrsys") is performed. Once "BioPack" is successfully installed,
        "loadbiopack" gives further instructions, by which
          - the macro "ghn_co" is called; this

**This software has not been tested on OpenVnmrJ. Use at your own risk.**

To install this user contribution:  
Download the repository from GitHub and checkout the tag of the contribution you want.
Typically tags end in the version (e.g. -v1.0)

     git clone https://github.com/OpenVnmrJ/maclib  
     cd maclib  
     git checkout loadbiopack-v1.0


You may also make a new branch and cherry-pick the multiple tags:  

     git checkout -b mybranch
     git cherry-pick  loadbiopack-v1.0

then read loadbiopack.README   

In most cases, use extract to install the contribution:  

    extract maclib/loadbiopack