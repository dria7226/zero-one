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
