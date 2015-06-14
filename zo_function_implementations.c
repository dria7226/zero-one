typedef void (*func_type)(void);

func_type functions[NO_OF_FUNCTIONS];

//MOV
void _mov(void)
{
	tape[tape[tape[HEAD].value+2].value].value = tape[tape[HEAD].value + 1].value;
}

//AT
void _at(void)
{
	tape[tape[tape[HEAD].value+2].value].value = tape[tape[tape[HEAD].value+1].value].value;
}

//JMP
void _jmp(void)
{
	tape[HEAD].value = tape[JMP_X].value; tape[HEAD].value--;
}

//LESS
void _less(void)
{
	tape[LESS_X].value = tape[CMP_A].value < tape[CMP_B].value;
}

//EQUAL
void _equal(void)
{
	tape[EQUAL_X].value = tape[CMP_A].value == tape[CMP_B].value;
}

//GREATER
void _greater(void)
{
	tape[GREATER_X].value = tape[CMP_A].value > tape[CMP_B].value;
}

//ADD
void _add(void)
{
	tape[ADD_X].value = tape[ADD_A].value + tape[ADD_B].value;
}

//SUB
void _sub(void)
{
	tape[SUB_X].value = tape[SUB_A].value - tape[SUB_B].value;
}

//MUL
void _mul(void)
{
	tape[MUL_X].value = tape[MUL_A].value * tape[MUL_B].value;
}

//NOT
void _not(void)
{
	tape[NOT_X].value =				   ~ tape[NOT_A].value;
}

//AND
void _and(void)
{
	tape[AND_X].value = tape[AND_A].value & tape[AND_B].value;
}

//XOR
void _xor(void)
{
	tape[XOR_X].value = tape[XOR_A].value ^ tape[XOR_B].value;
}

//SHIFT_L
void _shift_l(void)
{
	tape[SHIFT_X].value = tape[SHIFT_Left].value << tape[SHIFT_A].value;
}

//SHIFT_R
void _shift_r(void)
{
	tape[SHIFT_X].value = tape[SHIFT_Right].value >> tape[SHIFT_A].value;
}

//DRAW
void _draw(void)
{
	draw_l(tape[X1].value,tape[Y1].value,tape[X2].value,tape[Y2].value);
}

//FILL
void _fill(void)
{
	draw_t(tape[X1].value,tape[Y1].value,tape[X2].value,tape[Y2].value,tape[X3].value,tape[Y3].value);
}

//CLRS
void _clrs(void)
{
	clear();
}

//RNDR
void _rndr(void)
{
	SDL_RenderPresent( renderer );
}

