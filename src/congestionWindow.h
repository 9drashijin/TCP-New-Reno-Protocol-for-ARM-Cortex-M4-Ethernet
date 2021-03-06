#ifndef CONGESTION_WINDOW_H
#define CONGESTION_WINDOW_H

#include "TxTCP.h"

uint32_t cwndGetBeginningOffset(Cwnd *cwnd);
uint32_t cwndIncrementWindow(Cwnd *cwnd, uint32_t size);
uint32_t cwndGetDataBlock(Cwnd *cwnd, uint32_t offset, uint32_t requestedSize, uint8_t **block);
uint32_t cwndGetSSthresh(Cwnd *cwnd);
#endif // CONGESTION_WINDOW_H

