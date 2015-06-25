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
	node->cluster = (symbol*)calloc(CLUSTER_SIZE-1,sizeof(symbol));
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
	
	tree->height = 0;
	
	return tree;
}

void supernode(tree_node* node)
{
	if(node->supernode)return;
	tree_node* super = init_subnodes();
	super->subnodes[0] = node;
	node->supernode = super;
}

void supernode_tree(cluster_tree* tree)
{
	supernode(tree->top_node);
	tree->top_node = tree->top_node->supernode;
}

void subnode(tree_node* node, unsigned char address)
{
	if(!node || !(node->subnodes) || node->cluster || node->subnodes[address])return;
	node->subnodes[address] = init_subnodes();
	node->subnodes[address]->supernode = node;
}

tree_node* get_cluster_by_address(cluster_tree* tree, unsigned char* address)
{

}

void swap_clusters(tree_node* node_a, tree_node* node_b)
{

}

void insert_cluster_at_address(unsigned char* address, tree_node* target)
{

}

void create_cluster_at_address(unsigned char* address, cluster_tree* tree)
{	
	#include "address_cleanup.c"
	
	if(!address_length)return;

	
	if(address_length > tree->height+1)
	{
		printf("\nAddress is longer the tree height.\n");
		for(i = 0; i < address_length-(tree->height+1); i++)
		{
			supernode_tree(tree);
		}
		
		tree->height = address_length-1;
	}
	
	if(address_length < (tree->height+1))
	{
		printf("\nAddress is shorter the tree height.\n");
		unsigned char new_address[tree->height+2];
		
		new_address[tree->height+1] = CLUSTER_SIZE;
		
		for(i = 0; i < (tree->height+1 - address_length); i++)
		{
			new_address[i] = 0;
		}
		
		int j;
		for(j = 0;i < (tree->height+1); i++,j++)
		{
			new_address[i] = address[j];
		}
		
		address = new_address;
		address_length = tree->height+1;
		
		//#include "address_print.c"
	}
	
	//now add the cluster
	tree_node* current_node = tree->top_node;
	for(i = 0; i < address_length-1; i++)
	{
		if(current_node->subnodes[address[i]] == NULL)
		{
			if(i != address_length-2)
				subnode(current_node,address[i]);
			else
				{
					current_node->subnodes[address[i]] = init_cluster();
					current_node->subnodes[address[i]]->supernode = current_node;
					break;
				}
		}
		
		current_node = current_node->subnodes[address[i]];
	}
}

void remove_cluster_at_address(unsigned char* address, cluster_tree* tree, bool dealloc)
{

	

}

symbol* get_symbol_at_address(unsigned char* address, cluster_tree* tree)
{
	return;
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
void draw_node(tree_node* node)
{	
	if(!node)return;
	
	if(node->supernode == NULL && node->subnodes == NULL && node->cluster == NULL)
		//draw cross for node
		draw_cross(window_width/2,window_height/2,20);
	else
		//draw square for node
		draw_square(window_width/2,window_height/2,20);
	
	//draw supernode
	if(node->supernode)
	{
		int s_y = window_height/4;
		
		draw_line(window_width/2,window_height/2,window_width/2,s_y);
		draw_square(window_width/2,s_y,20);
		
		if(node->supernode->supernode)
		{
			draw_line(window_width/2,s_y,window_width/2,0);
		}
	}
	
	int v;
	//draw cluster
	if(node->cluster)
	{
		unsigned int width = (unsigned int)(window_width/(CLUSTER_SIZE-1));
		if(width > 30) width = 30;
		for(v = 0; v < CLUSTER_SIZE-1; v++)
		{
			if(node->cluster[v].type = function)
				SDL_SetRenderDrawColor( debug_renderer, 0, 0, 255, 255 );
			else
				SDL_SetRenderDrawColor( debug_renderer, 255, 0, 0, 255 );
			
			draw_square(window_width/2 - width*(CLUSTER_SIZE-2)/2+width*v
						,window_height/4*3
						,width/2);
			
			SDL_SetRenderDrawColor( debug_renderer, 0, 255, 0, 255 );
		}
	}
	
	if(node->subnodes)
	{
		//draw subnodes	
		for(v = 0; v < CLUSTER_SIZE-1; v++)
		{
			unsigned int width = (unsigned int)(window_width/(CLUSTER_SIZE-1));
			if(width > 30) width = 30;
			
			int s_x;
			int s_y;
			
			s_x = window_width/2 - width*(CLUSTER_SIZE-2)/2+width*v;
			s_y = window_height/4*3;
			
			draw_line(window_width/2,window_height/2,s_x,s_y);
			
			if(node->subnodes[v] != NULL)
			{
				draw_square(s_x, s_y ,width/2);
			}
			else
			{	
				draw_cross(s_x, s_y, width/2);
			}
		}
	}
}
