/* function to write the sum of to N */

#include <stdio.h>

int sumUpToN(N){
  int sum = 0;
  for(int i = 1; i <= N; i++){
    sum = sum + i;
  }
  return sum;
}

int main(){
  int N = 6;
  printf("Sum of integers up to %d is %d ", N, sumUpToN(N));
  return 0;
}
