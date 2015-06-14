SDL_SetRenderDrawColor( debug_renderer, 0, 20, 0, 255 );

SDL_RenderClear(debug_renderer);

draw_tree(test_tree, window_width/2, 100, CLUSTER_SIZE*100);
