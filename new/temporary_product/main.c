/********************
   Includes
 ********************/
#ifdef _WIN32
	#include "win/includes.c"
#else

#endif

#include "common/includes.c"

#include "common/variables.c"

/********************
   Main
 ********************/
#define TESTING
 
#ifndef TESTING
	#ifdef _WIN32
	   #include "win/main.c"
	#else
	
	#endif
#else
	#include "test_main.c"
#endif
