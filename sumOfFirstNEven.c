/* find the sum of the first N even numbers */

#include <stdio.h>

int sumOfFirstEven(int N){
  int evens[N];
  int i = 0, sum = 0;
  //notice the proper way of declaring multiple variables
  int num = 1; 
  while(i < N){
    if(num % 2 == 0){
      evens[i] = num;
      i++;
    }
    num++;
  }
  
  for(int i = 0; i < N; i++){
    sum = sum + evens[i];
  }
  return sum;
}

int altSumOfFirstEven(int N){
  int sum = 0;
  for(int i = 1; i <= N; i++){
    sum = sum + i*2;
  }
  return sum;
}

int altSumOfFirstEven2(int N){
  int sum = 0;
  for(int i = 2; i <= 2*N; i = i+2){
    sum = sum + i;
  }
  return sum;
}

int main(){
  int N = 5;
  printf("Sum of first %d even numbers is %d \n", N, sumOfFirstEven(N));
  printf("Sum of first %d even numbers is %d \n", N, altSumOfFirstEven(N));
  printf("Sum of first %d even numbers is %d \n", N, altSumOfFirstEven2(N));
  return 0;
}
