//Create debug window
debug_window = SDL_CreateWindow("01 DEBUG", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, window_width, window_height, SDL_WINDOW_SHOWN );

if( debug_window == NULL )
{
	SDL_Log( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
	return 0;
}

//Create renderer
debug_renderer = SDL_CreateRenderer( debug_window, -1, 0 );
if( debug_renderer == NULL )
{
    SDL_Log( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
}
