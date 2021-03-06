#include "unity.h"
#include "TxTCP.h"
#include "TCPhelper.h"
#include "mock_congestionWindow.h"
#include "mock_Packet.h"
#include "linkedList.h"

void setUp(void){}
void tearDown(void){}
Packet packet;

void test_cwndInitWindow_should_init_a_window_with_default_data(void){
  TCPSession session;
  Cwnd Window;
  session.cwnd = &Window;

  cwndInitWindow(&session);

  TEST_ASSERT_EQUAL(0,session.cwnd->offset);
  TEST_ASSERT_EQUAL(50,session.cwnd->size);
}

void test_initTCPState_should_go_to_the_slow_start_state(void){
  TCPSession session;
  TCP_state state;
  session.tcpState = &state;
  initTCPState(&session);

  TEST_ASSERT_EQUAL(SlowStart,session.tcpState->state);
}

/////////////////////////////////
// function test for Slow Start
/////////////////////////////////
/**
 *   0  _____      _____ 0
 *  50 |____|     |////| 50
 *     |    |  => |____| 100
 *     |    |     |____| 150
 *     |    |     |    |
 *     |    |     |    |
 *     |____|     |____|
 *
 *   1st congestion Window
 *   with size of 50 and offset 0
 *   after the ACK increament the window size to 100
 *   offset moved to 50
 */
void test_TxTCPSM_should_init_and_send_the_first_data_increase_WindowSize_after_ACK(void){
  TCPSession session;
  Cwnd Window;
  TCP_state state;
  session.cwnd = &Window;
  session.tcpState = &state;

  cwndInitWindow(&session);
  initTCPState(&session);
  TEST_ASSERT_EQUAL(SlowStart,session.tcpState->state);

  cwndGetBeginningOffset_ExpectAndReturn(session.cwnd,0);
  cwndGetDataBlock_ExpectAndReturn(session.cwnd,0,50,&state.ptrBlock,50);

  sendDataPacket_Expect(&packet,&session.tcpState->ptrBlock,50);
  TxTCPSM(&session,&packet);
  TEST_ASSERT_EQUAL(0,session.cwnd->offset);
  TEST_ASSERT_EQUAL(50,session.cwnd->size);
  TEST_ASSERT_EQUAL(SlowStartWaitACK,session.tcpState->state);

  cwndGetDataBlock_ExpectAndReturn(session.cwnd,50,50,&state.ptrBlock,0);
  getDataPacket_ExpectAndReturn(&packet,&receiveData,50);
  cwndIncrementWindow_ExpectAndReturn(session.cwnd,50,100);
  TxTCPSM(&session,&packet);
  TEST_ASSERT_EQUAL(50,session.cwnd->offset);
  TEST_ASSERT_EQUAL(100,session.cwnd->size);
  TEST_ASSERT_EQUAL(SlowStartWaitACK,session.tcpState->state);
}
/**
 *   0 _____       _____ 0         _____  0
 * 50 |____|      |////| 50       |////|
 *    |    |      |____| 100      |////|  100
 *    |    |      |____| 150      |____|  150
 *    |    |      |    |          |____|  200
 *    |    |  =>  |    |    =>    |____|  250
 *    |    |      |    |          |    |
 *    |    |      |    |          |    |
 *    |____|      |____|          |____|
 *
 *   1st congestion Window
 *   with size of 50 and offset 0
 *   after the ACK increament the window to 100
 *   offset moved to 50, 2nd ACK comes and increase window size by 50, to 150
 *   offset moved to 100
 */
