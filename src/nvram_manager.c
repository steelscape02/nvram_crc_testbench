// src/nvram_manager.c
#include "nvram_manager.h"
#include "crc.h"
#include <stddef.h>

bool nvram_save_state(const nvram_driver_t *drv, uint16_t addr, const app_state_t *state) {
    if (!drv || !drv->write || !state) return false;

    app_state_t state_to_write = *state;
    // Calculate CRC over payload excluding the CRC field itself
    size_t payload_len = offsetof(app_state_t, crc);
    state_to_write.crc = crc_ccitt((const uint8_t *)&state_to_write, payload_len);

    return drv->write(addr, (const uint8_t *)&state_to_write, sizeof(app_state_t));
}

bool nvram_load_state(const nvram_driver_t *drv, uint16_t addr, app_state_t *out_state) {
    if (!drv || !drv->read || !out_state) return false;

    app_state_t loaded;
    if (!drv->read(addr, (uint8_t *)&loaded, sizeof(app_state_t))) {
        return false;
    }

    size_t payload_len = offsetof(app_state_t, crc);
    uint16_t calculated_crc = crc_ccitt((const uint8_t *)&loaded, payload_len);

    if (calculated_crc != loaded.crc) {
        return false; // CRC mismatch / corrupted write
    }

    *out_state = loaded;
    return true;
}