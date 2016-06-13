FILE* file = fopen(target,"r");

memory* code;

//allocate memory
MAP(code, 2048, PAGE_READWRITE);

//copy from file
// memcpy(code->address);

//change protection
PROTECT(code, PAGE_EXECUTE_READ);
