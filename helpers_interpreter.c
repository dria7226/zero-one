/***********************
*
*Interpreter helpers
*
************************/

//Draw line function
void draw_l(unsigned char x1, unsigned char y1, unsigned char x2, unsigned char y2)
{
	SDL_SetRenderDrawColor( renderer, tape[R].value, tape[G].value, tape[B].value, tape[A].value );
	
	unsigned int X1 = x1*window_width/255;
	unsigned int Y1 = y1*window_height/255;
	
	unsigned int X2 = x2*window_width/255;
	unsigned int Y2 = y2*window_height/255;
	
	SDL_RenderDrawLine(renderer, X1,Y1,X2,Y2);
}

//Fill triangle function
void draw_t(unsigned char x1, unsigned char y1, unsigned char x2, unsigned char y2, unsigned char x3, unsigned char y3)
{
	SDL_SetRenderDrawColor( renderer, tape[R].value, tape[G].value, tape[B].value, tape[A].value );
	
	unsigned int X1 = x1*window_width/255;
	unsigned int Y1 = y1*window_height/255;
	
	unsigned int X2 = x2*window_width/255;
	unsigned int Y2 = y2*window_height/255;
	
	unsigned int X3 = x3*window_width/255;
	unsigned int Y3 = y3*window_height/255;
	
	
}

//Clear function
void clear()
{
	SDL_SetRenderDrawColor( renderer, tape[R].value, tape[G].value, tape[B].value, tape[A].value );
	
	SDL_RenderClear(renderer);
}


