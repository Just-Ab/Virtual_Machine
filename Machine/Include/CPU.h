#pragma once

#include <stdint.h>
#include "ISA.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    /*
    Registers
    */
    uint8_t ip;
    uint8_t si;
    uint8_t ac;
    uint8_t se;
    uint8_t sp;
    uint8_t bp;

    /*
    Fetch Queue
    */
    uint8_t fq[6];
    uint8_t fqs[6];
    uint8_t fqh;
    uint8_t fqt;
    
    /*
    Control
    */
    float step_time;

    /*
    Flag
    */
    int initialized;
    int running;

}CPU;

#define INVALID 0X00
#define VALID 0XFF

#define FQ_SIZE 6

struct Memory;


void cpu_init(CPU *cpu);
void cpu_run(CPU *cpu);
void cpu_step(CPU *cpu, struct Memory *memory);
void cpu_stop(CPU *cpu);

void cpu_advance_ip(CPU *cpu);
uint8_t cpu_peek_ip(CPU *cpu);

int8_t cpu_append_fetch_queue(CPU *cpu,uint8_t value);
uint8_t cpu_peek_fetch_queue(CPU *cpu,uint8_t index);
void cpu_advance_fretch_queue_head(CPU *cpu,uint8_t length);
void cpu_advance_fretch_queue_tail(CPU *cpu,uint8_t length);

uint8_t cpu_fq_head(const CPU *cpu);
uint8_t cpu_fq_tail(const CPU *cpu);
uint8_t cpu_fq_size(const CPU *cpu);
uint8_t cpu_fq_full(const CPU *cpu);


void cpu_load_reg(CPU *cpu,uint8_t reg,uint8_t value);
uint8_t cpu_peek_reg(CPU *cpu,uint8_t reg);


#ifdef __cplusplus
}
#endif