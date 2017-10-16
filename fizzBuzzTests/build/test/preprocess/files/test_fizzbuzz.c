#include "build/temp/_test_fizzbuzz.c"
#include "fizzbuzz.h"
#include "unity.h"


void setUp(void)

{

}



void tearDown(void)

{

}



void test_if_3_then_green(void)

{

  color_t color = get_color(3);

  UnityAssertEqualNumber((UNITY_INT)((GREEN)), (UNITY_INT)((color)), (((void *)0)), (UNITY_UINT)(15), UNITY_DISPLAY_STYLE_INT);

}



void test_if_5_then_red(void){

  color_t color = get_color(5);

  UnityAssertEqualNumber((UNITY_INT)((RED)), (UNITY_INT)((color)), (((void *)0)), (UNITY_UINT)(20), UNITY_DISPLAY_STYLE_INT);

}



void test_if_6_then_green(void){

  color_t color = get_color(6);

  UnityAssertEqualNumber((UNITY_INT)((GREEN)), (UNITY_INT)((color)), (((void *)0)), (UNITY_UINT)(25), UNITY_DISPLAY_STYLE_INT);

}



void test_if_10_then_red(void){

  color_t color = get_color(10);

  UnityAssertEqualNumber((UNITY_INT)((RED)), (UNITY_INT)((color)), (((void *)0)), (UNITY_UINT)(30), UNITY_DISPLAY_STYLE_INT);

}



void test_if_2_then_no_color(void){

  color_t color = get_color(2);

  UnityAssertEqualNumber((UNITY_INT)((NONE)), (UNITY_INT)((color)), (((void *)0)), (UNITY_UINT)(35), UNITY_DISPLAY_STYLE_INT);

}



void test_if_15_then_blue(void){

  color_t color = get_color(15);

  UnityAssertEqualNumber((UNITY_INT)((BLUE)), (UNITY_INT)((color)), (((void *)0)), (UNITY_UINT)(40), UNITY_DISPLAY_STYLE_INT);

}
