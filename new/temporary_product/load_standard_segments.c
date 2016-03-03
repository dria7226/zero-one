FILE* file;
struct stat status;

//load ide segment
uint8_t* ide_segment;
char* ide_file = "./ide.segment";

int success = stat(ide_file, &status);

if(success != -1 && status.st_size > 1)
{
    file = fopen(ide_file, "r");

    char machine_language = fgetc(ide_file);

    ide_segment = (uint8_t*) VirtualAllocEx(GetCurrentProcess(), 0, status.st_size-1,
    MEM_COMMIT, PAGE_EXECUTE_READWRITE);

    fgets(ide_segment, status.st_size, ide_file);

    fclose(ide_file);
}

//load main segment

//replace "system call" placeholders with actual addresses