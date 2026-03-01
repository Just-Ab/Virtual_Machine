#pragma once

#include <stdint.h>
#include "CPU.h"
#include "Memory.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    uint8_t *data;
    size_t byte_size;
} ROM;

typedef struct {
    CPU cpu;
    Memory memory;
    int initialized;
    int running;
}VM;


void vm_init(VM *vm);
void vm_load(VM *vm,ROM rom);
void vm_run(VM *vm);
void vm_update(VM *vm,float delta);
void vm_stop(VM *vm);

void vm_print_memory(VM *vm);

#ifdef __cplusplus
}
#endif