/* reading and parsing user input */
#include <stdio.h>
#include <stdlib.h>

int main(){
  /* the getline function requires 3 inputs, a pointer to a char* variable (pointer to a character pointer), a pointer
     to a size_t variable (size_t*) and a stream to read from, if the input is the keyboard, it is stdin */
  size_t l = 3;
  char* str = (char*)malloc(sizeof(char)*l);
  printf("Describe your day in 5 words\n");
  getline(&str, &l, stdin);
  printf("You entered: %s", str);
  return 0;
}
