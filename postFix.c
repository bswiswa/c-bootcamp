/* create a program that can evaluate simple postfix expressions */

#include <stdio.h>
#include <stdlib.h>

double processor(char str[]){
  op* top = create_node();
}

op* create_node(){
  op* node = (op*)malloc(sizeof(op));

struct Operations{
  double num;
  struct Operations * next;
};

typedef struct Operations op;

int main(){

  char c[] = "2,3*";
  char* s = c;
  real answer = processor(c);
  //predifined anwers for now
  s ="";
  answer = 0;
  printf("%s = %d", s, answer); 
}
