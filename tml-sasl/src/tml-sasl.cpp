/* 
 *  libTML:  A BEEP based Messaging Suite
 *  Copyright (C) 2015 wobe-systems GmbH
 *
 *  This program is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public License
 *  as published by the Free Software Foundation; either version 2.1
 *  of the License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this program; if not, write to the Free
 *  Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
 *  02111-1307 USA
 *  
 *  You may find a copy of the license under this software is released
 *  at COPYING file. This is LGPL software: you are welcome to develop
 *  proprietary applications using this library without any royalty or
 *  fee but returning back any change, improvement or addition in the
 *  form of source code, project image, documentation patches, etc.
 *
 *  Homepage:
 *    http://www.libtml.org
 *
 *  For professional support contact us:
 *
 *    wobe-systems GmbH
 *    support@libtml.org
 *
 * Contributors:
 *    wobe-systems GmbH
 */

/** @file tmlCore.cpp
  * 
  * @brief Definitions and dll import file for the TMLCore Object API
  *
  * To use the TMLCore interface library add the tmlCore.h, tmlGlobalDefines.h, tmlErrors.h and tmlCore.lib into your project and take
  * care to have the libvortex-1.1.dll, libaxl.dll and the tmlCore.dll in your path.
  */

#include "tml-sasl.h"
#ifdef LINUX
#else // LINUX
#include "windows.h"
#endif // LINUX

/**
 * @brief    Returns library version.
 */
SASL_CORE_API void DLL_CALL_CONV tml_sasl_Get_Version(int* iVersion){
  *iVersion = 4711;
};

#ifdef LINUX
void __attribute__ ((constructor)) my_load(void);
void __attribute__ ((destructor)) my_unload(void);

// Called when the library is loaded and before dlopen() returns
void my_load(void)
{
    // BEIM LADEN DER DLL:
    // Add initialization code
}

// Called when the library is unloaded and before dlclose()
// returns
void my_unload(void)
{
    // BEIM FREIGEBEN DER DLL:
    // Add clean-up code
}
#else
BOOL WINAPI DllMain(
    HINSTANCE hinstDLL,  // handle to DLL module
    DWORD fdwReason,     // reason for calling function
    LPVOID lpReserved )  // reserved
{

    // Perform actions based on the reason for calling.
    switch( fdwReason ) 
    { 
        case DLL_PROCESS_ATTACH:
         break;

        case DLL_THREAD_ATTACH:
         break;

        case DLL_THREAD_DETACH:
         break;

        case DLL_PROCESS_DETACH:
         break;
    }
    return TRUE;  // Successful DLL_PROCESS_ATTACH.
}
#endif
