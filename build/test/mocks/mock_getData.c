/* AUTOGENERATED FILE. DO NOT EDIT. */
#include <string.h>
#include <stdlib.h>
#include <setjmp.h>
#include "unity.h"
#include "cmock.h"
#include "mock_getData.h"

typedef struct _CMOCK_getBufferSize_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  int ReturnVal;
  int CallOrder;

} CMOCK_getBufferSize_CALL_INSTANCE;

typedef struct _CMOCK_sendData_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  int ReturnVal;
  int CallOrder;

} CMOCK_sendData_CALL_INSTANCE;

typedef struct _CMOCK_recieveRxACK_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  int ReturnVal;
  int CallOrder;

} CMOCK_recieveRxACK_CALL_INSTANCE;

typedef struct _CMOCK_sequenceNumber_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  int ReturnVal;
  int CallOrder;

} CMOCK_sequenceNumber_CALL_INSTANCE;

typedef struct _CMOCK_rxSlowStart_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  int ReturnVal;
  int CallOrder;

} CMOCK_rxSlowStart_CALL_INSTANCE;

typedef struct _CMOCK_indexSeqNumber_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  int ReturnVal;
  int CallOrder;

} CMOCK_indexSeqNumber_CALL_INSTANCE;

typedef struct _CMOCK_datalength_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  int ReturnVal;
  int CallOrder;

} CMOCK_datalength_CALL_INSTANCE;

static struct mock_getDataInstance
{
  int getBufferSize_IgnoreBool;
  int getBufferSize_FinalReturn;
  CMOCK_getBufferSize_CALLBACK getBufferSize_CallbackFunctionPointer;
  int getBufferSize_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE getBufferSize_CallInstance;
  int sendData_IgnoreBool;
  int sendData_FinalReturn;
  CMOCK_sendData_CALLBACK sendData_CallbackFunctionPointer;
  int sendData_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE sendData_CallInstance;
  int recieveRxACK_IgnoreBool;
  int recieveRxACK_FinalReturn;
  CMOCK_recieveRxACK_CALLBACK recieveRxACK_CallbackFunctionPointer;
  int recieveRxACK_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE recieveRxACK_CallInstance;
  int sequenceNumber_IgnoreBool;
  int sequenceNumber_FinalReturn;
  CMOCK_sequenceNumber_CALLBACK sequenceNumber_CallbackFunctionPointer;
  int sequenceNumber_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE sequenceNumber_CallInstance;
  int rxSlowStart_IgnoreBool;
  int rxSlowStart_FinalReturn;
  CMOCK_rxSlowStart_CALLBACK rxSlowStart_CallbackFunctionPointer;
  int rxSlowStart_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE rxSlowStart_CallInstance;
  int indexSeqNumber_IgnoreBool;
  int indexSeqNumber_FinalReturn;
  CMOCK_indexSeqNumber_CALLBACK indexSeqNumber_CallbackFunctionPointer;
  int indexSeqNumber_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE indexSeqNumber_CallInstance;
  int datalength_IgnoreBool;
  int datalength_FinalReturn;
  CMOCK_datalength_CALLBACK datalength_CallbackFunctionPointer;
  int datalength_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE datalength_CallInstance;
} Mock;

extern jmp_buf AbortFrame;
extern int GlobalExpectCount;
extern int GlobalVerifyOrder;

