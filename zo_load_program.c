//load program    
int i , j;
for(i = 0; i < PROGRAM_START; i++)
{
	tape[i].type = variable;
	
	memory->top_node->cluster[i].type = variable;
}

int program_length = (sizeof(program)/sizeof(0[program])) / ((size_t)(!(sizeof(program) % sizeof(0[program]))));
for(i = 0, j = 0; i < program_length;i++,j++)
{
    memory->top_node->cluster[PROGRAM_START + j].type  = program[i];
    tape[PROGRAM_START + j].type  = program[i];
    
    i++;
    
	tape[PROGRAM_START + j].value = program[i];
    memory->top_node->cluster[PROGRAM_START + j].value = program[i];
}

for(i = 0; i < PROGRAM_START+j+1; i++)
{
//	printf("\n%d\ntype: %d\nvalue: %d\n",i,memory->top_node->cluster[i].type,memory->top_node->cluster[i].value);
}

SDL_Log("\nProgram done loading.\n");

