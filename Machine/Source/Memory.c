#include "Memory.h"




void    memory_init(Memory *memory) {

    for (size_t i = 0; i < MEMORY_SIZE; i++)
    {
        memory->data[i] = 0x00;
    }
    
    memory->initialized = 1;

}



uint8_t memory_read(const Memory *memory, uint8_t address) {

    if (!memory->initialized) return 0;

    if (address>=MEMORY_SIZE) return 0;

    return memory->data[address];

}


void    memory_write(Memory *memory, uint8_t address, uint8_t value) {

    if (!memory->initialized) return;

    if (address>=MEMORY_SIZE) return;

    memory->data[address] = value;

}




uint8_t* memory_dump(Memory*memory) {

    return memory->data;

}