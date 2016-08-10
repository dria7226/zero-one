printf(ANSI_COLOR_GREEN "Running target. \n" ANSI_COLOR_RESET);

asm volatile("jmp *%0" : : "r" (code.address));

register short ax asm("ax");
printf("\n ax is: %hd\n", ax);
