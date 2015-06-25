SDL_SetRenderDrawColor( debug_renderer, 0, 20, 0, 255 );

SDL_RenderClear(debug_renderer);

SDL_SetRenderDrawColor( debug_renderer, 0, 255, 0, 255 );

draw_node(selected_node);

draw_0(8,10);
draw_1(16,10);
draw_2(24,10);
draw_3(32,10);
draw_4(40,10);
draw_5(48,10);
draw_6(56,10);
draw_7(64,10);
draw_8(72,10);
draw_9(80,10);

SDL_RenderPresent( debug_renderer );
