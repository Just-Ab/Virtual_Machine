#pragma once

#include <stdint.h>
#include "CPU.h"
#include "Memory.h"

#ifdef __cplusplus
extern "C" {
#endif

void fetch_step(CPU *cpu,Memory *memory);

#ifdef __cplusplus
}
#endif