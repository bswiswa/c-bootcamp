/* Program to swap two numbers */
#include <stdio.h>

int main(){
  int i = 5;
  int j = 10;
  int temp = i;
  i = j;
  j = temp;

  printf("i:%d j:%d", i, j);
  return 0;
}
