char* ide_file = "./ide.segment";

success = stat(ide_file, &status);

if(success != -1 && status.st_size > 1)
{
    file = fopen(ide_file, "r");

    char machine_language = fgetc(ide_file);

#ifdef _WIN32
    ide_segment = (uint8_t*) VirtualAllocEx(GetCurrentProcess(), 0, status.st_size-1,
    MEM_COMMIT, PAGE_EXECUTE_READWRITE);
#else

#endif

    fgets(ide_segment, status.st_size, ide_file);

    fclose(ide_file);
}