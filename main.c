/*  Author: Dragos Iarovoi
    Product: 01
    */

/**************************
 *
 * Includes
 *
 **************************/
#include "includes.c"

/**************************
 *
 * Standard program
 *
 **************************/
#include "zo_standard_program.c"

/**************************
 *
 * Main
 *
 **************************/ 
int main(int argc, char** argv)
{		
	#include "setup.c"
	
	#include "test_run.c"
	
	#include "main_loop.c"
	
	#include "clean_up.c"
}
