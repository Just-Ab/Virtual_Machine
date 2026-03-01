#include "VM.h"
#include "Fetch.h"
#include "Decode.h"
#include "Execute.h"
#include <stdio.h>





void vm_init(VM *vm) {
    
    cpu_init(&(vm->cpu));
    cpu_run(&(vm->cpu));
    memory_init(&(vm->memory));

    vm->initialized = 1;
    vm->running = 1;

    // for (size_t i = 0; i < MEMORY_SIZE; i++)
    // {
    //     memory.data[i] = 0x00;
    // }

}


void vm_load(VM *vm,ROM rom) {

    if (!vm->initialized) return;

    if (rom.byte_size>MEMORY_SIZE) return;

    for (size_t i = 0; i < rom.byte_size; i++)
    {
        vm->memory.data[i] = rom.data[i];
    }
}

void vm_run(VM *vm) {

    if (!vm->initialized) return;

    vm->running = 1;
}

void vm_update(VM *vm,float delta) {

    if (!vm->running || !vm->cpu.running) return;

    fetch_step(&vm->cpu,&vm->memory);
    uint8_t status = decode_step(&vm->cpu);
    execute_step(&vm->cpu,&vm->memory,status);
    
}

void vm_stop(VM *vm) {
    vm->running = 0;
}

void vm_print_memory(VM *vm) {

    uint8_t* memory_ptr = memory_dump(&vm->memory);

    for (size_t i = 0; i < MEMORY_SIZE; i++)
    {
        if(i % 16 == 0) printf("\n");

        printf("[%x]",(uint8_t)*(memory_ptr+i));

    }
    printf("\n");

}
