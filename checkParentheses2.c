/* check parentheses using a much better algorithm */
#include <stdio.h>
#include <stdlib.h>

struct Parentheses{
  char p;
  struct Parentheses* next;
};

typedef struct Parentheses par;

par* new_node(char p){
  par * node = (par*)malloc(sizeof(par));
  node->p = p;
  return node;
}

void push(char p, par** top){
  par* node = *top, *n = new_node(p);
  if(node == NULL){
    n->next = NULL;
  }
  else
    n->next = node;
  *top = n;
  
}

void print(par * top){
  par* node = top;
  if(node != NULL){
    while(node != NULL){
      printf("Unclosed: %c", node->p);
      node = node->next;
    }
    printf("\n");
  }
  else printf("Empty Stack - Balanced parentheses\n");
}

void pop(par** top){
  par* node = *top;
  par* temp = *top;
  if(node->next != NULL){
    *top = (*top)->next;
    free(temp);
  }
  else
    *top = NULL;
}

void isEmpty(par* top){
  if(top != NULL){
    printf("Stack is not empty - Unbalanced parentheses\n");
  }
  else printf("Empty Stack - balanced parentheses\n");
}

int main(){
  int l = 0;
  char s[] = "(2*3)[9/(85-2){11|}](";
  par *node,*top;
  
  while(s[l] != '\0'){
    l++;
  }
  
  for(int i = 0; i <= l; i++){
    switch(s[i]){
    case '(':
    case '[':
    case '{':
      push(s[i], &top); 
      break;
    case ')':
      if(top == NULL){
	printf("Unbalanced parentheses\n");
	return 0;
      }
      else if(top->p == '(') pop(&top);
      else{
        printf("Unbalanced parentheses\n");
        return 0;
      }
      break;
    case ']':
      if(top == NULL){
	printf("Unbalanced parentheses\n");
	return 0;
      }
      else if(top->p == '[')pop(&top);
      else{
        printf("Unbalanced parentheses\n");
        return 0;
      }
      break;
    case '}':
      if(top ==NULL){
	printf("Unbalanced parentheses\n");
	return 0;
      }
      else if(top->p == '{') pop(&top);
      else{
        printf("Unbalanced parentheses\n");
        return 0;
      }
      break;
    default:
      break;
    }
  }
  print(top);
  isEmpty(top);
  return 0;
}
