#pragma once

#include <stdint.h>
#include "CPU.h"
#include "Memory.h"

#ifdef __cplusplus
extern "C" {
#endif

struct CPU;
struct Memory;

void execute_step(CPU *cpu,Memory *memory,uint8_t status);
int16_t consume(CPU *cpu);

#ifdef __cplusplus
}
#endif