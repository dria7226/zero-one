long long int i;
long long unsigned int address_length,effective_address_length; // effective address length (exclunding leading zeroes)
bool more_consecutive_zeroes = true;

//#include "address_print.c"

//Calculating effective address length
	
for(i = 0, address_length = 0; address[i] != CLUSTER_SIZE;i++)
{
	address_length++;
}

for(i = 0, effective_address_length = 0; address[i] != CLUSTER_SIZE;i++)
{
	if(more_consecutive_zeroes)
	{
		if(address[i] != 0)
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

unsigned char effective_address[effective_address_length+1];
//Shorten the address if too long
if(address_length != effective_address_length)
{
	effective_address[effective_address_length] = CLUSTER_SIZE;
	for(i = 1; i < effective_address_length+1;i++)
	{
		effective_address[effective_address_length-i] = address[address_length-i];
	}
	
	address = effective_address;
	
	address_length = effective_address_length;
}

//#include "address_print.c"
//Done calculating effective address length
