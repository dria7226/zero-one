#include "headers.c"

#include "sections.c"

void write_app()
{
	//open file
	if(!open_file()) return;

	//headers
	write_headers();

	//sections
	write_sections();

	//close file
	if(app) fclose(app);
	
	printf("\n");
	system("PAUSE");
}