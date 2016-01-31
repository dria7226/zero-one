#include "includes.c"

int main (int argc, char** argv)
{
	// unsigned char* i;
	// for(i = &main; i < &main+0x0BD0;i++)
	// {
	// 	printf("%c ",*((unsigned char *)i));
	// }

	//test mman_abstract
	
	printf("Hello!");

	memory* m;
	MMAP(m,100,PAGE_READWRITE);

	printf("Goodbye!");

	//search current folder for binaries - loop

		//load binaries

}
