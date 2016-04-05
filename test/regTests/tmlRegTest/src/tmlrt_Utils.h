﻿/* 
 *  libTML:  A BEEP based Messaging Suite
 *  Copyright (C) 2016 wobe-systems GmbH
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
#ifndef TMLRT_UTILS_H
#define TMLRT_UTILS_H

#include <vortex.h>
#ifdef LINUX
  #include <wchar.h>
  #include <stdbool.h>
  #include <string.h>
  #include <unistd.h>
#else
  #include <stdio.h>
  #include <tchar.h>
  #include <Windows.h>     //for function sleep
#endif

#include <unicode.h>
#include <iostream>
#include <array>
using namespace std;
#include <sidex.h>
#include <tmlCore.h>

//constants for reuse
extern SIDEX_TCHAR* S_EMPTY;
extern SIDEX_TCHAR* S_UNNAMED;
extern SIDEX_TCHAR* S_START;
extern SIDEX_TCHAR* S_FINISH_SUCCESS;
extern SIDEX_TCHAR* S_FINISH_FAILED;
extern SIDEX_TCHAR* S_GROUP_TEST;
extern SIDEX_TCHAR* S_KEY_INDEX;

extern SIDEX_TCHAR* S_DOCUMENT;
extern SIDEX_TCHAR* S_wDOCUMENT;
extern SIDEX_TCHAR* S_DOCUMENT2;
extern SIDEX_TCHAR* S_GROUP;
extern SIDEX_TCHAR* S_KEY;
extern SIDEX_TCHAR* S_GROUP2;
extern SIDEX_TCHAR* S_KEY2;
extern SIDEX_TCHAR* S_GROUP3;
extern SIDEX_TCHAR* S_KEY3;
extern SIDEX_TCHAR* S_GROUP4;
extern SIDEX_TCHAR* S_KEY4;
extern SIDEX_TCHAR* S_wGROUP;
extern SIDEX_TCHAR* S_wKEY;
extern SIDEX_TCHAR* S_A_S_VAL;
extern SIDEX_TCHAR* S_B_S_VAL;
extern SIDEX_TCHAR* S_COLUMN;
extern SIDEX_TCHAR* S_COLUMN2;
extern SIDEX_TCHAR* S_MINDATE;
extern SIDEX_TCHAR* S_MAXDATE;
extern SIDEX_TCHAR* S_wDATE;
extern SIDEX_TCHAR* S_uDATE;
extern SIDEX_TCHAR* S_HANDLEKEY;
extern SIDEX_TCHAR* S_FLOATKEY;
extern SIDEX_TCHAR* S_minStr;

extern SIDEX_TCHAR* S_IO_PROFILE;
extern SIDEX_TCHAR* S_IO_PROFILE_TWO;
extern SIDEX_TCHAR* S_IO_PROFILE_THREE;
extern SIDEX_TCHAR* S_LISTENER_NETWORK_INTERFACE_IP;
extern SIDEX_TCHAR* S_IO_PORT;
extern SIDEX_TCHAR* S_IO_PORT_TWO;
extern SIDEX_TCHAR* S_IO_PORT_THREE;
extern SIDEX_TCHAR* S_IO_PORT_FOUR;
extern SIDEX_TCHAR* S_IO_PORT_FIVE;
extern SIDEX_TCHAR* S_DESTINATION_HOST_IP;

extern SIDEX_TCHAR* S_MEANING;
extern SIDEX_TCHAR* S_OF_LIFE;

extern SIDEX_TCHAR* S_DEFAULT_BOOTSTRAP;

const array<int, 5> COMMAND_CODES_LIST = {10,20,30,42,50};

//makro for creating strings in the right format
#ifdef SIDEX_UNICODE
#define tmlrtT(a) (wchar_t*) L ## a
#else // SIDEX_UNICODE
#define tmlrtT(a) (char*) a
#endif // SIDEX_UNICODE

#define CHOICE_FINISH_MESSAGE(a) a ? S_FINISH_SUCCESS : S_FINISH_FAILED

// Helper functions for strings
SIDEX_TCHAR* tmlrt_cat(SIDEX_TCHAR* first, SIDEX_TCHAR* second = NULL, SIDEX_TCHAR* third = NULL, int delStr = 0);
SIDEX_TCHAR* tmlrt_cpy(SIDEX_TCHAR* source);
int          tmlrt_cmp(SIDEX_TCHAR* first, SIDEX_TCHAR* second);
SIDEX_TCHAR* tmlrt_itoa(int value);

#define DELETE_STR(s) { if(s) { delete[](s); s = NULL; } }
#define DELETE_OBJ(o) { if(o) { delete(o);   o = NULL; } }

//cb for cmd 
void FUNC_C_DECL cbgenericCmd(TML_COMMAND_HANDLE cmdMsg, TML_POINTER data);

bool initGlobalMutex();
bool enterGlobalMutex();
void leaveGlobalMutex();
void deleteGlobalMutex();

#endif //TMLRT_UTILS_H