void test_TxTCPSM_should_increase_WindowSize_after_ACK_and_offset_moved_to_100(void){
  TCPSession session;
  Cwnd Window;
  TCP_state state;
  session.cwnd = &Window;
  session.tcpState = &state;

  cwndInitWindow(&session);
  initTCPState(&session);
  TEST_ASSERT_EQUAL(SlowStart,session.tcpState->state);

  cwndGetBeginningOffset_ExpectAndReturn(session.cwnd,0);
  cwndGetDataBlock_ExpectAndReturn(session.cwnd,0,50,&state.ptrBlock,50);

  sendDataPacket_Expect(&packet,&session.tcpState->ptrBlock,50);
  TxTCPSM(&session,&packet);
  TEST_ASSERT_EQUAL(0,session.cwnd->offset);
  TEST_ASSERT_EQUAL(50,session.cwnd->size);
  TEST_ASSERT_EQUAL(SlowStartWaitACK,session.tcpState->state);

  cwndGetDataBlock_ExpectAndReturn(session.cwnd,50,50,&state.ptrBlock, 0);
  getDataPacket_ExpectAndReturn(&packet,&receiveData,50);
  cwndIncrementWindow_ExpectAndReturn(session.cwnd,50,100);
  TxTCPSM(&session,&packet);
  TEST_ASSERT_EQUAL(50,session.cwnd->offset);
  TEST_ASSERT_EQUAL(100,session.cwnd->size);
  TEST_ASSERT_EQUAL(SlowStartWaitACK,session.tcpState->state);

  cwndGetDataBlock_ExpectAndReturn(session.cwnd,50,50,&state.ptrBlock,50);
  sendDataPacket_Expect(&packet,&session.tcpState->ptrBlock,100);
  TxTCPSM(&session,&packet);
  TEST_ASSERT_EQUAL(50,session.cwnd->offset);
  TEST_ASSERT_EQUAL(100,session.cwnd->size);
  TEST_ASSERT_EQUAL(SlowStartWaitACK,session.tcpState->state);

  cwndGetDataBlock_ExpectAndReturn(session.cwnd,100,50,&state.ptrBlock,50);
  sendDataPacket_Expect(&packet,&session.tcpState->ptrBlock,150);
  TxTCPSM(&session,&packet);
  TEST_ASSERT_EQUAL(50,session.cwnd->offset);
  TEST_ASSERT_EQUAL(100,session.cwnd->size);
  TEST_ASSERT_EQUAL(SlowStartWaitACK,session.tcpState->state);

  cwndGetDataBlock_ExpectAndReturn(session.cwnd,150,50,&state.ptrBlock,0);
  getDataPacket_ExpectAndReturn(&packet,&receiveData,100);
  cwndIncrementWindow_ExpectAndReturn(session.cwnd,100,150);
  TxTCPSM(&session,&packet);
  TEST_ASSERT_EQUAL(100,session.cwnd->offset);
  TEST_ASSERT_EQUAL(150,session.cwnd->size);
  TEST_ASSERT_EQUAL(SlowStartWaitACK,session.tcpState->state);

}

/**
 *   0 _____       _____ 0         _____ 0         _____ 0
 * 50 |____|      |////| 50       |////|          |////|
 *    |    |      |____| 100      |////|  100     |////|
 *    |    |      |____| 150      |____|  150     |////| 150
 *    |    |      |    |          |____|  200     |____| 200
 *    |    |  =>  |    |    =>    |____|  250  => |____| 250
 *    |    |      |    |          |    |          |____| 300
 *    |    |      |    |          |    |          |____| 350
 *    |    |      |    |          |    |          |    |
 *    |____|      |____|          |____|          |____|
 *
 *   1st congestion Window
 *   with size of 50 and offset 0
 *   after the ACK increament the window to 100
 *   offset moved to 50, 2nd ACK comes and increase window size by 50, to 150
 *   offset moved to 100, 3rd ACK comes and increase window size by 50, to 200
 *   offset moved to 150
 */
