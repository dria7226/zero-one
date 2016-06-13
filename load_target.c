FILE* file = fopen(target,"rb");

memory* code;

fseek(file, 0, SEEK_END);
long length = ftell(file);
fseek(file, 0, SEEK_SET);

//allocate memory
MAP(code, length, PAGE_READWRITE);

//copy from file and close
if (fread(code->address, length, 1, file))
{
   printf("Can't read file into memory. /n");
   return;
}

fclose(file);

//change protection
PROTECT(code, PAGE_EXECUTE_READ);
