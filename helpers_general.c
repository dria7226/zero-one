void draw_square(int x , int y , int l)
{
	SDL_RenderDrawLine(debug_renderer, x-l, y-l, x+l, y-l);
	SDL_RenderDrawLine(debug_renderer, x+l, y-l, x+l, y+l);
	SDL_RenderDrawLine(debug_renderer, x+l, y+l, x-l, y+l);
	SDL_RenderDrawLine(debug_renderer, x-l, y+l, x-l, y-l);
}

void draw_cross(int x , int y , int l)
{
	SDL_RenderDrawLine(debug_renderer, x-l , y-l , x+l , y+l);
	SDL_RenderDrawLine(debug_renderer, x+l , y-l , x-l , y+l);
}

void draw_line(int x1 , int y1 , int x2 , int y2)
{
	SDL_RenderDrawLine(debug_renderer, x1 , y1 , x2 , y2);
}

#define thw 3//Text Half Width
//0
void draw_0(int x, int y)
{
	SDL_RenderDrawLine(debug_renderer, x-thw, y-thw, x+thw, y-thw);
	SDL_RenderDrawLine(debug_renderer, x+thw, y-thw, x+thw, y+thw);
	SDL_RenderDrawLine(debug_renderer, x+thw, y+thw, x-thw, y+thw);
	SDL_RenderDrawLine(debug_renderer, x-thw, y+thw, x-thw, y-thw);
	
	SDL_RenderDrawLine(debug_renderer, x-thw, y+thw, x+thw, y-thw);
}

//1
void draw_1(int x, int y)
{
	SDL_RenderDrawLine(debug_renderer, x,y+thw,x,y-thw);
}

//2
void draw_2(int x, int y)
{
	SDL_RenderDrawLine(debug_renderer, x-thw, y-thw, x+thw, y-thw);
	SDL_RenderDrawLine(debug_renderer, x+thw, y+thw, x-thw, y+thw);
	
	SDL_RenderDrawLine(debug_renderer, x-thw, 	  y, x-thw, y+thw);
	SDL_RenderDrawLine(debug_renderer, x+thw, y-thw, x+thw, y);
	
	SDL_RenderDrawLine(debug_renderer, x+thw,     y, x-thw, y);
}

//3
void draw_3(int x, int y)
{
	SDL_RenderDrawLine(debug_renderer, x-thw, y-thw, x+thw, y-thw);
	SDL_RenderDrawLine(debug_renderer, x+thw, y-thw, x+thw, y+thw);
	SDL_RenderDrawLine(debug_renderer, x+thw, y+thw, x-thw, y+thw);
	SDL_RenderDrawLine(debug_renderer, x+thw,     y, x-thw, y);
}

//4
void draw_4(int x, int y)
{
	SDL_RenderDrawLine(debug_renderer, x+thw, y-thw, x+thw, y+thw);
	
	SDL_RenderDrawLine(debug_renderer, x-thw, y-thw, x-thw, y);
	SDL_RenderDrawLine(debug_renderer, x+thw,     y, x-thw, y);
}

//5
void draw_5(int x, int y)
{
	SDL_RenderDrawLine(debug_renderer, x-thw, y-thw, x+thw, y-thw);
	SDL_RenderDrawLine(debug_renderer, x+thw, y+thw, x-thw, y+thw);
	
	SDL_RenderDrawLine(debug_renderer, x-thw, y-thw, x-thw, y);
	SDL_RenderDrawLine(debug_renderer, x+thw,     y, x+thw, y+thw);
	
	SDL_RenderDrawLine(debug_renderer, x+thw,     y, x-thw, y);
}

//6
void draw_6(int x, int y)
{
	SDL_RenderDrawLine(debug_renderer, x-thw, y-thw, x+thw, y-thw);
	SDL_RenderDrawLine(debug_renderer, x+thw, y+thw, x-thw, y+thw);
	SDL_RenderDrawLine(debug_renderer, x-thw, y+thw, x-thw, y-thw);
	
	SDL_RenderDrawLine(debug_renderer, x+thw,     y, x+thw, y+thw);
	SDL_RenderDrawLine(debug_renderer, x+thw,     y, x-thw, y);
}

//7
void draw_7(int x, int y)
{
	SDL_RenderDrawLine(debug_renderer, x+thw, y-thw, x-thw, y-thw);
	
	SDL_RenderDrawLine(debug_renderer, x-thw, y+thw, x+thw, y-thw);
}

//8
void draw_8(int x, int y)
{
	SDL_RenderDrawLine(debug_renderer, x-thw, y-thw, x+thw, y-thw);
	SDL_RenderDrawLine(debug_renderer, x+thw, y-thw, x+thw, y+thw);
	SDL_RenderDrawLine(debug_renderer, x+thw, y+thw, x-thw, y+thw);
	SDL_RenderDrawLine(debug_renderer, x-thw, y+thw, x-thw, y-thw);
	
	SDL_RenderDrawLine(debug_renderer, x+thw,     y, x-thw, y);
}

//9
void draw_9(int x, int y)
{
	SDL_RenderDrawLine(debug_renderer, x-thw, y-thw, x+thw, y-thw);
	SDL_RenderDrawLine(debug_renderer, x+thw, y-thw, x+thw, y+thw);
	SDL_RenderDrawLine(debug_renderer, x+thw, y+thw, x-thw, y+thw);
	
	SDL_RenderDrawLine(debug_renderer, x-thw, y-thw, x-thw, y);
	SDL_RenderDrawLine(debug_renderer, x+thw,     y, x-thw, y);
}
