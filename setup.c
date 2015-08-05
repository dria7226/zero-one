//Init SDL
if(SDL_Init(SDL_INIT_EVERYTHING^SDL_INIT_HAPTIC) < 0) return 0;

//Calculate preffered window size
SDL_GetDesktopDisplayMode(0, &display);

window_width = (int)(display.w*0.9);
window_height = (int)(display.h*0.9);

//Create window
window = SDL_CreateWindow("01", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, window_width, window_height, SDL_WINDOW_HIDDEN );

if( window == NULL )
{
	SDL_Log( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
	return 0;
}

//Create renderer
renderer = SDL_CreateRenderer( window, -1, 0 );
if( renderer == NULL )
{
    SDL_Log( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
}

memory = init_tree();

selected_node = memory->top_node;
selected_subnode = 0;

//------------------------

printf("CLUSTER_SIZE: %u\n",CLUSTER_SIZE);

unsigned char x,y,z,c;

unsigned char* answer;

x = 20;
y = 40;

answer = add_with_manual_overflow(x,y,1);

if(!half_adder_error)
{	
	z = answer[0];
	c = answer[1];
	
	printf("%u + %u = %u, with %u carry\n",x,y,z,c);
}
else
	printf("half adder error \n");

x = 98;
y = 254;

answer = add_with_manual_overflow(x,y,1);

if(!half_adder_error)
{	
	z = answer[0];
	c = answer[1];
	
	printf("%u + %u = %u, with %u carry\n",x,y,z,c);
}
else
	printf("half adder error \n");
	
x = 55;
y = 50;

answer = add_with_manual_overflow(x,y,1);

if(!half_adder_error)
{	
	z = answer[0];
	c = answer[1];
	
	printf("%u + %u = %u, with %u carry\n",x,y,z,c);
}
else
	printf("half adder error \n");

x = 99;
y = 99;

answer = add_with_manual_overflow(x,y,1);

if(!half_adder_error)
{	
	z = answer[0];
	c = answer[1];
	
	printf("%u + %u = %u, with %u carry\n",x,y,z,c);
}
else
	printf("half adder error \n");

x = 254;
y = 254;

answer = add_with_manual_overflow(x,y,1);

if(!half_adder_error)
{	
	z = answer[0];
	c = answer[1];
	
	printf("%u + %u = %u, with %u carry\n",x,y,z,c);
}
else
	printf("half adder error \n");

//------------------------

address a,b;

unsigned char a_address[] = { 89, 99, 52, 24,CLUSTER_SIZE};

a = a_address;

unsigned char b_address[] = {     59, 99, 13,CLUSTER_SIZE};

b = b_address;

printf("a");
address_print(&a);
printf("\n");

printf("b");
address_print(&b);
printf("\n");

increment_address_by(&a,&b);

printf("a+b=");
address_print(&a);

#include "zo_load_interface.c"

#include "zo_load_program.c"

#include "debug_window_setup.c"
