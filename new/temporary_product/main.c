/********************
   Includes
 ********************/
#ifdef _WIN32
	#include "win/includes.c"
#else

#endif

<<<<<<< HEAD
// #include "common/variables.c"
=======
#include "common/includes.c"

#include "common/variables.c"
>>>>>>> 055d3d71a6ecd6abbd9364b05239a24161c5325a

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
