#include "VM.h"
#include <stdio.h>
#include "Math.h"





int main() {
    
    VM* vm;

    vm_init(vm);

    memory_write(&vm->memory,0,OPCODE_MOV_REG_IMM);
    memory_write(&vm->memory,1,REG_ACC);
    memory_write(&vm->memory,2,0b0101);

    memory_write(&vm->memory,3,OPCODE_MOV_REG_IMM);
    memory_write(&vm->memory,4,REG_SEC);
    memory_write(&vm->memory,5,0b1010);

    memory_write(&vm->memory,6,OPCODE_MOV_REG_IMM);
    memory_write(&vm->memory,7,REG_SP);
    memory_write(&vm->memory,8,0x80);

    memory_write(&vm->memory,9,OPCODE_PUSH_REG);
    memory_write(&vm->memory,10,REG_SEC);


    memory_write(&vm->memory,11,OPCODE_MOV_REG_IMM);
    memory_write(&vm->memory,12,REG_SEC);
    memory_write(&vm->memory,13,0x00);

    memory_write(&vm->memory,14,OPCODE_POP_REG);
    memory_write(&vm->memory,15,REG_SEC);

    memory_write(&vm->memory,16,OPCODE_XOR_REG_REG);
    memory_write(&vm->memory,17,REG_ACC);
    memory_write(&vm->memory,18,REG_SEC);

    memory_write(&vm->memory,19,OPCODE_HALT);
    




    while (vm->running)
    {
        vm_print_memory(vm);
        printf("REG_ACC: %x\n",(int)(cpu_peek_reg(&vm->cpu,REG_ACC)));
        printf("REG_IP: %d\n",(int)(cpu_peek_ip(&vm->cpu)));
        printf("REG_SP: %d\n",(int)(cpu_peek_reg(&vm->cpu,REG_SP)));

        uint8_t m0 = memory_read(&vm->memory, 0);
        uint8_t m1 = memory_read(&vm->memory, 1);
        uint8_t m2 = memory_read(&vm->memory, 2);

        printf("Memory:[%d,%d,%d]\n", m0, m1, m2);

        uint8_t fq0 = cpu_peek_fetch_queue(&vm->cpu, 0);
        uint8_t fq1 = cpu_peek_fetch_queue(&vm->cpu, 1);
        uint8_t fq2 = cpu_peek_fetch_queue(&vm->cpu, 2);
        uint8_t fq3 = cpu_peek_fetch_queue(&vm->cpu, 3);
        uint8_t fq4 = cpu_peek_fetch_queue(&vm->cpu, 4);
        uint8_t fq5 = cpu_peek_fetch_queue(&vm->cpu, 5);
        printf("Fetch Queue:[%d,%d,%d,%d,%d,%d]\n", fq0, fq1, fq2, fq3, fq4, fq5);

        printf("Head: %d\n",cpu_fq_head(&vm->cpu));
        printf("Tails: %d\n",cpu_fq_tail(&vm->cpu));
        printf("CPU-State: %d\n",vm->cpu.running);

        vm_update(vm,0.016f);
        getchar();
    }
    return 0;
}