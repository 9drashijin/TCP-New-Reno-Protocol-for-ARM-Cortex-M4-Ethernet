#ifndef CONGESTION_WINDOW_H
#define CONGESTION_WINDOW_H

#include "SlowStart.h"

uint32_t cwndGetBeginningOffsets(Cwnd *cwnd);
uint32_t cwndIncrementWindows(Cwnd *cwnd, uint32_t size);
uint32_t cwndGetDataBlocks(Cwnd *cwnd, uint32_t offset, uint32_t requestedSize, uint8_t **block);

#endif // CONGESTION_WINDOW_H