printf("Running target. \n");

asm volatile("jmp *%0" : : "r" (code->address));
