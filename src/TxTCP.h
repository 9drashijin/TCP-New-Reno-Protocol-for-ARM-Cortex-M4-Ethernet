#ifndef TXTCP_H
#define TXTCP_H

#include <stdint.h>

#define SMSS 50  // (SMSS) SENDER MAXIMUM SEGMENT SIZE
#define ssthres 250 // slow start threshold

extern uint8_t Buffer[1000];
extern uint8_t *receiveData;

typedef enum{
	SlowStart,
	SlowStartWaitACK,
  CongestionAvoidance,
	FastRetransmit,
  FastRecovery,
  TimeOut
}State;

typedef struct{
	State state;
  uint8_t *ptrBlock;
}TCP_state;

typedef struct{
	uint32_t offset;
	uint32_t size;
  uint32_t dupACKFlag;
  uint32_t ssthresh;
  uint32_t recover;
  uint32_t flightSize;
  uint32_t lostPacket;
}Cwnd; // CONGESTION WINDOW

typedef struct{
  uint32_t srcIpAddr;
  uint32_t destIpAddr;
  uint32_t SeqNum;
  uint32_t AckNum;
  uint8_t data;
}Packet;

void cwndInitWindow(Cwnd *cwnd);
void initTCPState(TCP_state *state);
void initPacket(Packet *packet);
uint32_t TxTCPSM(TCP_state *state, Cwnd *cwnd, Packet *packet);

#endif // TXTCP_H
