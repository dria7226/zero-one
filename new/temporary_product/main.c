/********************
   Includes
 ********************/
// #ifdef _WIN32
// 	#include "win/includes.c"
// #else
//
// #endif

#include "common/includes.c"

// #include "common/variables.c"

/********************
   Main
 ********************/
#ifndef TESTING
	#ifdef _WIN32
	   #include "win/main.c"
	#endif
#else
	#include "common/test_main.c"
#endif
// #include "common/test_main.c"
