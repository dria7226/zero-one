/**********************
*
*Cluster Tree Data Structure
*
***********************/

//#define CLUSTER_SIZE 256

#define CLUSTER_SIZE 4

//Cluster node

typedef struct tree_node{
	struct tree_node** subnodes;
	struct tree_node* supernode;
	
    tape_type* cluster;
}tree_node;

//Tree

typedef struct cluster_tree{
	tree_node* top_node;
	
	unsigned int length;		// # of leaf nodes
	unsigned int total_size; 	// total # of nodes
}cluster_tree;

cluster_tree* internal_memory;

