#pragma once

#ifdef ENG_PLATFORM_WINDOWS
	#ifdef ENG_BUILD_DLL
		#define ENG_API __declspec(dllexport)
	#else
		#define ENG_API __declspec(dllimport) 
	#endif // ENG_BUILD_DLL
#else
	#error Only Supports Windows
#endif

#ifdef _ASSERTION
	#define ENG_ASSERT(x, ...) {if(!x) { ENG_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
	#define ENG_CORE_ASSERT(x, ...) {if(!x) { ENG_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
#else
	#define ENG_ASSERT(x, ...)
	#define ENG_CORE_ASSERT(x, ...)
#endif

#define BIT(b) (1 << b)