void test_TxTCPSM_should_increase_WindowSize_after_third_ACK_and_offset_moved_to_150(void){
  TCPSession session;
  Cwnd Window;
  TCP_state state;
  session.cwnd = &Window;
  session.tcpState = &state;

  cwndInitWindow(&session);
  initTCPState(&session);
  TEST_ASSERT_EQUAL(SlowStart,session.tcpState->state);

  cwndGetBeginningOffset_ExpectAndReturn(session.cwnd,0);
  cwndGetDataBlock_ExpectAndReturn(session.cwnd,0,50,&state.ptrBlock,50);

  sendDataPacket_Expect(&packet,&session.tcpState->ptrBlock,50);
  TxTCPSM(&session,&packet);
  TEST_ASSERT_EQUAL(0,session.cwnd->offset);
  TEST_ASSERT_EQUAL(50,session.cwnd->size);
  TEST_ASSERT_EQUAL(SlowStartWaitACK,session.tcpState->state);

  cwndGetDataBlock_ExpectAndReturn(session.cwnd,50,50,&state.ptrBlock, 0);
  getDataPacket_ExpectAndReturn(&packet,&receiveData,50);
  cwndIncrementWindow_ExpectAndReturn(session.cwnd,50,100);
  TxTCPSM(&session,&packet);
  TEST_ASSERT_EQUAL(50,session.cwnd->offset);
  TEST_ASSERT_EQUAL(100,session.cwnd->size);
  TEST_ASSERT_EQUAL(SlowStartWaitACK,session.tcpState->state);

  cwndGetDataBlock_ExpectAndReturn(session.cwnd,50,50,&state.ptrBlock,50);
  sendDataPacket_Expect(&packet,&session.tcpState->ptrBlock,100);
  TxTCPSM(&session,&packet);
  TEST_ASSERT_EQUAL(50,session.cwnd->offset);
  TEST_ASSERT_EQUAL(100,session.cwnd->size);
  TEST_ASSERT_EQUAL(SlowStartWaitACK,session.tcpState->state);

  cwndGetDataBlock_ExpectAndReturn(session.cwnd,100,50,&state.ptrBlock,50);
  sendDataPacket_Expect(&packet,&session.tcpState->ptrBlock,150);
  TxTCPSM(&session,&packet);
  TEST_ASSERT_EQUAL(50,session.cwnd->offset);
  TEST_ASSERT_EQUAL(100,session.cwnd->size);
  TEST_ASSERT_EQUAL(SlowStartWaitACK,session.tcpState->state);

  cwndGetDataBlock_ExpectAndReturn(session.cwnd,150,50,&state.ptrBlock,0);
  getDataPacket_ExpectAndReturn(&packet,&receiveData,100);
  cwndIncrementWindow_ExpectAndReturn(session.cwnd,100,150);
  TxTCPSM(&session,&packet);
  TEST_ASSERT_EQUAL(100,session.cwnd->offset);
  TEST_ASSERT_EQUAL(150,session.cwnd->size);
  TEST_ASSERT_EQUAL(SlowStartWaitACK,session.tcpState->state);

  cwndGetDataBlock_ExpectAndReturn(session.cwnd,150,50,&state.ptrBlock,50);
  sendDataPacket_Expect(&packet,&session.tcpState->ptrBlock,200);
  TxTCPSM(&session,&packet);
  TEST_ASSERT_EQUAL(100,session.cwnd->offset);
  TEST_ASSERT_EQUAL(150,session.cwnd->size);
  TEST_ASSERT_EQUAL(SlowStartWaitACK,session.tcpState->state);

  cwndGetDataBlock_ExpectAndReturn(session.cwnd,200,50,&state.ptrBlock,50);
  sendDataPacket_Expect(&packet,&session.tcpState->ptrBlock,250);
  TxTCPSM(&session,&packet);
  TEST_ASSERT_EQUAL(100,session.cwnd->offset);
  TEST_ASSERT_EQUAL(150,session.cwnd->size);
  TEST_ASSERT_EQUAL(SlowStartWaitACK,session.tcpState->state);

  cwndGetDataBlock_ExpectAndReturn(session.cwnd,250,50,&state.ptrBlock,0);
  getDataPacket_ExpectAndReturn(&packet,&receiveData,150);
  cwndIncrementWindow_ExpectAndReturn(session.cwnd,150,200);
  TxTCPSM(&session,&packet);
  TEST_ASSERT_EQUAL(150,Window.offset);
  TEST_ASSERT_EQUAL(200,Window.size);
  TEST_ASSERT_EQUAL(SlowStartWaitACK,state.state);
}

/**
 *   0 _____       _____ 0         _____ 0         _____ 0
 * 50 |____|      |////| 50       |////|          |////|
 *    |    |      |____| 100      |////|  100     |////|
 *    |    |      |____| 150      |////|  150     |////| 150
 *    |    |      |    |          |____|  200     |////| 200
 *    |    |  =>  |    |    =>    |____|  250  => |____| 250
 *    |    |      |    |          |    |          |____| 300
 *    |    |      |    |          |    |          |____| 350
 *    |    |      |    |          |    |          |    |
 *    |____|      |____|          |____|          |____|
 *
 *   1st congestion Window
 *   with size of 50 and offset 0
 *   after the ACK increament the window to 100
 *   offset moved to 50, 2nd ACK (150) comes and increase window size by 50, to 150
 *   offset moved to 150, 3rd ACK comes and increase window size by 50, to 200
 *   offset moved to 200
 */
