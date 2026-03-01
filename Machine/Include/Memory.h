#pragma once

#include <stdint.h>


#ifdef __cplusplus
extern "C" {
#endif

#define MEMORY_SIZE 256

typedef struct {
    uint8_t data[MEMORY_SIZE];
    int initialized;
}Memory;


void    memory_init(Memory *memory);
uint8_t memory_read(const Memory *memory, uint8_t address);
void    memory_write(Memory *memory, uint8_t address, uint8_t value);

uint8_t* memory_dump(Memory *memory);



#ifdef __cplusplus
}
#endif