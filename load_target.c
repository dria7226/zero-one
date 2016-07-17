#define TARGET argv[1]

printf("Loading target ...");

FILE* file = fopen(TARGET,"rb");

memory* code;

fseek(file, 0, SEEK_END);
long length = ftell(file);
fseek(file, 0, SEEK_SET);

//allocate memory
MAP(code, length, PAGE_READWRITE);

//copy from file and close
if (fread(code->address, length, 1, file))
{
   printf("\nCan't read file into memory.");
   return;
}

fclose(file);

//change protection
PROTECT(code, PAGE_EXECUTE_READ);

printf("Done.\n");
