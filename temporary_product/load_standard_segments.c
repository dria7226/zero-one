FILE* file;
struct stat status;
int success;

//load ide segment
uint8_t* ide_segment;
#include "load_ide.c"
//replace system calls
replace_system_calls_in_segment(ide_segment,status.st_size);

//load main segment
uint8_t* main_segment;
#include "load_main.c"
//replace system calls
replace_system_calls_in_segment(main_segment,status.st_size);
