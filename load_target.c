// #define TARGET argv[1]

printf(ANSI_COLOR_GREEN "Loading target ... " ANSI_COLOR_RESET);

FILE* file = fopen(TARGET,"rb");

struct memory code;

#define PAGE_SIZE 4096

fseek(file, 0, SEEK_END);
unsigned long length = ftell(file);
fseek(file, 0, SEEK_SET);

printf("\nThe length of the file is %lu bytes",length);

if(length == 0)
{
  printf("\n" ANSI_COLOR_RED "ERROR" ANSI_COLOR_RESET " Target is empty.");
  return;
}

//allocate memory
printf("\nMapping");
MAP(&code, /*length*/ PAGE_SIZE, PAGE_READWRITE);

//copy from file and close
printf("\nReading");
unsigned long var = fread(code.address, length, 1, file);
printf("\nfread == %lu",var);
if (var != length)
{
   printf("\n" ANSI_COLOR_RED "ERROR" ANSI_COLOR_RESET " Can't read file into memory.");
   return;
}

printf("\nClosing");
fclose(file);

//change protection
printf("\nProtecting");
PROTECT(&code, PAGE_EXECUTE_READ);

printf(ANSI_COLOR_BLUE "Done.\n" ANSI_COLOR_RESET);
