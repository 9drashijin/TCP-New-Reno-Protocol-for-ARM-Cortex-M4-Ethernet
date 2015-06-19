/* AUTOGENERATED FILE. DO NOT EDIT. */
#include <string.h>
#include <stdlib.h>
#include <setjmp.h>
#include "unity.h"
#include "cmock.h"
#include "mock_timeOutTimer.h"

typedef struct _CMOCK_countTimer_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  int ReturnVal;
  int CallOrder;

} CMOCK_countTimer_CALL_INSTANCE;

static struct mock_timeOutTimerInstance
{
  int countTimer_IgnoreBool;
  int countTimer_FinalReturn;
  CMOCK_countTimer_CALLBACK countTimer_CallbackFunctionPointer;
  int countTimer_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE countTimer_CallInstance;
} Mock;

extern jmp_buf AbortFrame;
extern int GlobalExpectCount;
extern int GlobalVerifyOrder;

void mock_timeOutTimer_Verify(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  if (Mock.countTimer_IgnoreBool)
    Mock.countTimer_CallInstance = CMOCK_GUTS_NONE;
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.countTimer_CallInstance, cmock_line, "Function 'countTimer' called less times than expected.");
  if (Mock.countTimer_CallbackFunctionPointer != NULL)
    Mock.countTimer_CallInstance = CMOCK_GUTS_NONE;
}

void mock_timeOutTimer_Init(void)
{
  mock_timeOutTimer_Destroy();
}

void mock_timeOutTimer_Destroy(void)
{
  CMock_Guts_MemFreeAll();
  memset(&Mock, 0, sizeof(Mock));
  Mock.countTimer_CallbackFunctionPointer = NULL;
  Mock.countTimer_CallbackCalls = 0;
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
}

int countTimer(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_countTimer_CALL_INSTANCE* cmock_call_instance = (CMOCK_countTimer_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.countTimer_CallInstance);
  Mock.countTimer_CallInstance = CMock_Guts_MemNext(Mock.countTimer_CallInstance);
  if (Mock.countTimer_IgnoreBool)
  {
    if (cmock_call_instance == NULL)
      return Mock.countTimer_FinalReturn;
    Mock.countTimer_FinalReturn = cmock_call_instance->ReturnVal;
    return cmock_call_instance->ReturnVal;
  }
  if (Mock.countTimer_CallbackFunctionPointer != NULL)
  {
    return Mock.countTimer_CallbackFunctionPointer(Mock.countTimer_CallbackCalls++);
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "Function 'countTimer' called more times than expected.");
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, "Function 'countTimer' called earlier than expected.");
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, "Function 'countTimer' called later than expected.");
  return cmock_call_instance->ReturnVal;
}

void countTimer_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, int cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_countTimer_CALL_INSTANCE));
  CMOCK_countTimer_CALL_INSTANCE* cmock_call_instance = (CMOCK_countTimer_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "CMock has run out of memory. Please allocate more.");
  Mock.countTimer_CallInstance = CMock_Guts_MemChain(Mock.countTimer_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ReturnVal = cmock_to_return;
  Mock.countTimer_IgnoreBool = (int)1;
}

void countTimer_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, int cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_countTimer_CALL_INSTANCE));
  CMOCK_countTimer_CALL_INSTANCE* cmock_call_instance = (CMOCK_countTimer_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "CMock has run out of memory. Please allocate more.");
  Mock.countTimer_CallInstance = CMock_Guts_MemChain(Mock.countTimer_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  cmock_call_instance->ReturnVal = cmock_to_return;
}

void countTimer_StubWithCallback(CMOCK_countTimer_CALLBACK Callback)
{
  Mock.countTimer_CallbackFunctionPointer = Callback;
}

