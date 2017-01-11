#ifdef __WIN32
  #include <windows.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "mman_abstract.c"

// SetConsoleTextAttribute( GetStdHandle( STD_INPUT_HANDLE ), 0x5B ); http://www.cplusplus.com/forum/beginner/5830/
#define ANSI_COLOR_RED      "\x1b[41m"
#define ANSI_COLOR_GREEN    "\x1b[32m"
#define ANSI_COLOR_BLUE     "\x1b[36m"
#define ANSI_COLOR_RESET    "\x1b[0m"

int main(int argc, char** argv)
{
  #include "check_target.c"

  #include "load_target.c"

  #include "run_target.c"
}
