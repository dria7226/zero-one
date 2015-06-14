printf("Starting tree test.\n");

cluster_tree* test_tree = init_tree();

printf("	TEST_TREE IS: %x \n",test_tree);

printf("	TEST_TREE->top_node IS: %x \n",test_tree->top_node);

printf("	TEST_TREE->length IS: %x \n",test_tree->length);
	
printf("	TEST_TREE->total_size IS: %x \n\n",test_tree->total_size);

int z;

for(z = 0; z < CLUSTER_SIZE; z++)
{
	test_tree->top_node->cluster[z].value = z;
}

for(z = 0; z < CLUSTER_SIZE; z++)
{
	printf("	TEST_TREE->top_node->array[i].value IS: %x \n",test_tree->top_node->cluster[z].value);
}

cluster_tree* other_tree = init_tree();


for(z=0; z < 5; z++)
{
	tree_node* node = init_subnodes();	
	
	test_tree->top_node->supernode = node;
	node->subnodes[0] = test_tree->top_node;
	test_tree->top_node = node;
}

printf("Ending tree test.\n");
