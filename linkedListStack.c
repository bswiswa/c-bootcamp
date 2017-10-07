/* implement stack with linked list */

#include <stdio.h>
#include <stdlib.h>

struct LinkedListStack{
  int val;
  struct LinkedListStack * next;
};

typedef struct LinkedListStack lstack;

lstack * create_stack(int val){
  lstack* s = (lstack*)malloc(sizeof(lstack));
  s->next = NULL;
  s->val = val;
  return s;
}

void push(lstack** top, int val){
  lstack* node = (lstack*)malloc(sizeof(lstack));
  node->val = val;
  node->next = *top;
  *top = node;
}

void pop(lstack** top){
  if(*top != NULL){
    lstack* temp = *top;
    *top = temp->next;
    free(temp);
  }
  else{
    printf("Empty stack \n");
  }
}

int Top(lstack* top){
  if(top != NULL) return top->val;
  else{
    printf("Empty stack \n");
    return -1;
  }
}

void printStack(lstack* top){
  lstack* node = top;
  int i = 1;
  if(top == NULL) printf("Empty stack\n");

  while(node != NULL){
    printf("[%d] %d \n",i,  node->val);
    i++;
    node = node->next;
  }
}


int main(){
  lstack* top = create_stack(1); 
  printf("Pushing 1...\n");
  push(&top, 1);
  printStack(top);
  printf("Top = %d \n", Top(top));
  printf("Pushing 2...\n");
  push(&top, 2);
  printStack(top);
  printf("Popping...\n");
  pop(&top);
  printStack(top);
  printf("Popping...\n");
  pop(&top);
  printStack(top);
  printf("Popping...\n");
  pop(&top);
  printStack(top);
  printf("Popping...\n");
  pop(&top);
  printf("Pushing, 6 times...\n");
  push(&top, 2);
  push(&top, 3);
  push(&top, 4);
  push(&top, 5);
  push(&top, 6);
  push(&top, 7);
  printStack(top);

 return 0;
}
