#define RAND (rand() % CLUSTER_SIZE)
if(event.button.windowID == 2 && event.button.state == SDL_PRESSED && event.button.button == SDL_BUTTON_LEFT)
{	
	//add cluster
	unsigned char rand_address[] = {RAND,RAND,RAND,CLUSTER_SIZE};
	
	address a = rand_address;
	
	create_cluster_at_address(&a,memory);
}
