#include <windows.h>
#include "mman_abstract.c"
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv)
{
  char* target;

  #include "check_target.c"

  #include "load_target.c"

  #include "run_target.c"
}
