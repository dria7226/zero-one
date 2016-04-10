/*
*	Writes DOS header
*/

void write_DOS_header()
{
	unsigned int length = 2*14;

	//allocate content
	unsigned char* content = calloc(length,1);

	//prepare content
	content[0] = 0x4D;
	content[1] = 0x5A;

	content[26] = 0;
	content[27] = 0;

	//write content
	fwrite(content, 1, length, app);

	//free content
	free(content);
}