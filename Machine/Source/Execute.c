#include "Execute.h"
#include "Decode.h"
#include "ISA.h"
#include "Math.h"

#include <stdio.h>

void execute_step(CPU *cpu,Memory *memory,uint8_t status) {

    if (!cpu->initialized||
        !memory->initialized||
        status == OPCODE_INVALID||
        status == OPCODE_INCOMPLETE) return;

    printf("status: %d\n",status);

    uint8_t opcode = consume(cpu);
    uint8_t reg_source;
    uint8_t reg_dest;
    uint8_t imm;
    uint8_t address;
    switch (opcode)
    {
    case OPCODE_MOV_REG_IMM:

        reg_dest = consume(cpu);
        imm = consume(cpu);
        
        cpu_load_reg(cpu,reg_dest,imm);

        break;
    
    case OPCODE_MOV_REG_REG:

        reg_dest = consume(cpu);
        reg_source = consume(cpu);
        
        cpu_load_reg(cpu,reg_dest,cpu_peek_reg(cpu,reg_source));

        break;

    case OPCODE_ADD_REG_IMM:
        reg_dest = consume(cpu);
        imm = consume(cpu);

        cpu_load_reg(cpu, reg_dest, cpu_peek_reg(cpu,reg_dest) + imm);

        break;

    case OPCODE_ADD_REG_REG:
        reg_dest = consume(cpu);
        reg_source = consume(cpu);

        cpu_load_reg(cpu, reg_dest, cpu_peek_reg(cpu,reg_dest) + cpu_peek_reg(cpu,reg_source));

        break;

    case OPCODE_SUB_REG_IMM:
        reg_dest = consume(cpu);
        imm = consume(cpu);

        cpu_load_reg(cpu, reg_dest, cpu_peek_reg(cpu,reg_dest) - imm);

        break;

    case OPCODE_SUB_REG_REG:
        reg_dest = consume(cpu);
        reg_source = consume(cpu);

        cpu_load_reg(cpu, reg_dest, cpu_peek_reg(cpu,reg_dest) - cpu_peek_reg(cpu,reg_source));

        break;

    case OPCODE_AND_REG_IMM:
        reg_dest = consume(cpu);
        imm = consume(cpu);

        cpu_load_reg(cpu, reg_dest, cpu_peek_reg(cpu,reg_dest) & imm);

        break;

    case OPCODE_AND_REG_REG:
        reg_dest = consume(cpu);
        reg_source = consume(cpu);

        cpu_load_reg(cpu, reg_dest, cpu_peek_reg(cpu,reg_dest) & cpu_peek_reg(cpu,reg_source));

        break;

    case OPCODE_OR_REG_IMM:
        reg_dest = consume(cpu);
        imm = consume(cpu);

        cpu_load_reg(cpu, reg_dest, cpu_peek_reg(cpu,reg_dest) | imm);

        break;


    case OPCODE_OR_REG_REG:
        reg_dest = consume(cpu);
        reg_source = consume(cpu);

        cpu_load_reg(cpu, reg_dest, cpu_peek_reg(cpu,reg_dest) | cpu_peek_reg(cpu,reg_source));

        break;

    case OPCODE_XOR_REG_IMM:
        reg_dest = consume(cpu);
        imm = consume(cpu);

        cpu_load_reg(cpu, reg_dest, xOR(cpu_peek_reg(cpu,reg_source),imm) ) ;

        break;


    case OPCODE_XOR_REG_REG:
        reg_dest = consume(cpu);
        reg_source = consume(cpu);

        cpu_load_reg(cpu, reg_dest, xOR(cpu_peek_reg(cpu,reg_source),cpu_peek_reg(cpu,reg_dest))) ;

        break;


    case OPCODE_PUSH_IMM:
        imm = consume(cpu);
        cpu->sp++;
        address = cpu->sp;
        if (address >= MEMORY_SIZE) break;
        memory->data[address] = imm;
        break;

    case OPCODE_PUSH_REG:
        reg_source = consume(cpu);
        cpu->sp++;
        address = cpu->sp;
        if (address >= MEMORY_SIZE) break;
        memory->data[address] = cpu_peek_reg(cpu,reg_source);
        break;

    case OPCODE_POP_REG:
        reg_dest = consume(cpu);
        address = cpu->sp;
        if (address >= MEMORY_SIZE) break;
        cpu_load_reg(cpu,reg_dest,memory->data[address]);
        cpu->sp--;
        break;


    case OPCODE_PASS:

        break;


        
    case OPCODE_HALT:

        cpu_stop(cpu);

        break;

    default:
        break;
    }

}


int16_t consume(CPU *cpu) {

    if (!cpu->initialized) return -1;
    
    uint8_t byte = cpu_peek_fetch_queue(cpu,cpu->fqh);

    cpu_advance_fretch_queue_head(cpu,1);

    return byte;
}
