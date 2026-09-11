// tests/mock_nvram.c
#include "mock_nvram.h"
#include <string.h>

#define MOCK_SIZE 1024
static uint8_t memory_buffer[MOCK_SIZE];

static bool mock_read(uint16_t addr, uint8_t *data, uint16_t len) {
    if (addr + len > MOCK_SIZE) return false;
    memcpy(data, &memory_buffer[addr], len);
    return true;
}

static bool mock_write(uint16_t addr, const uint8_t *data, uint16_t len) {
    if (addr + len > MOCK_SIZE) return false;
    memcpy(&memory_buffer[addr], data, len);
    return true;
}

static const nvram_driver_t mock_driver = {
    .read = mock_read,
    .write = mock_write
};

void mock_nvram_init(void) {
    memset(memory_buffer, 0xFF, MOCK_SIZE);
}

void mock_nvram_corrupt_byte(uint16_t addr, uint8_t mask) {
    if (addr < MOCK_SIZE) {
        memory_buffer[addr] ^= mask;
    }
}

const nvram_driver_t *mock_nvram_get_driver(void) {
    return &mock_driver;
}