void mock_getData_Verify(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  if (Mock.getBufferSize_IgnoreBool)
    Mock.getBufferSize_CallInstance = CMOCK_GUTS_NONE;
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.getBufferSize_CallInstance, cmock_line, "Function 'getBufferSize' called less times than expected.");
  if (Mock.getBufferSize_CallbackFunctionPointer != NULL)
    Mock.getBufferSize_CallInstance = CMOCK_GUTS_NONE;
  if (Mock.sendData_IgnoreBool)
    Mock.sendData_CallInstance = CMOCK_GUTS_NONE;
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.sendData_CallInstance, cmock_line, "Function 'sendData' called less times than expected.");
  if (Mock.sendData_CallbackFunctionPointer != NULL)
    Mock.sendData_CallInstance = CMOCK_GUTS_NONE;
  if (Mock.recieveRxACK_IgnoreBool)
    Mock.recieveRxACK_CallInstance = CMOCK_GUTS_NONE;
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.recieveRxACK_CallInstance, cmock_line, "Function 'recieveRxACK' called less times than expected.");
  if (Mock.recieveRxACK_CallbackFunctionPointer != NULL)
    Mock.recieveRxACK_CallInstance = CMOCK_GUTS_NONE;
  if (Mock.sequenceNumber_IgnoreBool)
    Mock.sequenceNumber_CallInstance = CMOCK_GUTS_NONE;
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.sequenceNumber_CallInstance, cmock_line, "Function 'sequenceNumber' called less times than expected.");
  if (Mock.sequenceNumber_CallbackFunctionPointer != NULL)
    Mock.sequenceNumber_CallInstance = CMOCK_GUTS_NONE;
  if (Mock.rxSlowStart_IgnoreBool)
    Mock.rxSlowStart_CallInstance = CMOCK_GUTS_NONE;
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.rxSlowStart_CallInstance, cmock_line, "Function 'rxSlowStart' called less times than expected.");
  if (Mock.rxSlowStart_CallbackFunctionPointer != NULL)
    Mock.rxSlowStart_CallInstance = CMOCK_GUTS_NONE;
  if (Mock.indexSeqNumber_IgnoreBool)
    Mock.indexSeqNumber_CallInstance = CMOCK_GUTS_NONE;
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.indexSeqNumber_CallInstance, cmock_line, "Function 'indexSeqNumber' called less times than expected.");
  if (Mock.indexSeqNumber_CallbackFunctionPointer != NULL)
    Mock.indexSeqNumber_CallInstance = CMOCK_GUTS_NONE;
  if (Mock.datalength_IgnoreBool)
    Mock.datalength_CallInstance = CMOCK_GUTS_NONE;
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.datalength_CallInstance, cmock_line, "Function 'datalength' called less times than expected.");
  if (Mock.datalength_CallbackFunctionPointer != NULL)
    Mock.datalength_CallInstance = CMOCK_GUTS_NONE;
}

void mock_getData_Init(void)
{
  mock_getData_Destroy();
}

void mock_getData_Destroy(void)
{
  CMock_Guts_MemFreeAll();
  memset(&Mock, 0, sizeof(Mock));
  Mock.getBufferSize_CallbackFunctionPointer = NULL;
  Mock.getBufferSize_CallbackCalls = 0;
  Mock.sendData_CallbackFunctionPointer = NULL;
  Mock.sendData_CallbackCalls = 0;
  Mock.recieveRxACK_CallbackFunctionPointer = NULL;
  Mock.recieveRxACK_CallbackCalls = 0;
  Mock.sequenceNumber_CallbackFunctionPointer = NULL;
  Mock.sequenceNumber_CallbackCalls = 0;
  Mock.rxSlowStart_CallbackFunctionPointer = NULL;
  Mock.rxSlowStart_CallbackCalls = 0;
  Mock.indexSeqNumber_CallbackFunctionPointer = NULL;
  Mock.indexSeqNumber_CallbackCalls = 0;
  Mock.datalength_CallbackFunctionPointer = NULL;
  Mock.datalength_CallbackCalls = 0;
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
}

int getBufferSize(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_getBufferSize_CALL_INSTANCE* cmock_call_instance = (CMOCK_getBufferSize_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.getBufferSize_CallInstance);
  Mock.getBufferSize_CallInstance = CMock_Guts_MemNext(Mock.getBufferSize_CallInstance);
  if (Mock.getBufferSize_IgnoreBool)
  {
    if (cmock_call_instance == NULL)
      return Mock.getBufferSize_FinalReturn;
    Mock.getBufferSize_FinalReturn = cmock_call_instance->ReturnVal;
    return cmock_call_instance->ReturnVal;
  }
  if (Mock.getBufferSize_CallbackFunctionPointer != NULL)
  {
    return Mock.getBufferSize_CallbackFunctionPointer(Mock.getBufferSize_CallbackCalls++);
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "Function 'getBufferSize' called more times than expected.");
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, "Function 'getBufferSize' called earlier than expected.");
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, "Function 'getBufferSize' called later than expected.");
  return cmock_call_instance->ReturnVal;
}

void getBufferSize_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, int cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_getBufferSize_CALL_INSTANCE));
  CMOCK_getBufferSize_CALL_INSTANCE* cmock_call_instance = (CMOCK_getBufferSize_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "CMock has run out of memory. Please allocate more.");
  Mock.getBufferSize_CallInstance = CMock_Guts_MemChain(Mock.getBufferSize_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ReturnVal = cmock_to_return;
  Mock.getBufferSize_IgnoreBool = (int)1;
}

