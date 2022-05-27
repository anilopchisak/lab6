#pragma once

#if defined(__MINGW32__) || defined(__CYGWIN__)
#   define GLFX_APIENTRY __cdecl
#elif (_MSC_VER >= 800)
#   define GLFX_APIENTRY __cdecl
#else
#   define GLFX_APIENTRY
#endif

#ifndef GLFX_STATIC
#   ifdef GLFX_BUILD
#       ifdef _MSC_VER
#           define GLFXAPI extern __declspec(dllexport)
#       else
#           define GLFXAPI __attribute__((__visibility__("default")))
#       endif
#   else
#       ifdef _MSC_VER
#           define GLFXAPI extern __declspec(dllimport)
#       else
#           define GLFXAPI
#       endif
#   endif
#else
#   define GLFXAPI extern
#endif

extern "C" {

/**************************************************
* glfxGenEffect
* Return value: Effect id
**************************************************/
GLFXAPI int GLFX_APIENTRY glfxGenEffect();

/**************************************************
* glfxCreateEffectFromFile
* Input:
*   effect  -- GLFX effect id
*   file    -- File name
* Return value: Status
**************************************************/
GLFXAPI bool GLFX_APIENTRY glfxParseEffectFromFile( int effect, const char* file );

/**************************************************
* glfxCreateEffectFromMemory
* Input:
*   effect  -- GLFX effect id
*   src    -- Source
* Return value: Status
**************************************************/
GLFXAPI bool GLFX_APIENTRY glfxParseEffectFromMemory( int effect, const char* src );

/**************************************************
* glfxCompileProgram
* Input:
*   effect  -- GLFX effect id
*   program -- Program name
* Return value: GL program id if success, -1 otherwise
**************************************************/
GLFXAPI int GLFX_APIENTRY glfxCompileProgram(int effect, const char* program);

/**************************************************
* glfxGetProgramCount
* Return value: Number of programs
**************************************************/
GLFXAPI int GLFX_APIENTRY glfxGetProgramCount(int effect);

/**************************************************
* glfxGetProgramName
* Input:
*   effect  -- GLFX effect id
*   program -- Index of program
*   name    -- Destination address
*   bufSize -- Size of the buffer
**************************************************/
GLFXAPI void GLFX_APIENTRY glfxGetProgramName(int effect, int program, char* name, int bufSize);

/**************************************************
* glfxGenerateSampler
* Input:
*   effect  -- GLFX effect id
*   sampler -- Sampler name
* Return value: GL sampler id if success, -1 otherwise
**************************************************/
GLFXAPI int GLFX_APIENTRY glfxGenerateSampler(int effect, const char* sampler);

/**************************************************
* glfxGetEffectLog
* Input:
*   effect  -- GLFX effect id
*   log     -- Destination address
*   bufSize -- Size of the buffer
**************************************************/
GLFXAPI void GLFX_APIENTRY glfxGetEffectLog(int effect, char* log, int bufSize);


/**************************************************
* glfxDeleteEffect
* Input:
*   effect  -- GLFX effect id
**************************************************/
GLFXAPI void GLFX_APIENTRY glfxDeleteEffect(int effect);

}

#ifdef __cplusplus

/**************************************************
* glfxGetProgramName
* Input:
*   effect  -- GLFX effect id
*   program -- Index of program
**************************************************/
GLFXAPI const char* GLFX_APIENTRY glfxGetProgramName(int effect, int program);

/**************************************************
* glfxGetEffectLog
* Input:
*   effect  -- GLFX effect id
* Return value: Log string
**************************************************/
GLFXAPI const char* GLFX_APIENTRY glfxGetEffectLog(int effect);

#endif
