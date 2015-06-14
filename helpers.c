/***********************
*
*Interpretter helpers
*
************************/

//Draw line function
void draw_l(unsigned char x1, unsigned char y1, unsigned char x2, unsigned char y2)
{
	SDL_SetRenderDrawColor( renderer, tape[R].value, tape[G].value, tape[B].value, tape[A].value );
	
	unsigned int X1 = x1*window_width/255;
	unsigned int Y1 = y1*window_height/255;
	
	unsigned int X2 = x2*window_width/255;
	unsigned int Y2 = y2*window_height/255;
	
	SDL_RenderDrawLine(renderer, X1,Y1,X2,Y2);
}

//Fill triangle function
void draw_t(unsigned char x1, unsigned char y1, unsigned char x2, unsigned char y2, unsigned char x3, unsigned char y3)
{
	SDL_SetRenderDrawColor( renderer, tape[R].value, tape[G].value, tape[B].value, tape[A].value );
	
	unsigned int X1 = x1*window_width/255;
	unsigned int Y1 = y1*window_height/255;
	
	unsigned int X2 = x2*window_width/255;
	unsigned int Y2 = y2*window_height/255;
	
	unsigned int X3 = x3*window_width/255;
	unsigned int Y3 = y3*window_height/255;
	
	
}

//Clear function
void clear()
{
	SDL_SetRenderDrawColor( renderer, tape[R].value, tape[G].value, tape[B].value, tape[A].value );
	
	SDL_RenderClear(renderer);
}

/***********************
*
*Cluster tree helpers
*
************************/

tree_node* init_tree_node()
{
	tree_node* node = (tree_node*)malloc(sizeof(tree_node));
	if(!node) return;
	
	node->subnodes = NULL;
	node->supernode = NULL;
	
	node->cluster = NULL;
	
	return node;
}

tree_node* init_subnodes()
{
	tree_node* node = init_tree_node();
	
	//Initialize subnodes
	node->subnodes = (tree_node**)calloc(CLUSTER_SIZE,sizeof(tree_node*));
	if(!(node->subnodes))
	{
		free(node);
		return;
	}
	
	return node;
}

tree_node* init_cluster()
{
	tree_node* node = init_tree_node();
	
	//Initialize an array of CLUSTER_SIZE tape_type s
	node->cluster = (tape_type*)calloc(CLUSTER_SIZE,sizeof(tape_type));
	if(!(node->cluster))
	{
		free(node);
		return;
	}
	
	return node;
}

cluster_tree* init_tree()
{
	cluster_tree* tree = (cluster_tree*)malloc(sizeof(cluster_tree));
	if(!tree) return;
	
	tree->top_node = init_cluster();
	
	tree->length = 1;
	tree->total_size = 1;
	
	return tree;
}

tree_node* get_cluster_by_address(cluster_tree* tree, char* address)
{

}

void swap_clusters(tree_node* node_a, tree_node* node_b)
{

}

void insert_cluster(tree_node* node, tree_node* target)
{

}

void add_cluster(cluster_tree* tree)
{
	if(!tree->top_node) return;
	
	tree_node* current_node = tree->top_node;
	
	int i;
	//while the working node has subnodes
	while(current_node->subnodes)
	{
		//we find the last subnode and make it current
		
		for(i == CLUSTER_SIZE-1; i >= 0; i--)
		{
			if(&(current_node->subnodes[i]))
			{
				current_node = current_node->subnodes[i];
				break;
			}
		}
	}
	
	//now that we found the leaf, we find the next available spot
	while(current_node->supernode)
	{
		current_node = current_node->supernode;
		
		if(!current_node) break;
		
//		current_node->
	}
	
}

void remove_cluster(tree_node* node, bool dealloc)
{


}

//Cluster clean up
void free_node(tree_node* node)
{
	free(node);
}

void free_tree(cluster_tree* tree)
{
	
}


//Cluster draw
void draw_node(tree_node* node, int x, int y, int subnode_spacing)
{	
	//draw square for node
	SDL_RenderDrawLine(renderer, x-3,y-3, x+3,y-3);
	SDL_RenderDrawLine(renderer, x+3,y-3, x+3,y+3);
	SDL_RenderDrawLine(renderer, x+3,y+3, x-3,y+3);
	SDL_RenderDrawLine(renderer, x-3,y+3, x-3,y-3);
	
	int v;
	if(!(node->subnodes) && node->cluster)
	{
		for(v = 1; v < CLUSTER_SIZE+1; v++)
		{
			SDL_SetRenderDrawColor( renderer, 255, 0, 0, 255 );
			
			SDL_RenderDrawLine(renderer, x-3,y-3-v*3, x+3,y-3-v*3);
			SDL_RenderDrawLine(renderer, x+3,y-3-v*3, x+3,y+3-v*3);
			SDL_RenderDrawLine(renderer, x+3,y+3-v*3, x-3,y+3-v*3);
			SDL_RenderDrawLine(renderer, x-3,y+3-v*3, x-3,y-3-v*3);
			
			SDL_SetRenderDrawColor( renderer, 0, 255, 0, 255 );
		}
	}
	
	//draw subnodes	
	for(v = 0; v < CLUSTER_SIZE; v++)
	{
		int s_x;
		int s_y;
		
		s_x = x - (CLUSTER_SIZE-1)*subnode_spacing/2 + subnode_spacing*v;
		s_y = y + 20;
		
		SDL_RenderDrawLine(renderer, x,y, s_x,s_y);
		
		if(node->subnodes[v] != NULL)
		{
			draw_node(node->subnodes[v], s_x, s_y , subnode_spacing/(CLUSTER_SIZE-1));
		}
		else
		{
			
			SDL_RenderDrawLine(renderer, s_x-3,s_y-3, s_x+3,s_y+3);
			SDL_RenderDrawLine(renderer, s_x+3,s_y-3, s_x-3,s_y+3);
		}
	}
}
