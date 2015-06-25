int window_width,window_height;
SDL_DisplayMode display;

SDL_Window* window;
SDL_Renderer* renderer;

SDL_Window* debug_window;
SDL_Renderer* debug_renderer;
tree_node* selected_node;
unsigned char selected_subnode;

//Tape
symbol tape[256];
cluster_tree* memory;
