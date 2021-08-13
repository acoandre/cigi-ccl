function(SetCompilerString COMPILER_STR)
	if(CMAKE_COMPILER_IS_GNUCXX)
		#no decoration for linux
		SET(COMPILER_STR "" PARENT_SCOPE)
		return()
	endif()
	if(MSVC)
		if(MSVC_VERSION VERSION_GREATER_EQUAL 1930)	
			message(WARNING "Unknown MSVC compiler version, defaulting to install root")
			SET(RESULT ".")
		elseif(MSVC_VERSION VERSION_GREATER_EQUAL 1920)
			SET(RESULT "vc142")
		elseif(MSVC_VERSION VERSION_GREATER_EQUAL 1910)
			SET(RESULT "vc141")
		elseif(MSVC_VERSION VERSION_GREATER_EQUAL 1900)
			SET(RESULT "vc140")
		elseif(MSVC_VERSION VERSION_GREATER_EQUAL 1800)
			SET(RESULT "vc120")
		elseif(MSVC_VERSION VERSION_GREATER_EQUAL 1700)
			SET(RESULT "vc110")
		elseif(MSVC_VERSION VERSION_GREATER_EQUAL 1600)
			SET(RESULT "vc100")
		elseif(MSVC_VERSION VERSION_GREATER_EQUAL 1500)
			SET(RESULT "vc90")
		elseif(MSVC_VERSION VERSION_GREATER_EQUAL 1400)
			SET(RESULT "vc80")
		else()
			message(FATAL_ERROR "MSVC compiler version is too old!")
		endif()
	endif()
	if(CMAKE_SIZEOF_VOID_P EQUAL 8)
		SET(RESULT ${RESULT}-64)
	elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
		SET(RESULT ${RESULT}-32)
	endif()
		
	set(COMPILER_STR ${RESULT} PARENT_SCOPE)
	message(STATUS "Got compiler string \"${RESULT}\"")
endfunction()