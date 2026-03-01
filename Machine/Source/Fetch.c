#include "Fetch.h"




void fetch_step(CPU *cpu,Memory *memory) {

    if (!cpu->initialized || !memory->initialized) return ;

    uint8_t ip = cpu_peek_ip(cpu);
    uint8_t byte = memory_read(memory,ip);

    if (cpu_append_fetch_queue(cpu,byte) == 0) {

        cpu_advance_ip(cpu);

    }
}
