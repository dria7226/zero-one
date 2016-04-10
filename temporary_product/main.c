/********************
   Includes
 ********************/
#ifdef _WIN32
	#include "win/includes.c"
#else

#endif

#include "common/includes.c"

// #include "common/variables.c"

/********************
   Main
 ********************/
#ifdef _WIN32
int WINAPI WinMain (HINSTANCE hInstance,
						  HINSTANCE hPrevInstance,
						  LPSTR lpCmdLine,
						  int iCmdShow)
#else
int main (int argc, char* argv)
#endif
{
	#ifndef TESTING
		#ifdef _WIN32
		   #include "win/main.c"
		#endif
	#else
		#include "common/test_main.c"
	#endif

	return 0;
}
