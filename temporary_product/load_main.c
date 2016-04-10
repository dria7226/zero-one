char* main_file = "./main.segment";

success = stat(main_file, &status);

if(success != -1 && status.st_size > 1)
{
    file = fopen(main_file, "r");

    char machine_language = fgetc(main_file);

#ifdef _WIN32
    main_segment = (uint8_t*) VirtualAllocEx(GetCurrentProcess(), 0, status.st_size-1,
    MEM_COMMIT, PAGE_EXECUTE_READWRITE);
#else

#endif

    fgets(main_segment, status.st_size, main_file);

    fclose(main_file);
}