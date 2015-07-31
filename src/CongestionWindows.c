#include <stdio.h>
#include <stdint.h>
#include "TxTCP.h"
#include "CongestionWindows.h"
#include "Packet.h"

uint32_t cwndGetBeginningOffsets(Cwnd *cwnd){
  return cwnd->offset;
}

uint32_t cwndIncrementWindows(Cwnd *cwnd, uint32_t size){
  
  uint32_t windowSize;
  
  windowSize = cwnd->size + SMSS;
  
  return windowSize;
}

uint32_t cwndGetDataBlocks(Cwnd *cwnd, uint32_t offset, uint32_t requestedSize, uint8_t **block){
  uint32_t availableSize;
  uint32_t Offset = cwnd->offset;
  uint32_t Size = cwnd->size;
  uint32_t *Block = &Size;
  // uint32_t *Blocksize = (uint32_t*)(&(*block));
     
  if (((Size - requestedSize) < Size) && (Offset - offset == 0)){
  
    availableSize = requestedSize;
    
    return availableSize;
  }
  return 0;
}

