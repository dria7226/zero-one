int window_width,window_height;
SDL_DisplayMode display;

SDL_Window* window;
SDL_Renderer* renderer;

SDL_Window* debug_window;
SDL_Renderer* debug_renderer;
bool firstTimeDragging;
point previous;
point camera;

//Tape
tape_type tape[256];