void test_TxTCPSM_for_ACK_out_of_order_case_receive_ACK150_instead_of_ACK100(void){
  TCPSession session;
  Cwnd Window;
  TCP_state state;
  session.cwnd = &Window;
  session.tcpState = &state;

  cwndInitWindow(&session);
  initTCPState(&session);
  TEST_ASSERT_EQUAL(SlowStart,session.tcpState->state);

  cwndGetBeginningOffset_ExpectAndReturn(session.cwnd,0);
  cwndGetDataBlock_ExpectAndReturn(session.cwnd,0,50,&state.ptrBlock,50);

  sendDataPacket_Expect(&packet,&session.tcpState->ptrBlock,50);
  TxTCPSM(&session,&packet);
  TEST_ASSERT_EQUAL(0,session.cwnd->offset);
  TEST_ASSERT_EQUAL(50,session.cwnd->size);
  TEST_ASSERT_EQUAL(SlowStartWaitACK,session.tcpState->state);

  cwndGetDataBlock_ExpectAndReturn(session.cwnd,50,50,&state.ptrBlock, 0);
  getDataPacket_ExpectAndReturn(&packet,&receiveData,50);
  cwndIncrementWindow_ExpectAndReturn(session.cwnd,50,100);
  TxTCPSM(&session,&packet);
  TEST_ASSERT_EQUAL(50,session.cwnd->offset);
  TEST_ASSERT_EQUAL(100,session.cwnd->size);
  TEST_ASSERT_EQUAL(SlowStartWaitACK,session.tcpState->state);

  cwndGetDataBlock_ExpectAndReturn(session.cwnd,50,50,&state.ptrBlock,50);
  sendDataPacket_Expect(&packet,&session.tcpState->ptrBlock,100);
  TxTCPSM(&session,&packet);
  TEST_ASSERT_EQUAL(50,session.cwnd->offset);
  TEST_ASSERT_EQUAL(100,session.cwnd->size);
  TEST_ASSERT_EQUAL(SlowStartWaitACK,session.tcpState->state);

  cwndGetDataBlock_ExpectAndReturn(session.cwnd,100,50,&state.ptrBlock,50);
  sendDataPacket_Expect(&packet,&session.tcpState->ptrBlock,150);
  TxTCPSM(&session,&packet);
  TEST_ASSERT_EQUAL(50,session.cwnd->offset);
  TEST_ASSERT_EQUAL(100,session.cwnd->size);
  TEST_ASSERT_EQUAL(SlowStartWaitACK,session.tcpState->state);

  cwndGetDataBlock_ExpectAndReturn(session.cwnd,150,50,&state.ptrBlock, 0);
  getDataPacket_ExpectAndReturn(&packet,&receiveData,150);
  cwndIncrementWindow_ExpectAndReturn(session.cwnd,100,150);
  TxTCPSM(&session,&packet);
  TEST_ASSERT_EQUAL(150,Window.offset);
  TEST_ASSERT_EQUAL(150,Window.size);
  TEST_ASSERT_EQUAL(SlowStartWaitACK,state.state);

  cwndGetDataBlock_ExpectAndReturn(session.cwnd,150,50,&state.ptrBlock,50);
  sendDataPacket_Expect(&packet,&session.tcpState->ptrBlock,200);
  TxTCPSM(&session,&packet);
  TEST_ASSERT_EQUAL(150,Window.offset);
  TEST_ASSERT_EQUAL(150,Window.size);
  TEST_ASSERT_EQUAL(SlowStartWaitACK,state.state);

  cwndGetDataBlock_ExpectAndReturn(session.cwnd,200,50,&state.ptrBlock,50);
  sendDataPacket_Expect(&packet,&session.tcpState->ptrBlock,250);
  TxTCPSM(&session,&packet);
  TEST_ASSERT_EQUAL(150,Window.offset);
  TEST_ASSERT_EQUAL(150,Window.size);
  TEST_ASSERT_EQUAL(SlowStartWaitACK,state.state);

  cwndGetDataBlock_ExpectAndReturn(&Window,250,50,&state.ptrBlock,0);
  getDataPacket_ExpectAndReturn(&packet,&receiveData,200);
  cwndIncrementWindow_ExpectAndReturn(&Window,150,200);//
  TxTCPSM(&session,&packet);
  TEST_ASSERT_EQUAL(200,Window.offset);
  TEST_ASSERT_EQUAL(200,Window.size);
  TEST_ASSERT_EQUAL(SlowStartWaitACK,state.state);
  //printf("\n END TEST");
}

