/* define a stack using an array */

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5

struct ArrayStack{
  int layer [MAX_SIZE];
  int top;
};

typedef struct ArrayStack stk;


stk* create_stack(){
  stk* s = (stk*)malloc(sizeof(stk));
  s->top = -1;
  return s;
}

void pop(stk* s){
  if(s->top > -1)
    --s->top;
  else
    printf("Stack is empty\n");
}

void push(stk* s, int val){
  if(s->top + 1 < MAX_SIZE){
    s->layer[++s->top] = val;
  }
  else{
    printf("Error: stack overflow \n");
  }
}

int top(stk* s){
  if(s->top > -1)
    return s->layer[s->top];
  else
    {
      printf("Stack is empty, use pop function to add \n");
      return -1;
    }
}

void printStack(stk *s){
  printf("Printing stack \n");
  if(s->top > -1){
    for(int i = s->top; i > -1; i--){
      printf("[%d] %d \n", s->top - i, s->layer[i]);
    }
  }
  else
    printf("Empty stack\n");
}

int main(){
  stk* s = create_stack();
  printf("Pushing 1...\n");
  push(s, 1);
  printStack(s);
  printf("Top = [%d] %d \n", s->top, top(s));
  printf("Pushing 2...\n");
  push(s, 2);
  printStack(s);
  printf("Popping...\n");
  pop(s);
  printStack(s);
  printf("Popping...\n");
  pop(s);
  printStack(s);
  printf("Popping...\n");
  pop(s);
  printStack(s);
  printf("Pushing, 6 times...\n");
  push(s, 2);
  push(s, 3);
  push(s, 4);
  push(s, 5);
  push(s, 6);
  push(s, 7);
  printStack(s);
  return 0;
}
