/******************
*
*Text Helpers
*
******************/

typedef void (*draw_type)(int x,int y);

draw_type draw[10+26];

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

//a
//b
//c
//d
//e
//f
//g
//h
//i
//j
//k
//l
//m
//n
//o
//p
//q
//r
//s
//t
//w
//x
//y
//z

void load_draws()
{
	draw[0] = draw_0;
	draw[1] = draw_1;
	draw[2] = draw_2;
	draw[3] = draw_3;
	draw[4] = draw_4;
	draw[5] = draw_5;
	draw[6] = draw_6;
	draw[7] = draw_7;
	draw[8] = draw_8;
	draw[9] = draw_9;
}

#define draw_char_value(x,y,v) \
	draw[(unsigned char)(v-v%100)](x-thw*2-2,y);\
	draw[(unsigned char)(v%100-v%10)](x,y);\
	draw[(unsigned char)(v%10)](x+thw*2+2,y);

void draw_symbol_value(int x, int y, symbol* s)
{
	unsigned char v = s->value;
	
	draw_char_value(x,y,v)
}
