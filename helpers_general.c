void draw_rectangle(int x , int y , int l)
{
	SDL_RenderDrawLine(debug_renderer, x-l - camera.x, y-l - camera.y, x+l - camera.x, y-l - camera.y);
	SDL_RenderDrawLine(debug_renderer, x+l - camera.x, y-l - camera.y, x+l - camera.x, y+l - camera.y);
	SDL_RenderDrawLine(debug_renderer, x+l - camera.x, y+l - camera.y, x-l - camera.x, y+l - camera.y);
	SDL_RenderDrawLine(debug_renderer, x-l - camera.x, y+l - camera.y, x-l - camera.x, y-l - camera.y);
}

void draw_cross(int x , int y , int l)
{
	SDL_RenderDrawLine(debug_renderer, x-l - camera.x , y-l - camera.y , x+l - camera.x , y+l - camera.y);
	SDL_RenderDrawLine(debug_renderer, x+l - camera.x , y-l - camera.y , x-l - camera.x , y+l - camera.y);
}

void draw_line(int x1 , int y1 , int x2 , int y2)
{
	SDL_RenderDrawLine(debug_renderer, x1 - camera.x , y1 - camera.y , x2 - camera.x , y2 - camera.y);
}
