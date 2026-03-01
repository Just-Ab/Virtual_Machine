#include "CPU.h"
#include <stdio.h>
void cpu_init(CPU *cpu) {

    cpu->ip = 0;
    cpu->si = 0;
    cpu->ac = 0;
    cpu->se = 0;
    cpu->sp = 0;
    cpu->bp = 0;

    cpu->fq[0] = 0xFF;
    for (size_t i = 1; i < 6; i++)
    {
        cpu->fq[i] = 0x00;
    }
    for (size_t i = 0; i < 6; i++)
    {
        cpu->fqs[i] = INVALID;
    }

    cpu->fqh = 0;
    cpu->fqt = 0;

    cpu->initialized = 1;
    cpu->running = 0;
}

void cpu_run(CPU *cpu) {

    if (!cpu->initialized) return;

    cpu->running = 1;
}

void cpu_step(CPU *cpu, struct Memory *memory) {

    

}

void cpu_stop(CPU *cpu) {

    cpu->running = 0;

}

void cpu_advance_ip(CPU *cpu) {

    if (!cpu->initialized) return ;

    cpu->ip = (cpu->ip + 1) % INT8_MAX;

}

uint8_t cpu_peek_ip(CPU *cpu) {

    if (!cpu->initialized) return 0;

    return cpu->ip;

}

int8_t cpu_append_fetch_queue(CPU *cpu,uint8_t value) {

    if (!cpu->initialized) return -1;

    if (cpu->fqh == ((cpu->fqt + 1) % FQ_SIZE)) return -1;

    cpu_advance_fretch_queue_tail(cpu,1);
    cpu->fq[cpu->fqt] = value;


    return 0;
}


uint8_t cpu_peek_fetch_queue(CPU *cpu,uint8_t index) {

    if (!cpu->initialized) return 0;

    if (index >= FQ_SIZE) return 0;

    return cpu->fq[index];
}

void cpu_advance_fretch_queue_head(CPU *cpu,uint8_t length) {

    if (!cpu->initialized) return;

    cpu->fqh = (cpu->fqh + length) % FQ_SIZE;

}

void cpu_advance_fretch_queue_tail(CPU *cpu,uint8_t length) {

    if (!cpu->initialized) return;

    cpu->fqt = (cpu->fqt + length) % FQ_SIZE;

}

uint8_t cpu_fq_head(const CPU *cpu) {
    
    return cpu->fqh;
}

uint8_t cpu_fq_tail(const CPU *cpu) {
    
    return cpu->fqt;
}

uint8_t cpu_fq_size(const CPU *cpu) {

    if (cpu->fqt >= cpu->fqh) return cpu->fqt - cpu->fqh;
    
    return FQ_SIZE - cpu->fqh + cpu->fqt;
}

uint8_t cpu_fq_full(const CPU *cpu) {
    
    return ((cpu->fqt + 1) % FQ_SIZE) == cpu->fqh;
}


void cpu_load_reg(CPU *cpu,uint8_t reg,uint8_t value) {

    if (!cpu->initialized) return;

    switch (reg)
    {
    case REG_ACC:
        cpu->ac = value;
        break;
    
    case REG_SEC:
        cpu->se = value;
        break;

    case REG_IP:
        cpu->ip = value;
        printf("Loaded IP");
        break;

    case REG_SI:
        cpu->si = value;
        break;

    case REG_SP:
        cpu->sp = value;
        break;

    default:
        break;
    }

}


uint8_t cpu_peek_reg(CPU *cpu,uint8_t reg) {

    if (!cpu->initialized) return 0;

    switch (reg)
    {
    case REG_ACC:
        return cpu->ac;
        break;
    
    case REG_SEC:
        return cpu->se;
        break;

    case REG_IP:
        return cpu->ip;
        break;

    case REG_SI:
        return cpu->si;
        break;

    case REG_SP:
        return cpu->sp;
        break;

    default:
        break;
    }
    return 0;
}


