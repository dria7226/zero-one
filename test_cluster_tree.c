printf("Starting tree test.\n");

cluster_tree* test_tree = init_tree();

printf("	TEST_TREE IS: %x \n",test_tree);

printf("	TEST_TREE->top_node IS: %x \n",test_tree->top_node);

printf("	TEST_TREE->height IS: %x \n",test_tree->height);

int z;

for(z = 0; z < CLUSTER_SIZE; z++)
{
	test_tree->top_node->cluster[z].value = z;
}

for(z = 0; z < CLUSTER_SIZE; z++)
{
	printf("	TEST_TREE->top_node->cluster[i].value IS: %x \n",test_tree->top_node->cluster[z].value);
}

cluster_tree* other_tree = init_tree();

printf("Ending tree test.\n");
