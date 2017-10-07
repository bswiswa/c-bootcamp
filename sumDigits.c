/* function that adds all the digits in a number together */

#include <stdio.h>

int sumDigits(int x){
  int div = 10;
  int sum = 0;
  do{
    sum = sum + (x % div);
    x = x/div;
  }
  while(x != 0);

  return sum;
}

int main(){
  int num = 123456;
  printf("The sum of digits in %d is %d \n",num, sumDigits(num));
  return 0;
}