void getBufferSize_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, int cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_getBufferSize_CALL_INSTANCE));
  CMOCK_getBufferSize_CALL_INSTANCE* cmock_call_instance = (CMOCK_getBufferSize_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "CMock has run out of memory. Please allocate more.");
  Mock.getBufferSize_CallInstance = CMock_Guts_MemChain(Mock.getBufferSize_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  cmock_call_instance->ReturnVal = cmock_to_return;
}

void getBufferSize_StubWithCallback(CMOCK_getBufferSize_CALLBACK Callback)
{
  Mock.getBufferSize_CallbackFunctionPointer = Callback;
}

int sendData(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_sendData_CALL_INSTANCE* cmock_call_instance = (CMOCK_sendData_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.sendData_CallInstance);
  Mock.sendData_CallInstance = CMock_Guts_MemNext(Mock.sendData_CallInstance);
  if (Mock.sendData_IgnoreBool)
  {
    if (cmock_call_instance == NULL)
      return Mock.sendData_FinalReturn;
    Mock.sendData_FinalReturn = cmock_call_instance->ReturnVal;
    return cmock_call_instance->ReturnVal;
  }
  if (Mock.sendData_CallbackFunctionPointer != NULL)
  {
    return Mock.sendData_CallbackFunctionPointer(Mock.sendData_CallbackCalls++);
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "Function 'sendData' called more times than expected.");
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, "Function 'sendData' called earlier than expected.");
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, "Function 'sendData' called later than expected.");
  return cmock_call_instance->ReturnVal;
}

void sendData_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, int cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_sendData_CALL_INSTANCE));
  CMOCK_sendData_CALL_INSTANCE* cmock_call_instance = (CMOCK_sendData_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "CMock has run out of memory. Please allocate more.");
  Mock.sendData_CallInstance = CMock_Guts_MemChain(Mock.sendData_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ReturnVal = cmock_to_return;
  Mock.sendData_IgnoreBool = (int)1;
}

void sendData_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, int cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_sendData_CALL_INSTANCE));
  CMOCK_sendData_CALL_INSTANCE* cmock_call_instance = (CMOCK_sendData_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "CMock has run out of memory. Please allocate more.");
  Mock.sendData_CallInstance = CMock_Guts_MemChain(Mock.sendData_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  cmock_call_instance->ReturnVal = cmock_to_return;
}

void sendData_StubWithCallback(CMOCK_sendData_CALLBACK Callback)
{
  Mock.sendData_CallbackFunctionPointer = Callback;
}

int recieveRxACK(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_recieveRxACK_CALL_INSTANCE* cmock_call_instance = (CMOCK_recieveRxACK_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.recieveRxACK_CallInstance);
  Mock.recieveRxACK_CallInstance = CMock_Guts_MemNext(Mock.recieveRxACK_CallInstance);
  if (Mock.recieveRxACK_IgnoreBool)
  {
    if (cmock_call_instance == NULL)
      return Mock.recieveRxACK_FinalReturn;
    Mock.recieveRxACK_FinalReturn = cmock_call_instance->ReturnVal;
    return cmock_call_instance->ReturnVal;
  }
  if (Mock.recieveRxACK_CallbackFunctionPointer != NULL)
  {
    return Mock.recieveRxACK_CallbackFunctionPointer(Mock.recieveRxACK_CallbackCalls++);
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "Function 'recieveRxACK' called more times than expected.");
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, "Function 'recieveRxACK' called earlier than expected.");
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, "Function 'recieveRxACK' called later than expected.");
  return cmock_call_instance->ReturnVal;
}

void recieveRxACK_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, int cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_recieveRxACK_CALL_INSTANCE));
  CMOCK_recieveRxACK_CALL_INSTANCE* cmock_call_instance = (CMOCK_recieveRxACK_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "CMock has run out of memory. Please allocate more.");
  Mock.recieveRxACK_CallInstance = CMock_Guts_MemChain(Mock.recieveRxACK_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ReturnVal = cmock_to_return;
  Mock.recieveRxACK_IgnoreBool = (int)1;
}

void recieveRxACK_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, int cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_recieveRxACK_CALL_INSTANCE));
  CMOCK_recieveRxACK_CALL_INSTANCE* cmock_call_instance = (CMOCK_recieveRxACK_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "CMock has run out of memory. Please allocate more.");
  Mock.recieveRxACK_CallInstance = CMock_Guts_MemChain(Mock.recieveRxACK_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  cmock_call_instance->ReturnVal = cmock_to_return;
}

