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
	draw_rectangle(x,y,2);
	
	int v;
	if(node->cluster)
	{
		for(v = 1; v < CLUSTER_SIZE+1; v++)
		{
			SDL_SetRenderDrawColor( debug_renderer, 255, 0, 0, 255 );
			
			draw_rectangle(x,y+1+v*4,2);
			
			SDL_SetRenderDrawColor( debug_renderer, 0, 255, 0, 255 );
		}
	}
	
	if(!(node->subnodes))return;
	
	//draw subnodes	
	for(v = 0; v < CLUSTER_SIZE; v++)
	{
		int s_x;
		int s_y;
		
		s_x = x - (CLUSTER_SIZE-1)*subnode_spacing/2 + subnode_spacing*v;
		s_y = y + 20;
		
		draw_line(x,y,s_x,s_y);
		
		if(node->subnodes[v] != NULL)
		{
			draw_node(node->subnodes[v], s_x, s_y , subnode_spacing/(CLUSTER_SIZE-1));
		}
		else
		{
			
			draw_cross(s_x,s_y,2);
		}
	}
}

void draw_tree(cluster_tree* tree, int x, int y, int subnode_spacing)
{
	SDL_SetRenderDrawColor(debug_renderer, 0 , 255, 0, 255);
	
	draw_node(tree->top_node, x, y, subnode_spacing);
	
	SDL_RenderPresent(debug_renderer);
}
