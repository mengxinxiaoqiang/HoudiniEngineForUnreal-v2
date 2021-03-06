/*
* Copyright (c) <2018> Side Effects Software Inc.
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*
* 1. Redistributions of source code must retain the above copyright notice,
*    this list of conditions and the following disclaimer.
*
* 2. The name of Side Effects Software may not be used to endorse or
*    promote products derived from this software without specific prior
*    written permission.
*
* THIS SOFTWARE IS PROVIDED BY SIDE EFFECTS SOFTWARE "AS IS" AND ANY EXPRESS
* OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
* OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN
* NO EVENT SHALL SIDE EFFECTS SOFTWARE BE LIABLE FOR ANY DIRECT, INDIRECT,
* INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
* LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
* OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
* LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
* NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
* EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#pragma once

#include "CoreMinimal.h"
#include "Logging/LogMacros.h"

// Define module names.
#define HOUDINI_MODULE "HoudiniEngine"
#define HOUDINI_MODULE_EDITOR "HoudiniEngineEditor"
#define HOUDINI_MODULE_RUNTIME "HoudiniEngineRuntime"

// Declare the log category depending on the module we're in
#ifdef HOUDINI_ENGINE
	#define HOUDINI_LOCTEXT_NAMESPACE HOUDINI_MODULE
	DECLARE_LOG_CATEGORY_EXTERN(LogHoudiniEngine, Log, All);
#else
	#ifdef HOUDINI_ENGINE_EDITOR
		#define HOUDINI_LOCTEXT_NAMESPACE HOUDINI_MODULE_EDITOR
		DECLARE_LOG_CATEGORY_EXTERN(LogHoudiniEngineEditor, Log, All);
	#else
		#define HOUDINI_LOCTEXT_NAMESPACE HOUDINI_MODULE_RUNTIME
		DECLARE_LOG_CATEGORY_EXTERN(LogHoudiniEngineRuntime, Log, All);
	#endif
#endif

//---------------------------------------------------------------------------------------------------------------------
// Default session settings
//---------------------------------------------------------------------------------------------------------------------

#define HAPI_UNREAL_SESSION_SERVER_AUTOSTART                true
#define HAPI_UNREAL_SESSION_SERVER_TIMEOUT                  3000.0f
#define HAPI_UNREAL_SESSION_SERVER_HOST                     TEXT( "localhost" )
#define HAPI_UNREAL_SESSION_SERVER_PORT                     9090
#if PLATFORM_MAC
	#define HAPI_UNREAL_SESSION_SERVER_PIPENAME                 TEXT( "/tmp/hapi" )
#else
	#define HAPI_UNREAL_SESSION_SERVER_PIPENAME                 TEXT( "hapi" )
#endif



// Names of HAPI libraries on different platforms.
#define HAPI_LIB_OBJECT_WINDOWS         TEXT( "libHAPIL.dll" )
#define HAPI_LIB_OBJECT_MAC             TEXT( "libHAPIL.dylib" )
#define HAPI_LIB_OBJECT_LINUX           TEXT( "libHAPIL.so" )

//---------------------------------------------------------------------------------------------------------------------
// LOG MACROS
//---------------------------------------------------------------------------------------------------------------------

// Whether to enable logging.
#define HOUDINI_ENGINE_LOGGING 1

#ifdef HOUDINI_ENGINE_LOGGING
	#ifdef HOUDINI_ENGINE
		#define HOUDINI_LOG_HELPER(VERBOSITY, HOUDINI_LOG_TEXT, ...) \
				do \
				{ \
					UE_LOG( LogHoudiniEngine, VERBOSITY, HOUDINI_LOG_TEXT, ##__VA_ARGS__ ); \
				} \
				while ( 0 )
	#else
		#ifdef HOUDINI_ENGINE_EDITOR
			#define HOUDINI_LOG_HELPER(VERBOSITY, HOUDINI_LOG_TEXT, ...) \
				do \
				{ \
					UE_LOG( LogHoudiniEngineEditor, VERBOSITY, HOUDINI_LOG_TEXT, ##__VA_ARGS__ ); \
				} \
				while ( 0 )
		#else
			#define HOUDINI_LOG_HELPER( VERBOSITY, HOUDINI_LOG_TEXT, ... ) \
				do \
				{ \
					UE_LOG( LogHoudiniEngineRuntime, VERBOSITY, HOUDINI_LOG_TEXT, ##__VA_ARGS__ ); \
				} \
				while ( 0 )
		#endif
	#endif

	#define HOUDINI_LOG_MESSAGE( HOUDINI_LOG_TEXT, ... ) \
			HOUDINI_LOG_HELPER( Log, HOUDINI_LOG_TEXT, ##__VA_ARGS__ )

	#define HOUDINI_LOG_FATAL( HOUDINI_LOG_TEXT, ... ) \
			HOUDINI_LOG_HELPER( Fatal, HOUDINI_LOG_TEXT, ##__VA_ARGS__ )

	#define HOUDINI_LOG_ERROR( HOUDINI_LOG_TEXT, ... ) \
			HOUDINI_LOG_HELPER( Error, HOUDINI_LOG_TEXT, ##__VA_ARGS__ )

	#define HOUDINI_LOG_WARNING( HOUDINI_LOG_TEXT, ... ) \
			HOUDINI_LOG_HELPER( Warning, HOUDINI_LOG_TEXT, ##__VA_ARGS__ )

	#define HOUDINI_LOG_DISPLAY( HOUDINI_LOG_TEXT, ... ) \
			HOUDINI_LOG_HELPER( Display, HOUDINI_LOG_TEXT, ##__VA_ARGS__ )
#else
	#define HOUDINI_LOG_MESSAGE( HOUDINI_LOG_TEXT, ... )
	#define HOUDINI_LOG_FATAL( HOUDINI_LOG_TEXT, ... )
	#define HOUDINI_LOG_ERROR( HOUDINI_LOG_TEXT, ... )
	#define HOUDINI_LOG_WARNING( HOUDINI_LOG_TEXT, ... )
	#define HOUDINI_LOG_DISPLAY( HOUDINI_LOG_TEXT, ... )
#endif


// HAPI_Common
enum HAPI_UNREAL_NodeType 
{
	HAPI_UNREAL_NODETYPE_ANY		=		-1,
	HAPU_UNREAL_NODETYPE_NONE		=		 0
};

enum HAPI_UNREAL_NodeFlags
{
	HAPI_UNREAL_NODEFLAGS_ANY = -1,
	HAPI_UNREAL_NODEFLAGS_NONE = 0
};

// Default cook/bake folder
#define HAPI_UNREAL_DEFAULT_BAKE_FOLDER					TEXT("/Game/HoudiniEngine/Bake");
#define HAPI_UNREAL_DEFAULT_TEMP_COOK_FOLDER			TEXT("/Game/HoudiniEngine/Temp");

// Default PDG Filters
#define HAPI_UNREAL_PDG_DEFAULT_TOP_FILTER				"HE_";
#define HAPI_UNREAL_PDG_DEFAULT_TOP_OUTPUT_FILTER		"HE_OUT_";