void recieveRxACK_StubWithCallback(CMOCK_recieveRxACK_CALLBACK Callback)
{
  Mock.recieveRxACK_CallbackFunctionPointer = Callback;
}

int sequenceNumber(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_sequenceNumber_CALL_INSTANCE* cmock_call_instance = (CMOCK_sequenceNumber_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.sequenceNumber_CallInstance);
  Mock.sequenceNumber_CallInstance = CMock_Guts_MemNext(Mock.sequenceNumber_CallInstance);
  if (Mock.sequenceNumber_IgnoreBool)
  {
    if (cmock_call_instance == NULL)
      return Mock.sequenceNumber_FinalReturn;
    Mock.sequenceNumber_FinalReturn = cmock_call_instance->ReturnVal;
    return cmock_call_instance->ReturnVal;
  }
  if (Mock.sequenceNumber_CallbackFunctionPointer != NULL)
  {
    return Mock.sequenceNumber_CallbackFunctionPointer(Mock.sequenceNumber_CallbackCalls++);
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "Function 'sequenceNumber' called more times than expected.");
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, "Function 'sequenceNumber' called earlier than expected.");
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, "Function 'sequenceNumber' called later than expected.");
  return cmock_call_instance->ReturnVal;
}

void sequenceNumber_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, int cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_sequenceNumber_CALL_INSTANCE));
  CMOCK_sequenceNumber_CALL_INSTANCE* cmock_call_instance = (CMOCK_sequenceNumber_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "CMock has run out of memory. Please allocate more.");
  Mock.sequenceNumber_CallInstance = CMock_Guts_MemChain(Mock.sequenceNumber_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ReturnVal = cmock_to_return;
  Mock.sequenceNumber_IgnoreBool = (int)1;
}

void sequenceNumber_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, int cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_sequenceNumber_CALL_INSTANCE));
  CMOCK_sequenceNumber_CALL_INSTANCE* cmock_call_instance = (CMOCK_sequenceNumber_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "CMock has run out of memory. Please allocate more.");
  Mock.sequenceNumber_CallInstance = CMock_Guts_MemChain(Mock.sequenceNumber_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  cmock_call_instance->ReturnVal = cmock_to_return;
}

void sequenceNumber_StubWithCallback(CMOCK_sequenceNumber_CALLBACK Callback)
{
  Mock.sequenceNumber_CallbackFunctionPointer = Callback;
}

int rxSlowStart(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_rxSlowStart_CALL_INSTANCE* cmock_call_instance = (CMOCK_rxSlowStart_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.rxSlowStart_CallInstance);
  Mock.rxSlowStart_CallInstance = CMock_Guts_MemNext(Mock.rxSlowStart_CallInstance);
  if (Mock.rxSlowStart_IgnoreBool)
  {
    if (cmock_call_instance == NULL)
      return Mock.rxSlowStart_FinalReturn;
    Mock.rxSlowStart_FinalReturn = cmock_call_instance->ReturnVal;
    return cmock_call_instance->ReturnVal;
  }
  if (Mock.rxSlowStart_CallbackFunctionPointer != NULL)
  {
    return Mock.rxSlowStart_CallbackFunctionPointer(Mock.rxSlowStart_CallbackCalls++);
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "Function 'rxSlowStart' called more times than expected.");
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, "Function 'rxSlowStart' called earlier than expected.");
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, "Function 'rxSlowStart' called later than expected.");
  return cmock_call_instance->ReturnVal;
}

void rxSlowStart_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, int cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_rxSlowStart_CALL_INSTANCE));
  CMOCK_rxSlowStart_CALL_INSTANCE* cmock_call_instance = (CMOCK_rxSlowStart_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "CMock has run out of memory. Please allocate more.");
  Mock.rxSlowStart_CallInstance = CMock_Guts_MemChain(Mock.rxSlowStart_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ReturnVal = cmock_to_return;
  Mock.rxSlowStart_IgnoreBool = (int)1;
}

void rxSlowStart_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, int cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_rxSlowStart_CALL_INSTANCE));
  CMOCK_rxSlowStart_CALL_INSTANCE* cmock_call_instance = (CMOCK_rxSlowStart_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "CMock has run out of memory. Please allocate more.");
  Mock.rxSlowStart_CallInstance = CMock_Guts_MemChain(Mock.rxSlowStart_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  cmock_call_instance->ReturnVal = cmock_to_return;
}