//=================================
//  For not enough window size case (TxTCPSM)
//=================================
/**
 *   0  _____      _____ 0
 *  50 |____|     |////| 50
 *     |    |  => |____| 100
 *     |    |     |    |
 *     |    |     |    |
 *     |    |     |    |
 *     |____|     |____|
 *
 *   1st congestion Window
 *   with size of 50 and offset 0
 *   //fail to increase windowSize
 *   offset remain 50
 */
void test_TxTCPSM_should_return_if_the_availableSize_not_enough(void){
  TCPSession session;
  Cwnd Window;
  TCP_state state;
  session.cwnd = &Window;
  session.tcpState = &state;

  cwndInitWindow(&session);
  initTCPState(&session);
  TEST_ASSERT_EQUAL(SlowStart,session.tcpState->state);

  
  cwndGetBeginningOffset_ExpectAndReturn(session.cwnd,0);
  cwndGetDataBlock_ExpectAndReturn(session.cwnd,0,50,&state.ptrBlock,0); //mock function return 0 (no available size)
  //not available size thus no Send the packet
  TxTCPSM(&session,&packet);

  TEST_ASSERT_EQUAL(0,session.cwnd->offset);
  TEST_ASSERT_EQUAL(50,session.cwnd->size);
  TEST_ASSERT_EQUAL(SlowStart,session.tcpState->state);
}

/**
 *   0 _____       _____ 0         _____  0
 * 50 |____|      |////| 50       |////|
 *    |    |      |____| 100      |////|  100
 *    |    |      |____| 150      |____|  150
 *    |    |      |    |          |____|  200
 *    |    |  =>  |    |    =>    |    |  250
 *    |    |      |    |          |    |
 *    |    |      |    |          |    |
 *    |____|      |____|          |____|
 *
 *   1st congestion Window
 *   with size of 50 and offset 0
 *   after the ACK increament the window to 100
 *   offset moved to 50, 2nd ACK comes but is Duplicate
 *    * First time able to increase window size, but second time not
 */
void test_TxTCPSM_should_go_to_congestion_avoidance_case_if_duplicate_detected(void){
  TCPSession session;
  Cwnd Window;
  TCP_state state;
  session.cwnd = &Window;
  session.tcpState = &state;

  cwndInitWindow(&session);
  initTCPState(&session);
  TEST_ASSERT_EQUAL(SlowStart,session.tcpState->state);

  cwndGetBeginningOffset_ExpectAndReturn(session.cwnd,0);
  cwndGetDataBlock_ExpectAndReturn(session.cwnd,0,50,&state.ptrBlock,50);

  sendDataPacket_Expect(&packet,&session.tcpState->ptrBlock,50);
  TxTCPSM(&session,&packet);
  TEST_ASSERT_EQUAL(0,session.cwnd->offset);
  TEST_ASSERT_EQUAL(50,session.cwnd->size);
  TEST_ASSERT_EQUAL(SlowStartWaitACK,session.tcpState->state);

  cwndGetDataBlock_ExpectAndReturn(session.cwnd,50,50,&state.ptrBlock, 0);
  getDataPacket_ExpectAndReturn(&packet,&receiveData,50);
  cwndIncrementWindow_ExpectAndReturn(session.cwnd,50,100);
  TxTCPSM(&session,&packet);
  TEST_ASSERT_EQUAL(50,session.cwnd->offset);
  TEST_ASSERT_EQUAL(100,session.cwnd->size);
  TEST_ASSERT_EQUAL(SlowStartWaitACK,session.tcpState->state);

  cwndGetDataBlock_ExpectAndReturn(session.cwnd,50,50,&state.ptrBlock,50);
  sendDataPacket_Expect(&packet,&session.tcpState->ptrBlock,100);
  TxTCPSM(&session,&packet);
  TEST_ASSERT_EQUAL(50,session.cwnd->offset);
  TEST_ASSERT_EQUAL(100,session.cwnd->size);
  TEST_ASSERT_EQUAL(SlowStartWaitACK,session.tcpState->state);

  cwndGetDataBlock_ExpectAndReturn(session.cwnd,100,50,&state.ptrBlock,50);
  sendDataPacket_Expect(&packet,&session.tcpState->ptrBlock,150);
  TxTCPSM(&session,&packet);
  TEST_ASSERT_EQUAL(50,session.cwnd->offset);
  TEST_ASSERT_EQUAL(100,session.cwnd->size);
  TEST_ASSERT_EQUAL(SlowStartWaitACK,session.tcpState->state);

  cwndGetDataBlock_ExpectAndReturn(session.cwnd,150,50,&state.ptrBlock, 0);
  getDataPacket_ExpectAndReturn(&packet,&receiveData,50);
  // Duplicate ACK Thus WindowSize no increase
  TxTCPSM(&session,&packet);
  TEST_ASSERT_EQUAL(50,session.cwnd->offset);
  TEST_ASSERT_EQUAL(100,session.cwnd->size); // The window Size still 100
  TEST_ASSERT_EQUAL(CongestionAvoidance,session.tcpState->state); //moved to CongestionAvoidance cases
}


