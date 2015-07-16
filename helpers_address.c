/**********************
*
*Address Helpers
*
***********************/

void address_print(address* a)
{
	long long unsigned int i;
	
	printf("\nAddress ");
	for(i = 0; (*a)[i] != CLUSTER_SIZE; i++)
	{
		printf("%u ",(*a)[i]);
	}
	printf("\n");
}

void increment_address_by(address a, address amount)
{
	address carry;
	
	//find out which parameter is longer
	unsigned int i,a_length, amount_length;
	
	check_a_and_amount:
	if(a[i] == CLUSTER_SIZE)a_length = i;
	check_amount:
	if(amount[i] == CLUSTER_SIZE)amount_length = i;
	
	if(true)goto check_a_and_amount;
	
	
	
	carry = calloc(i+1,sizeof(char));
	
	
}

void decrement_address_by(address a, address amount)
{

}

long long unsigned int address_cleanup(address* a)
{
	long long unsigned int i;
	long long unsigned int address_length,effective_address_length; // effective address length (exclunding leading zeroes)
	bool more_consecutive_zeroes = true;
	
	address_print(a);
	
	//Calculating effective address length	
	for(i = 0, effective_address_length = 0; (*a)[i] != CLUSTER_SIZE;i++)
	{
		if(more_consecutive_zeroes)
		{
			if((*a)[i] != 0)
			{
				effective_address_length++;
				more_consecutive_zeroes = false;
			}
		}
		else
		{
			effective_address_length++;
		}
	}
	address_length = i;
	
	//Done calculating effective address length\
	
	//Shorten the address if too long
	if(address_length != effective_address_length)
	{
		address effective_address = calloc(effective_address_length+1,sizeof(unsigned char));
		
		effective_address[effective_address_length] = CLUSTER_SIZE;
		for(i = 1; i < effective_address_length+1;i++)
		{
			effective_address[effective_address_length-i] = (*a)[address_length-i];
		}
		
		free((*a));
		(*a) = effective_address;
		
		address_length = effective_address_length;
	}
	
	address_print(a);
	
	return address_length;
}


bool adjust_address_to_length(address* a, long long unsigned int length)
{
	long long unsigned int i;
	long long unsigned int address_length = address_cleanup(a);
	
	if(!address_length)return false;
	
	if(address_length > tree->height+1)
	{
		printf("\nAddress is longer than the tree height.\n");
		for(i = 0; i < address_length-(tree->height+1); i++)
		{
			supernode_tree(tree);
		}
		
		tree->height = address_length-1;
	}
	
	if(address_length < (tree->height+1))
	{
		printf("\nAddress is shorter than the tree height.\n");
		address new_address = calloc(tree->height+2,sizeof(unsigned char));
		
		new_address[tree->height+1] = CLUSTER_SIZE;
		
		for(i = 0; i < (tree->height+1 - address_length); i++)
		{
			new_address[i] = 0;
		}
		
		long long unsigned int j;
		for(j = 0;i < (tree->height+1); i++,j++)
		{
			new_address[i] = (*a)[j];
		}
		
		a = &new_address;
		address_length = tree->height+1;
		
		address_print(a);
	}
	
	return true;
}
