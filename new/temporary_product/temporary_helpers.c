struct typedef replacement{
    //make to_replace addresses start with 8 0x00 bytes, in order to improve performance
    //these will be followed by one byte to id the system call (this limits the number of system calls to 256)
    uint8_t* to_replace;

    uint8_t* replace_with;
}replacement;

void replace_system_calls_in_buffer(uint8_t buffer, unsigned int length)
{
    //find call to replace
    unsigned int i;
    for(i =0; i<length; i++)
    {
        //check for a sequence of 8 0x00 bytes
        uint8_t j = 0;
        while(j < 8)
        {
            if( buffer[i + j] == 0x00)
            {
                j++;
                if( j == 7 )
                //verify if valid instruction
            }
            else
            {
                //no chance for replacement, skip
                i+=j;
                break;
            }
        }
    }

    //replace the array
    
}