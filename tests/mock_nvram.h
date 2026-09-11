// tests/mock_nvram.h
#ifndef MOCK_NVRAM_H
#define MOCK_NVRAM_H

#include "nvram.h"

void mock_nvram_init(void);
void mock_nvram_corrupt_byte(uint16_t addr, uint8_t mask);
const nvram_driver_t *mock_nvram_get_driver(void);

#endif // MOCK_NVRAM_H