SDL_SetRenderDrawColor( debug_renderer, 0, 20, 0, 255 );

SDL_RenderClear(debug_renderer);

SDL_SetRenderDrawColor( debug_renderer, 0, 255, 0, 255 );

draw_node(selected_node);

draw_char_value(window_width/2 + 100, window_height/2,selected_subnode)

SDL_RenderPresent( debug_renderer );
