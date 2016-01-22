#include <stdio.h>

#ifdef _WIN32
	#include <windows.h>
#else
	#include <sys/mman.h>
#endif

#include "mman_abstract.c"