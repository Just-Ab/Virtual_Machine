#include "Decode.h"
#include "ISA.h"

uint8_t decode_step(CPU *cpu) {

    if (!cpu->initialized) return OPCODE_INVALID;

    if (cpu->fq[cpu->fqh] == OPCODE_INVALID) return OPCODE_INVALID;

    uint8_t opcode = cpu->fq[cpu->fqh];
    uint8_t available =
        (cpu->fqt + FQ_SIZE - cpu->fqh) % FQ_SIZE;

    
    switch (opcode)
    {
    case OPCODE_MOV_REG_IMM:
        
        if (OPCODE_MOV_REG_IMM_SIZE > available) return OPCODE_INCOMPLETE;

        return OPCODE_COMPLETE;

    case OPCODE_MOV_REG_REG:
        
        if (OPCODE_MOV_REG_REG_SIZE > available) return OPCODE_INCOMPLETE;

        return OPCODE_COMPLETE;

    case OPCODE_ADD_REG_IMM:
        
        if (OPCODE_ADD_REG_IMM_SIZE > available) return OPCODE_INCOMPLETE;

        return OPCODE_COMPLETE;

    case OPCODE_ADD_REG_REG:
        
        if (OPCODE_ADD_REG_REG_SIZE > available) return OPCODE_INCOMPLETE;

        return OPCODE_COMPLETE;

    case OPCODE_SUB_REG_IMM:
        
        if (OPCODE_SUB_REG_IMM_SIZE > available) return OPCODE_INCOMPLETE;

        return OPCODE_COMPLETE;

    case OPCODE_SUB_REG_REG:
        
        if (OPCODE_SUB_REG_REG_SIZE > available) return OPCODE_INCOMPLETE;

        return OPCODE_COMPLETE;

    case OPCODE_AND_REG_IMM:
        
        if (OPCODE_AND_REG_IMM_SIZE > available) return OPCODE_INCOMPLETE;

        return OPCODE_COMPLETE;

    case OPCODE_AND_REG_REG:
        
        if (OPCODE_AND_REG_REG_SIZE > available) return OPCODE_INCOMPLETE;

        return OPCODE_COMPLETE;

    case OPCODE_OR_REG_IMM:
        
        if (OPCODE_OR_REG_IMM_SIZE > available) return OPCODE_INCOMPLETE;

        return OPCODE_COMPLETE;

    case OPCODE_OR_REG_REG:
        
        if (OPCODE_OR_REG_REG_SIZE > available) return OPCODE_INCOMPLETE;

        return OPCODE_COMPLETE;

    case OPCODE_XOR_REG_IMM:
        
        if (OPCODE_XOR_REG_IMM_SIZE > available) return OPCODE_INCOMPLETE;

        return OPCODE_COMPLETE;

    case OPCODE_XOR_REG_REG:
        
        if (OPCODE_XOR_REG_REG_SIZE > available) return OPCODE_INCOMPLETE;

        return OPCODE_COMPLETE;

    case OPCODE_PUSH_IMM:
        
        if (OPCODE_PUSH_IMM_SIZE > available) return OPCODE_INCOMPLETE;

        return OPCODE_COMPLETE;

    case OPCODE_PUSH_REG:
        
        if (OPCODE_PUSH_REG_SIZE > available) return OPCODE_INCOMPLETE;

        return OPCODE_COMPLETE;

    case OPCODE_POP_REG:
        
    if (OPCODE_POP_REG_SIZE > available ) return OPCODE_INCOMPLETE;

        return OPCODE_COMPLETE;

    case OPCODE_PASS:
        
        if (OPCODE_PASS_SIZE > available) return OPCODE_INCOMPLETE;

        return OPCODE_COMPLETE;
    
    case OPCODE_HALT:
        
        if (OPCODE_HALT_SIZE > available) return OPCODE_INCOMPLETE;

        return OPCODE_COMPLETE;

    default:
        return OPCODE_INVALID;
    }

}