/**
 *   0 _____       _____ 0         _____ 0         _____ 0
 * 50 |____|      |////| 50       |////|          |////|
 *    |    |      |____| 100      |////|  100     |////|
 *    |    |      |____| 150      |____|  150     |////| 150
 *    |    |      |    |          |____|  200     |____| 200
 *    |    |  =>  |    |    =>    |    |  250  => |____| 250
 *    |    |      |    |          |    |          |____| 300
 *    |    |      |    |          |    |          |    |
 *    |    |      |    |          |    |          |    |
 *    |____|      |____|          |____|          |____|
 *
 *   1st congestion Window
 *   with size of 50 and offset 0
 *   after the ACK increament the window to 100
 *   offset moved to 50, 2nd ACK comes but is Duplicate
 *   3rd ACK comes and increase window size by 50, to 100
 *    * First time able to increase window size, but second time not
 *    * window no increase, 3rd time ACK then window only increase by 50
 */
void test_TxTCPSM_should_go_to_congestion_avoidance_case_if_duplicate_detected_and_continue_send(void){
  TCPSession session;
  Cwnd Window;
  TCP_state state;
  session.cwnd = &Window;
  session.tcpState = &state;

  cwndInitWindow(&session);
  initTCPState(&session);
  TEST_ASSERT_EQUAL(SlowStart,session.tcpState->state);

  cwndGetBeginningOffset_ExpectAndReturn(session.cwnd,0);
  cwndGetDataBlock_ExpectAndReturn(session.cwnd,0,50,&state.ptrBlock,50);

  sendDataPacket_Expect(&packet,&session.tcpState->ptrBlock,50);
  TxTCPSM(&session,&packet);
  TEST_ASSERT_EQUAL(0,session.cwnd->offset);
  TEST_ASSERT_EQUAL(50,session.cwnd->size);
  TEST_ASSERT_EQUAL(SlowStartWaitACK,session.tcpState->state);

  cwndGetDataBlock_ExpectAndReturn(session.cwnd,50,50,&state.ptrBlock, 0);
  getDataPacket_ExpectAndReturn(&packet,&receiveData,50);
  cwndIncrementWindow_ExpectAndReturn(session.cwnd,50,100);
  TxTCPSM(&session,&packet);
  TEST_ASSERT_EQUAL(50,session.cwnd->offset);
  TEST_ASSERT_EQUAL(100,session.cwnd->size);
  TEST_ASSERT_EQUAL(SlowStartWaitACK,session.tcpState->state);

  cwndGetDataBlock_ExpectAndReturn(session.cwnd,50,50,&state.ptrBlock,50);
  sendDataPacket_Expect(&packet,&session.tcpState->ptrBlock,100);
  TxTCPSM(&session,&packet);
  TEST_ASSERT_EQUAL(50,session.cwnd->offset);
  TEST_ASSERT_EQUAL(100,session.cwnd->size);
  TEST_ASSERT_EQUAL(SlowStartWaitACK,session.tcpState->state);

  cwndGetDataBlock_ExpectAndReturn(session.cwnd,100,50,&state.ptrBlock,50);
  sendDataPacket_Expect(&packet,&session.tcpState->ptrBlock,150);
  TxTCPSM(&session,&packet);
  TEST_ASSERT_EQUAL(50,session.cwnd->offset);
  TEST_ASSERT_EQUAL(100,session.cwnd->size);
  TEST_ASSERT_EQUAL(SlowStartWaitACK,session.tcpState->state);

  cwndGetDataBlock_ExpectAndReturn(session.cwnd,150,50,&state.ptrBlock, 0);
  getDataPacket_ExpectAndReturn(&packet,&receiveData,50);
  // Duplicate ACK Thus WindowSize no increase
  TxTCPSM(&session,&packet);
  TEST_ASSERT_EQUAL(50,session.cwnd->offset);
  TEST_ASSERT_EQUAL(100,session.cwnd->size); // The Window size still 100
  TEST_ASSERT_EQUAL(CongestionAvoidance,session.tcpState->state);

  cwndGetDataBlock_ExpectAndReturn(session.cwnd,150,50,&state.ptrBlock,50);
  sendDataPacket_Expect(&packet,&session.tcpState->ptrBlock,200);
  TxTCPSM(&session,&packet);
  TEST_ASSERT_EQUAL(50,session.cwnd->offset);
  TEST_ASSERT_EQUAL(100,session.cwnd->size);

  cwndGetDataBlock_ExpectAndReturn(session.cwnd,200,50,&state.ptrBlock,50);
  sendDataPacket_Expect(&packet,&session.tcpState->ptrBlock,250);
  TxTCPSM(&session,&packet);
  TEST_ASSERT_EQUAL(50,session.cwnd->offset);
  TEST_ASSERT_EQUAL(100,session.cwnd->size);

  cwndGetDataBlock_ExpectAndReturn(session.cwnd,250,50,&state.ptrBlock, 0);
  getDataPacket_ExpectAndReturn(&packet,&receiveData,100);
  // Duplicate ACK Thus WindowSize no increase
  TxTCPSM(&session,&packet);
  TEST_ASSERT_EQUAL(100,session.cwnd->offset);
  TEST_ASSERT_EQUAL(100,session.cwnd->size);
  TEST_ASSERT_EQUAL(CongestionAvoidance,session.tcpState->state);
}

