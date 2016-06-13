
asm volatile("jmp *%0" : : "r" (code->address));