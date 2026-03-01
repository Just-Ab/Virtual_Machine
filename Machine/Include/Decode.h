#pragma once

#include <stdint.h>
#include "CPU.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef uint8_t OPCODE;

struct CPU;

uint8_t decode_step(CPU *cpu);

#ifdef __cplusplus
}
#endif