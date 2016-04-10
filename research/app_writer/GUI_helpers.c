/*
*	GUI Helpers
*/

void clear_screen()
{
	int i;
	for(i = 0; i<16;i++)
		printf("\n\n\n\n\n\n\n\n");
}

const unsigned char line_length = 64;

void draw_title(char* title)
{
	int length;
	for(length = 0; title[length] > 0; length++);

	int i;
	for(i = 0; i < (line_length-length)/2;i++)printf(">");
	printf("%s",title);
	for(i = 0; i < (line_length-length)/2;i++)printf("<");

	printf("\n");
}

void draw_row()
{
	int i;
	for(i = 0; i < line_length/2; i++)printf(">");
	for(i = 0; i < line_length/2; i++)printf("<");
	printf("\n");
}