#define SYSTEM_ADDRESS_SIZE 8

typedef struct replacement{
    //make to_replace addresses start with 8 0x00 bytes, in order to improve performance
    //these will be followed by one byte to id the system call (this limits the number of system calls to 256)
    uint8_t* to_replace;

    uint64_t* replace_with;
}replacement;

typedef struct r_map_node{
    uint8_t* index;
    struct r_map_node* next;
}r_map_node;

typedef struct r_map{
    uint16_t size;
    r_map_node* start;
    r_map_node* end;
}r_map;

void add_node(r_map* map, r_map_node* node)
{
    map->end->next = node;
    map->size++;
    map->end = node;
}

void replace_system_calls_in_segment(uint8_t* buffer, uint16_t length)
{
    //create replacement map
    r_map* map;

    map->start = NULL;
    map->end = NULL;
    map->size = 0;

    //find call to replace
    uint16_t i;
    for(i =1; i < length; i++)
    {
        //check for a sequence of 8 0x00 bytes
        uint8_t j = 0;
        while(j < SYSTEM_ADDRESS_SIZE)
        {
            if( buffer[i + j] == 0x00)
            {
                j++;
                if( j == SYSTEM_ADDRESS_SIZE - 1 )
                {
                   //verify if valid instruction
                   if ((buffer[i-1] && buffer[i-1] == 0xFF) || (buffer[i-2] && buffer[i-2] == 0xFF))
                   {
                      //is valid instruction, do replacement
                      //create node to add to node map
                      r_map_node* node;
                      node->address = i;

                      //first time code
                      if(map->start == NULL)
                      {
                          map->start = node;
                          map->end = node;
                          map->size++;
                      }
                      else
                      {
                          add_node(node);
                      }
                   }
                   else
                   {
                      //is not valid
                      i+=j;
                      break;
                   }
                }
            }
            else
            {
                //no chance for replacement, skip
                i+=j;
                break;
            }
        }
    }

    //replace the array using replacement map
    uint8_t address_length = SYSTEM_ADDRESS_SIZE;
    uint8_t temporary_length = SYSTEM_ADDRESS_SIZE + 1;
    uint16_t total_length = length - map->size*(temporary_length - address_length);

    // uint8_t* temp_buffer = VirtualAlloc(total_length);
    r_map_node* current_node = map->start;
    i = 0;
    uint8_t j;
    while(current_node->next != NULL)
    {
        if(i < current_node->address)
        {
            new_buffer[i] = buffer[i+j];
            i++;
        }
        if(i == current_node->address)
        {
            {
                //do replacement

            }

            current_node = current_node->next;
            j++;
        }

    }
}
