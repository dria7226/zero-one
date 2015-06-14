//Destroy renderer
SDL_DestroyRenderer( renderer );

//Destroy window
SDL_DestroyWindow( window );

//Quit SDL subsystems
SDL_Quit();

return 0;
