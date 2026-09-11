// include/nvram_manager.h
#ifndef NVRAM_MANAGER_H
#define NVRAM_MANAGER_H

#include "nvram.h"

typedef struct {
    uint32_t uptime_seconds;
    uint16_t setting_a;
    uint16_t crc;
} __attribute__((packed)) app_state_t;

bool nvram_save_state(const nvram_driver_t *drv, uint16_t addr, const app_state_t *state);
bool nvram_load_state(const nvram_driver_t *drv, uint16_t addr, app_state_t *out_state);

#endif // NVRAM_MANAGER_H