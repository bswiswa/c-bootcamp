/* function that returns T if number is even and F if odd */

#include <stdio.h>

char isEven(int x){
  if((x % 2) == 0) return 'T';
  else return 'F';
  //no need for else here, could have just used return
}

int main(){
  int num = 2;
  printf("%d is even? %c \n", num, isEven(num));
  num = 3;
  printf("%d is even? %c \n", num, isEven(num));
  return 0;
}
