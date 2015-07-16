//Init SDL
if(SDL_Init(SDL_INIT_EVERYTHING^SDL_INIT_HAPTIC) < 0) return 0;

//Calculate preffered window size
SDL_GetDesktopDisplayMode(0, &display);

window_width = (int)(display.w*0.9);
window_height = (int)(display.h*0.9);

//Create window
window = SDL_CreateWindow("01", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, window_width, window_height, SDL_WINDOW_SHOWN );

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

#include "zo_load_interface.c"

#include "zo_load_program.c"

#include "debug_window_setup.c"
