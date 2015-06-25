#define RAND (rand() % CLUSTER_SIZE)
if(event.button.windowID == 2 && event.button.state == SDL_PRESSED && event.button.button == SDL_BUTTON_LEFT)
{	
	//add cluster
	unsigned char address[] = {RAND,RAND,RAND,CLUSTER_SIZE};
	create_cluster_at_address(address,memory);
}
