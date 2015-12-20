/**********************
*
*Address Helpers
*
***********************/

void print_address(address* a)
{
	long long unsigned int i;
	
	printf("\nAddress ");
	for(i = 0; (*a)[i] < CLUSTER_SIZE; i++)
	{
		printf("%u ",(*a)[i]);
	}
	printf("\n");
}

long long unsigned int get_address_length(address* a)
{
	long long unsigned int i = 0;
	
	while((*a)[i] < CLUSTER_SIZE) {i++;}
	
	return i;
}

long long unsigned int cleanup_address(address* a)
{
	long long unsigned int i;
	long long unsigned int address_length,effective_address_length; // effective address length (exclunding leading zeroes)
	bool more_consecutive_zeroes = true;
	
	//print_address(a);
	
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
		
		free(*a);
		(*a) = effective_address;
		
		address_length = effective_address_length;
	}
	
	//print_address(a);
	
	return address_length;
}

bool adjust_address_to_length(address* a, long long unsigned int length)
{
	long long unsigned int i;
	long long unsigned int address_length = get_address_length(a);
	
	//error out if the length is 0
	if(!(address_length||length))return false;
	
	if(address_length == length) return true;
	
	address temp = calloc(length+1,sizeof(unsigned char));
	temp[length] = CLUSTER_SIZE;
	
	for(i = 0; i < length; i++)
	{
		if(i < address_length)
		temp[length - 1 - i] = (*a)[address_length - 1 - i];
		else
		temp[length - 1 - i] = 0;
	}
	
	free(a);
	
	*a = temp;
	
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
	
	//allocate RAM for answer
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
	// get lengths
	long long unsigned int 		a_length = get_address_length(a);
	long long unsigned int amount_length = get_address_length(amount);
	
	printf("%u,%u\n",a_length,amount_length);
	
	if(!(a_length||amount_length)) return;
	
	if(amount_length > a_length)
	{
		adjust_address_to_length(a,amount_length);
		a_length = amount_length;
	}
	
	if(amount_length < a_length)
	{
		adjust_address_to_length(amount,a_length);
		amount_length = a_length;
	}
	
	print_address(a);
	print_address(amount);
	
	printf("%u,%u\n",a_length,amount_length);
	
	//repeatedly add pairs of bytes with carry-in and out
	long long unsigned int i;
	
	bool carry = 0;
	
	//be careful about overflow and carries (overflows at CLUSTER_SIZE [not MAX_UCHAR] and carries are multiples of C_S)	
	for(i = 0; i < amount_length; i++)
	{
		unsigned char* answer;
		
		#define input_a ( (*a)[a_length - 1 - i] )
		#define input_amount ( (*amount)[amount_length - 1 - i] )
		
		printf("input_a : %u, input_amount : %u\n", input_a, input_amount);
		
		answer = add_with_manual_overflow(input_a,input_amount,carry);
		
		if(!half_adder_error)
		{
			input_a = answer[0];
			carry = answer[1];
			free(answer);
		}
		else
		{
			printf("half adder error \n");
			return;
		}
	}
	
	if(carry)
	{
		adjust_address_to_length(a,a_length+1);
		(*a)[i++] = carry;
	}
}

void increment_address(address* a)
{
	//get length
	long long unsigned int length = get_address_length(a);
	
	if(!length)return;
	
	//loop
	long long unsigned int i;
	
	#define input ( (*a)[length - 1 - i] )
	for(i = 0; i < length; i++)
	{
		input++;
		
		if( input < input-1 || input > CLUSTER_SIZE-1 )
		{
			//handle overflow
			
		}
		else
			return;
	}
}

void decrement_address_by(address* a, address* amount)
{
	//clean both addresses
	long long unsigned int a_length = cleanup_address(a);
	long long unsigned int amount_length = cleanup_address(amount);
	
	if(!(a_length||amount_length)) return;
	
	

}
