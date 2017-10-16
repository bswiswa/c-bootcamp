/* AUTOGENERATED FILE. DO NOT EDIT. */

/*=======Test Runner Used To Run Each Test Below=====*/
#define RUN_TEST(TestFunc, TestLineNum) \
{ \
  Unity.CurrentTestName = #TestFunc; \
  Unity.CurrentTestLineNumber = TestLineNum; \
  Unity.NumberOfTests++; \
  if (TEST_PROTECT()) \
  { \
      setUp(); \
      TestFunc(); \
  } \
  if (TEST_PROTECT()) \
  { \
    tearDown(); \
  } \
  UnityConcludeTest(); \
}

/*=======Automagically Detected Files To Include=====*/
#include "unity.h"
#include <setjmp.h>
#include <stdio.h>

int GlobalExpectCount;
int GlobalVerifyOrder;
char* GlobalOrderError;

/*=======External Functions This Runner Calls=====*/
extern void setUp(void);
extern void tearDown(void);
extern void test_if_3_then_green(void);
extern void test_if_5_then_red(void);
extern void test_if_6_then_green(void);
extern void test_if_10_then_red(void);
extern void test_if_2_then_no_color(void);
extern void test_if_15_then_blue(void);


/*=======Test Reset Option=====*/
void resetTest(void);
void resetTest(void)
{
  tearDown();
  setUp();
}


/*=======MAIN=====*/
int main(void)
{
  UnityBegin("test_fizzbuzz.c");
  RUN_TEST(test_if_3_then_green, 12);
  RUN_TEST(test_if_5_then_red, 18);
  RUN_TEST(test_if_6_then_green, 23);
  RUN_TEST(test_if_10_then_red, 28);
  RUN_TEST(test_if_2_then_no_color, 33);
  RUN_TEST(test_if_15_then_blue, 38);

  return (UnityEnd());
}