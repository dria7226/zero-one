
asm volatile("jmp *%0" : : "r" (code->address));

printf("Target done running \n");
