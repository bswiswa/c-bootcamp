/* function to calculate the number of digits in a number */

#include <stdio.h>

int numDigits(int x){
  int div = 1, i = 1;
  while(x/div > 10){
    i++;
    div = 10*div;
  }
  return i;
}

int main(){
  int num = 24567;
  printf("Number of digits in %d is %d", num, numDigits(num));
  return 0;
}
