tape[M_X].value = event.motion.x*255/window_width;
tape[M_Y].value = event.motion.y*255/window_height;

if(event.motion.windowID == 2 && event.motion.type == SDL_MOUSEBUTTONDOWN)
{	
	if(firstTimeDragging)
	{
		previous.x = event.motion.x;
		previous.y = event.motion.y;
	}

	camera.x = camera.x - event.motion.x - previous.x;
	camera.y = camera.y - event.motion.y - previous.y;
	
	previous.x = event.motion.x;
	previous.y = event.motion.y;
}
