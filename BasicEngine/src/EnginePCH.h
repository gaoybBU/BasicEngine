#pragma once

// Precompiled Header File

// C++ Standard Library Headers

// General
#include<iostream>     // defines objects like cin, cout, cerr, etc. that correspond to the standard input/output streams
#include<stdexcept>    // defines a set of standard exceptions that both the library and the user can throw and catch
#include<string>       // introduces string types
#include<optional>     // defines a template class to represent optional objects

// Container Library
#include<array>        // defines the array container type
#include<vector>       // defines the vector container type
#include<set>          // defines the set and multiset container types

// Algorithm Library
#include<algorithm>    // defines a collection of functions especially designed to be used on ranges of elements

// Utilities Library
#include<limits>       // defines elements with the characteristics of arithmetic types
#include<functional>

// C Standard Library Headers
#include<cstdlib>     // general purpose functions, including dynamic memory management, random numbers, etc
#include<cstdint>     // introduces set of typedefs that specify exact-width integer types



#ifdef ENG_PLATFORM_WINDOWS
    #include <Windows.h>
#endif