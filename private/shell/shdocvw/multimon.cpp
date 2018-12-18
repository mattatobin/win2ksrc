#include "priv.h"
//=============================================================================
//
// This function defines the MULTIMON stub module that fakes multiple monitor 
// apis on pre Memphis Win32 OSes
// this is the only file that defines COMPILE_MULTIMON_STUBS 
//=============================================================================

//BUGBUG: multimon.h uses lstrcpyW so redefine lstrcpyW to StrCpyW


#ifdef StrCpyW
    #undef StrCpyW
#endif

#ifdef lstrcpy
    #undef lstrcpy
#endif

#define lstrcpy    StrCpyW


#define COMPILE_MULTIMON_STUBS
#include "multimon.h"
