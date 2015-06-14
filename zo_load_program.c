//load program    
int i , j;
int program_length = (sizeof(program)/sizeof(0[program])) / ((size_t)(!(sizeof(program) % sizeof(0[program]))));
for(i = 0, j = 0; i < program_length;i++,j++)
{
    tape[PROGRAM_START + j].type  = program[i++];
    tape[PROGRAM_START + j].value = program[i];
}

if(true)
{
//	for(i = 0;i < PROGRAM_START + program_length; i++)
//	{
//	  	printf("\n");
//	    printf("%i type: %i\n",i,tape[i].type);
//	    printf("%i value: %i\n",i,tape[i].value);
//	    printf("\n");
//	}

SDL_Log("PROGRAM_START: %d",PROGRAM_START);

}
