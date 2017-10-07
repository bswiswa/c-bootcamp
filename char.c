// printing characters

#include <stdio.h>

int main(){
  char char1 = 'a';
  printf("char1 : %c \n", char1);
  //characters are internally represented as integers
  char1 = 97;
  printf("char1 : %c \n", char1);

  // what integer is A
  char1 = char1 - 32;
  printf("char1 capitalized : %c \n", char1);

  return 0;
}
