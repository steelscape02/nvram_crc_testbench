// include/crc.h
#ifndef CRC_H
#define CRC_H

#include <stdint.h>
#include <stddef.h>

uint16_t crc_ccitt(const uint8_t *data, size_t length);

#endif // CRC_H