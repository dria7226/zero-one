FILE* file;
struct stat status;
int success;

//load ide segment
uint8_t* ide_segment;
#include "load_ide.c"

//load main segment
uint8_t* main_segment;
#include "load_main.c"

//replace "system call" placeholders with actual addresses
#include "temporary_system_call_replacement.c"