//SDL_Log(" head: %i ",tape[HEAD].value);
//interpretter
if(tape[HEAD].value >= 256){done = true;break;}
if(tape[tape[HEAD].value].type == function) functions[tape[tape[HEAD].value].value]();

tape[HEAD].value++;
if(tape[STEP_DT].value != 0) SDL_Delay( tape[STEP_DT].value );
