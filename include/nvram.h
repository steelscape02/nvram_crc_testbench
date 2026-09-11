// include/nvram.h
#ifndef NVRAM_H
#define NVRAM_H

#include <stdint.h>
#include <stdbool.h>

typedef bool (*nvram_read_fn)(uint16_t addr, uint8_t *data, uint16_t len);
typedef bool (*nvram_write_fn)(uint16_t addr, const uint8_t *data, uint16_t len);

typedef struct {
    nvram_read_fn read;
    nvram_write_fn write;
} nvram_driver_t;

#endif // NVRAM_H