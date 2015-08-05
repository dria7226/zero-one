/**********************
*
*Address Helpers
*
***********************/

void address_print(address* a)
{
	long long unsigned int i;
	
	printf("\nAddress ");
	for(i = 0; (*a)[i] < CLUSTER_SIZE; i++)
	{
		printf("%u ",(*a)[i]);
	}
	printf("\n");
}

long long unsigned int address_cleanup(address* a)
{
	long long unsigned int i;
	long long unsigned int address_length,effective_address_length; // effective address length (exclunding leading zeroes)
	bool more_consecutive_zeroes = true;
	
	//address_print(a);
	
	//Calculating effective address length	
	for(i = 0, effective_address_length = 0; (*a)[i] < CLUSTER_SIZE;i++)
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
	
	//Done calculating effective address length
	
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
	
	//address_print(a);
	
	return address_length;
}


bool adjust_address_to_length(address* a, long long unsigned int length)
{
	long long unsigned int i;
	long long unsigned int address_length = address_cleanup(a);
	
	if(!address_length)return false;
	
	if(address_length > length)
	{
		address new_address = calloc(length+1,sizeof(unsigned char));
		
		new_address[length] = CLUSTER_SIZE;
		
		long long unsigned int j;
		for(i = length-1;i >= 0; i--)
		{
			new_address[i] = (*a)[i];
		}
		
		a = &new_address;
		address_length = length+1;
	}
	
	if(address_length < length)
	{
		address new_address = calloc(length+1,sizeof(unsigned char));
		
		new_address[length] = CLUSTER_SIZE;
		
		for(i = 0; i < (length+1 - address_length); i++)
		{
			new_address[i] = 0;
		}
		
		long long unsigned int j;
		for(j = 0;i < (length+1); i++,j++)
		{
			new_address[i] = (*a)[j];
		}
		
		a = &new_address;
		address_length = length+1;
	}
	
	return true;
}

/**
	0 - no error
	1 - x or y are greater than CLUSTER_SIZE
**/
unsigned char half_adder_error = 0;

unsigned char* add_with_manual_overflow( unsigned char x, unsigned char y, bool carry)
{
	if(x >= CLUSTER_SIZE || y >= CLUSTER_SIZE) { half_adder_error = 1; return;}
	
	//-------------------------z-c--
	unsigned char* result;
	result = calloc(2,sizeof(unsigned char));
	
	result[0] = x+y+carry;
	
	result[1] = result[0] < x;
	
	if(result[1])
	{
		result[0] += 255 - (CLUSTER_SIZE-1);
		return result;
	}
	
	if(result[0] > CLUSTER_SIZE-1)
	{
		result[1] = 1;
		result[0] = result[0] - CLUSTER_SIZE;
	}
	
	half_adder_error = 0;
	
	return result;
}

void increment_address_by(address* a, address* amount)
{
	//clean both addresses and get lengths
	long long unsigned int a_length = address_cleanup(a);
	long long unsigned int amount_length = address_cleanup(amount);
	
	if(!(a_length||amount_length)) return;
	
	if(amount_length > a_length)
	{
		adjust_address_to_length(a,amount_length);
		a_length = amount_length;
	}
	
	//repeatedly add pairs of bytes with carry-in and out
	long long unsigned int i;
	
	bool carry = 0;
	
	//be careful about overflow and carries (overflows at CLUSTER_SIZE [not MAX_UCHAR] and carries are multiples of C_S)	
	for(i = 0; i < a_length + 1; i++)
	{
		unsigned char* answer;
		
		answer = add_with_manual_overflow(a[i],amount[i],carry);
		
		if(!half_adder_error)
		{
			a[i] = answer[0];
			carry = answer[1];
		}
		
		free(answer);
	}
	
	if(carry)
	{
		adjust_address_to_length(a,a_length+1);
	
		(*a)[i++] = carry;
	}
	
}

void decrement_address_by(address* a, address* amount)
{
	//clean both addresses
	long long unsigned int a_length = address_cleanup(a);
	long long unsigned int amount_length = address_cleanup(amount);
	
	if(!(a_length||amount_length)) return;
	
	

}

long long unsigned int get_address_length(address* a)
{
	long long unsigned int i;
	
	for(i = 0; (*a)[i] < CLUSTER_SIZE;i++){}
	
	return i;
}