void rxSlowStart_StubWithCallback(CMOCK_rxSlowStart_CALLBACK Callback)
{
  Mock.rxSlowStart_CallbackFunctionPointer = Callback;
}

int indexSeqNumber(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_indexSeqNumber_CALL_INSTANCE* cmock_call_instance = (CMOCK_indexSeqNumber_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.indexSeqNumber_CallInstance);
  Mock.indexSeqNumber_CallInstance = CMock_Guts_MemNext(Mock.indexSeqNumber_CallInstance);
  if (Mock.indexSeqNumber_IgnoreBool)
  {
    if (cmock_call_instance == NULL)
      return Mock.indexSeqNumber_FinalReturn;
    Mock.indexSeqNumber_FinalReturn = cmock_call_instance->ReturnVal;
    return cmock_call_instance->ReturnVal;
  }
  if (Mock.indexSeqNumber_CallbackFunctionPointer != NULL)
  {
    return Mock.indexSeqNumber_CallbackFunctionPointer(Mock.indexSeqNumber_CallbackCalls++);
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "Function 'indexSeqNumber' called more times than expected.");
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, "Function 'indexSeqNumber' called earlier than expected.");
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, "Function 'indexSeqNumber' called later than expected.");
  return cmock_call_instance->ReturnVal;
}

void indexSeqNumber_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, int cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_indexSeqNumber_CALL_INSTANCE));
  CMOCK_indexSeqNumber_CALL_INSTANCE* cmock_call_instance = (CMOCK_indexSeqNumber_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "CMock has run out of memory. Please allocate more.");
  Mock.indexSeqNumber_CallInstance = CMock_Guts_MemChain(Mock.indexSeqNumber_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ReturnVal = cmock_to_return;
  Mock.indexSeqNumber_IgnoreBool = (int)1;
}

void indexSeqNumber_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, int cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_indexSeqNumber_CALL_INSTANCE));
  CMOCK_indexSeqNumber_CALL_INSTANCE* cmock_call_instance = (CMOCK_indexSeqNumber_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "CMock has run out of memory. Please allocate more.");
  Mock.indexSeqNumber_CallInstance = CMock_Guts_MemChain(Mock.indexSeqNumber_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  cmock_call_instance->ReturnVal = cmock_to_return;
}

void indexSeqNumber_StubWithCallback(CMOCK_indexSeqNumber_CALLBACK Callback)
{
  Mock.indexSeqNumber_CallbackFunctionPointer = Callback;
}

int datalength(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_datalength_CALL_INSTANCE* cmock_call_instance = (CMOCK_datalength_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.datalength_CallInstance);
  Mock.datalength_CallInstance = CMock_Guts_MemNext(Mock.datalength_CallInstance);
  if (Mock.datalength_IgnoreBool)
  {
    if (cmock_call_instance == NULL)
      return Mock.datalength_FinalReturn;
    Mock.datalength_FinalReturn = cmock_call_instance->ReturnVal;
    return cmock_call_instance->ReturnVal;
  }
  if (Mock.datalength_CallbackFunctionPointer != NULL)
  {
    return Mock.datalength_CallbackFunctionPointer(Mock.datalength_CallbackCalls++);
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "Function 'datalength' called more times than expected.");
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, "Function 'datalength' called earlier than expected.");
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, "Function 'datalength' called later than expected.");
  return cmock_call_instance->ReturnVal;
}

void datalength_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, int cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_datalength_CALL_INSTANCE));
  CMOCK_datalength_CALL_INSTANCE* cmock_call_instance = (CMOCK_datalength_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "CMock has run out of memory. Please allocate more.");
  Mock.datalength_CallInstance = CMock_Guts_MemChain(Mock.datalength_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ReturnVal = cmock_to_return;
  Mock.datalength_IgnoreBool = (int)1;
}

void datalength_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, int cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_datalength_CALL_INSTANCE));
  CMOCK_datalength_CALL_INSTANCE* cmock_call_instance = (CMOCK_datalength_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "CMock has run out of memory. Please allocate more.");
  Mock.datalength_CallInstance = CMock_Guts_MemChain(Mock.datalength_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  cmock_call_instance->ReturnVal = cmock_to_return;
}

void datalength_StubWithCallback(CMOCK_datalength_CALLBACK Callback)
{
  Mock.datalength_CallbackFunctionPointer = Callback;
}

