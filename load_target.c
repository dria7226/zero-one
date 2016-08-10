// #define TARGET argv[1]

printf(ANSI_COLOR_GREEN "Loading target ... " ANSI_COLOR_RESET);

FILE* file = fopen(TARGET,"rb");

struct memory code;

fseek(file, 0, SEEK_END);
unsigned long length = ftell(file);
fseek(file, 0, SEEK_SET);

if(length == 0)
{
  printf("\n" ANSI_COLOR_RED "ERROR" ANSI_COLOR_RESET " Target is empty.");
  return;
}

//allocate memory
if( MAP(&code, length, PAGE_READWRITE) == MAP_FAILED)
{
  printf("\n" ANSI_COLOR_RED "ERROR %lu:" ANSI_COLOR_RESET " Can't map necessary memory.",GET_LAST_ERROR());
  return;
}

//copy from file and close
if (fread(code.address, 1, length, file) != length)
{
   printf("\n" ANSI_COLOR_RED "ERROR" ANSI_COLOR_RESET " Can't read file into memory.");
   return;
}

fclose(file);

//change protection
if(PROTECT(&code, PAGE_EXECUTE_READ) == PROTECT_FAILED)
{
  printf("\n" ANSI_COLOR_RED "ERROR %lu:" ANSI_COLOR_RESET " Can't make code executable.", GET_LAST_ERROR());
  return;
}

printf(ANSI_COLOR_BLUE "Done.\n" ANSI_COLOR_RESET);
