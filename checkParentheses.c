/* program that checks that brackets have been closed correctly using a stack */

#include <stdio.h>
#include <stdlib.h>

struct Expression{
  char expr;
  struct Expression *next;
};


typedef struct Expression exp;
void push(exp** e, char c){
  exp * node = *e, *n;
  n = (exp*)malloc(sizeof(exp));
  n->expr = c;
  if(*e == NULL){
    n->next = NULL;
    *e = n;
  }
  else{
    n->next = *e;
  *e = n;
  }
}

void pop(exp** e){
  exp* temp = *e;
  if(*e != NULL){
    *e = (*e)->next;
    free(temp);
  }
}

void printStack(exp* e){
  exp* node = e;
  while(node != NULL){
    printf("%c", node->expr);
    node = node->next;
  }
}

int main(){
  char ex[] = "{(abc12{4533(~{m[8ba";
  char inp, match;
  int i = 0;
  exp *temp;
  exp * e = NULL;
  
  while(ex[i] != '\0'){
    switch(ex[i]){
    case '{':
      push(&e, '}');
      break;
    case '[':
      push(&e, ']');
      break;
    case '(':
      push(&e, ')');
      break;
    default:
      break;
    }
    i++;
  }

  
  printf("Enter one closing parenthesis at a time and press enter to\n\
 properly close the following expression \n %s  ",ex);
  while(e != NULL){  
    scanf("%c", &inp);
    if(inp == e->expr){
      pop(&e);
      
    }
  }
  printf("\nContratulations!\n");
  return 0;
}
