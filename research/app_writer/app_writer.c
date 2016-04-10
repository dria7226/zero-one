#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "global_variables.c"

#include "GUI_helpers.c"

#include "helpers.c"

#include "./writers/includes.c"

#include "GUI_main_menu.c"

int main (int argc, char** argv)
{
	#include "setup.c"

	while(draw_main_menu());

}