/**
 *  Send 50  -> ACK 50.  increment window to 100
 *  Send 100 -> ACK 100. increment window to 150
 *  Send 150 -> ACK 150. increment window to 200
 *  Send 200 -> ACK 200. increment window to 250
 *  Send 250 -> ACK 250. increment window to 300 (300 had over the slowstart threshold 250)
 *  Send 300
 *
 *  the size is bigger than slow start threshold, thus moved to congestion avoidance case
 */
void test_TxTCPSM_should_go_to_congestion_avoidance_case_the_size_more_than_the_ssthresh(void){
  TCPSession session;
  Cwnd Window;
  TCP_state state;
  session.cwnd = &Window;
  session.tcpState = &state;

  cwndInitWindow(&session);
  initTCPState(&session);
  TEST_ASSERT_EQUAL(SlowStart,session.tcpState->state);

  cwndGetBeginningOffset_ExpectAndReturn(session.cwnd,0);
  cwndGetDataBlock_ExpectAndReturn(session.cwnd,0,50,&state.ptrBlock,50);

  sendDataPacket_Expect(&packet,&session.tcpState->ptrBlock,50);
  TxTCPSM(&session,&packet);
  TEST_ASSERT_EQUAL(0,session.cwnd->offset);
  TEST_ASSERT_EQUAL(50,session.cwnd->size);
  TEST_ASSERT_EQUAL(SlowStartWaitACK,session.tcpState->state);

  cwndGetDataBlock_ExpectAndReturn(session.cwnd,50,50,&state.ptrBlock, 0);
  getDataPacket_ExpectAndReturn(&packet,&receiveData,50);
  cwndIncrementWindow_ExpectAndReturn(session.cwnd,50,100);
  TxTCPSM(&session,&packet);
  TEST_ASSERT_EQUAL(50,session.cwnd->offset);
  TEST_ASSERT_EQUAL(100,session.cwnd->size);
  TEST_ASSERT_EQUAL(SlowStartWaitACK,session.tcpState->state);

  cwndGetDataBlock_ExpectAndReturn(session.cwnd,50,50,&state.ptrBlock,50);
  sendDataPacket_Expect(&packet,&session.tcpState->ptrBlock,100);  //send 100
  TxTCPSM(&session,&packet);
  TEST_ASSERT_EQUAL(50,session.cwnd->offset);
  TEST_ASSERT_EQUAL(100,session.cwnd->size);
  TEST_ASSERT_EQUAL(SlowStartWaitACK,session.tcpState->state);

  cwndGetDataBlock_ExpectAndReturn(session.cwnd,100,50,&state.ptrBlock,50);
  sendDataPacket_Expect(&packet,&session.tcpState->ptrBlock,150); // send 150
  TxTCPSM(&session,&packet);
  TEST_ASSERT_EQUAL(50,session.cwnd->offset);
  TEST_ASSERT_EQUAL(100,session.cwnd->size);
  TEST_ASSERT_EQUAL(SlowStartWaitACK,session.tcpState->state);

  cwndGetDataBlock_ExpectAndReturn(session.cwnd,150,50,&state.ptrBlock, 0);
  getDataPacket_ExpectAndReturn(&packet,&receiveData,100);
  cwndIncrementWindow_ExpectAndReturn(session.cwnd,100,150);
  TxTCPSM(&session,&packet);
  TEST_ASSERT_EQUAL(100,session.cwnd->offset);
  TEST_ASSERT_EQUAL(150,session.cwnd->size);
  TEST_ASSERT_EQUAL(SlowStartWaitACK,session.tcpState->state);

  cwndGetDataBlock_ExpectAndReturn(session.cwnd,150,50,&state.ptrBlock,50);
  sendDataPacket_Expect(&packet,&session.tcpState->ptrBlock,200); // send 200
  TxTCPSM(&session,&packet);
  TEST_ASSERT_EQUAL(100,session.cwnd->offset);
  TEST_ASSERT_EQUAL(150,session.cwnd->size);

  cwndGetDataBlock_ExpectAndReturn(session.cwnd,200,50,&state.ptrBlock,50);
  sendDataPacket_Expect(&packet,&session.tcpState->ptrBlock,250); // send 250
  TxTCPSM(&session,&packet);
  TEST_ASSERT_EQUAL(100,session.cwnd->offset);
  TEST_ASSERT_EQUAL(150,session.cwnd->size);

  cwndGetDataBlock_ExpectAndReturn(session.cwnd,250,50,&state.ptrBlock,50);
  sendDataPacket_Expect(&packet,&session.tcpState->ptrBlock,300); // send 300
  TxTCPSM(&session,&packet);
  TEST_ASSERT_EQUAL(100,session.cwnd->offset);
  TEST_ASSERT_EQUAL(150,session.cwnd->size);

  cwndGetDataBlock_ExpectAndReturn(session.cwnd,300,50,&state.ptrBlock, 0);
  getDataPacket_ExpectAndReturn(&packet,&receiveData,150);    // ACK 150
  cwndIncrementWindow_ExpectAndReturn(session.cwnd,150,200);
  TxTCPSM(&session,&packet);
  TEST_ASSERT_EQUAL(150,session.cwnd->offset);
  TEST_ASSERT_EQUAL(200,session.cwnd->size);
  TEST_ASSERT_EQUAL(SlowStartWaitACK,session.tcpState->state);

  cwndGetDataBlock_ExpectAndReturn(session.cwnd,300,50,&state.ptrBlock, 0);
  getDataPacket_ExpectAndReturn(&packet,&receiveData,200);    // ACK 200
  cwndIncrementWindow_ExpectAndReturn(session.cwnd,200,250);
  TxTCPSM(&session,&packet);
  TEST_ASSERT_EQUAL(200,session.cwnd->offset);
  TEST_ASSERT_EQUAL(250,session.cwnd->size);
  TEST_ASSERT_EQUAL(SlowStartWaitACK,session.tcpState->state);

  cwndGetDataBlock_ExpectAndReturn(session.cwnd,300,50,&state.ptrBlock, 0);
  getDataPacket_ExpectAndReturn(&packet,&receiveData,250);    // ACK 250
  cwndIncrementWindow_ExpectAndReturn(session.cwnd,250,300);
  TxTCPSM(&session,&packet);
  TEST_ASSERT_EQUAL(250,session.cwnd->offset);
  TEST_ASSERT_EQUAL(300,session.cwnd->size);   // The Size over the ssthresh thus moved to congetion avoidance case
  TEST_ASSERT_EQUAL(CongestionAvoidance,session.tcpState->state);
}



