//Destroy renderers
SDL_DestroyRenderer( renderer );
SDL_DestroyRenderer( debug_renderer );

//Destroy windows
SDL_DestroyWindow( window );
SDL_DestroyWindow( debug_window );

//Quit SDL subsystems
SDL_Quit();

return 0;
