/* AUTOGENERATED FILE. DO NOT EDIT. */

//=======Test Runner Used To Run Each Test Below=====
#define RUN_TEST(TestFunc, TestLineNum) \
{ \
  Unity.CurrentTestName = #TestFunc; \
  Unity.CurrentTestLineNumber = TestLineNum; \
  Unity.NumberOfTests++; \
  if (TEST_PROTECT()) \
  { \
      CMock_Init(); \
      setUp(); \
      TestFunc(); \
      CMock_Verify(); \
  } \
  CMock_Destroy(); \
  if (TEST_PROTECT() && !TEST_IS_IGNORED) \
  { \
    tearDown(); \
  } \
  UnityConcludeTest(); \
}

//=======Automagically Detected Files To Include=====
#include "unity.h"
#include "cmock.h"
#include <setjmp.h>
#include <stdio.h>
#include "mock_Packet.h"
#include "mock_congestionWindow.h"

int GlobalExpectCount;
int GlobalVerifyOrder;
char* GlobalOrderError;

//=======External Functions This Runner Calls=====
extern void setUp(void);
extern void tearDown(void);
extern void test_get_and_send_1_segment_of_data_to_receiver_after_return_ack_increment_size_and_offset(void);


//=======Mock Management=====
static void CMock_Init(void)
{
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
  GlobalOrderError = NULL;
  mock_Packet_Init();
  mock_congestionWindow_Init();
}
static void CMock_Verify(void)
{
  mock_Packet_Verify();
  mock_congestionWindow_Verify();
}
static void CMock_Destroy(void)
{
  mock_Packet_Destroy();
  mock_congestionWindow_Destroy();
}

//=======Test Reset Option=====
void resetTest()
{
  CMock_Verify();
  CMock_Destroy();
  tearDown();
  CMock_Init();
  setUp();
}


//=======MAIN=====
int main(void)
{
  Unity.TestFile = "test_SlowStart.c";
  UnityBegin();
  RUN_TEST(test_get_and_send_1_segment_of_data_to_receiver_after_return_ack_increment_size_and_offset, 12);

  return (UnityEnd());
}
