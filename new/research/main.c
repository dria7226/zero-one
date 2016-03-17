#include "includes.c"

int main (int argc, char** argv)
{
	// unsigned char* i;
	// for(i = &main; i < &main+0x0BD0;i++)
	// {
	// 	printf("%c ",*((unsigned char *)i));
	// }

	//test mman_abstract

	unsigned char buffer[] =
	{
		0x48, 0x50
	};

	memory m;
	MAP(&m,sizeof(buffer),PAGE_READWRITE);

	if(&m == (void*)-1)
	{
		perror("NULL");
		return;
	}

	unsigned int i;
	for(i = 0; i < sizeof(buffer); i++)
	{
		&m[i] = buffer[i];
	}

	printf("Writing out mapped memory:\n");

	for(i = 0; i < sizeof(buffer);i++)
	{
		printf("%d\n",&m[i]);
	}

	printf("Done!");

	//search current folder for binaries - loop

		//load binaries

}
