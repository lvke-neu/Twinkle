#pragma once

#ifdef TWINKLE_PLATFORM_WINDOWS
	#ifdef TWINKLE_BUILD_DLL
		#define TWINKLE_API __declspec(dllexport)
	#else
		#define TWINKLE_API __declspec(dllimport)
	#endif 
#else
	#error Twinkle only support Windows!
#endif

#define BIT(X) (1 << X)