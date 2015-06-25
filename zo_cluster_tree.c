/**********************
*
*Cluster Tree Data Structure
*
***********************/

//#define CLUSTER_SIZE 255

#define CLUSTER_SIZE 5

//Cluster node

typedef struct tree_node{
	struct tree_node** subnodes;
	struct tree_node* supernode;
	
    symbol* cluster;
}tree_node;

//Tree

typedef struct cluster_tree{
	tree_node* top_node;
	
	long long unsigned int height;
}cluster_tree;
