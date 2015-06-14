SDL_Event event;
bool done = false;

while(!done)
{
	SDL_PumpEvents();
	while (SDL_PollEvent(&event))
	{
		#include "handle_events.c"
	}	

	#include "zo_main_loop.c"
	
	#include "debug_main_loop.c"
}
