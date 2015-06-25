if(event.key.windowID == 2)
{	
	switch(event.key.keysym.sym)
	{
		case SDLK_UP:
		{
			if(selected_node->supernode)
			selected_node = selected_node->supernode;
			break;
		}
		
		case SDLK_DOWN:
		{
			if(selected_node->subnodes && selected_node->subnodes[selected_subnode])
			selected_node = selected_node->subnodes[selected_subnode];
			break;
		}
		
		case SDLK_LEFT:
		{
			if(!(selected_node->supernode) || selected_subnode == 0)break;
			selected_subnode--;
			selected_node = selected_node->supernode->subnodes[selected_subnode];
			break;
		}
		
		case SDLK_RIGHT:
		{
			if(!(selected_node->supernode) || selected_subnode == CLUSTER_SIZE-1)break;
			selected_subnode++;
			selected_node = selected_node->supernode->subnodes[selected_subnode];
			break;
		}
		 
	}
}
