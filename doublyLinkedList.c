#include <stdio.h>
#include <stdlib.h>


struct node{
  int val;
  struct node *prev;
  struct node *next;
};

typedef struct node node_d;


node_d* create_node(int val){
  node_d* node =  (node_d*)malloc(sizeof(node_d*));
  node->val = val;
  node->prev = NULL;
  node->next = NULL;
  return node;
}

void printList(node_d * head){
  node_d* node = head;
  int i = 0;
  while(node != NULL){
    i++;
    printf("%d) %d \n", i, node->val);
    node = node->next;
  }
}

void reversePrintList(node_d *head){
  node_d * node = head;
  int i = 0;
  while(node->next != NULL){
    node = node->next;
    i++;
  }
  i++;
  while(node != NULL){
    printf("%d) %d\n", i, node->val);
    i--;
    node = node->prev;
  }
}

void append(node_d* head, int val){
  node_d* node = head, *new_node = create_node(val);
  while(node->next != NULL){
    node = node->next;
  }
  new_node->next = NULL;
  new_node->prev = node;
  node->next = new_node;
}

void prepend(node_d** head, int val){
  node_d* node = *head, *new_node = create_node(val);
  if(node != NULL){
    new_node->prev = NULL;
    new_node->next = node;
    node->prev = new_node;
    *head = new_node;
  }
}

void insert_at(node_d** head, int position, int val){
  node_d* node = *head, *temp, *new_node;
  int i = 0;
  if(position == 1){
    prepend(head, val); 
    return;
  }
  else{
    while(node != NULL){
      i++;
      if(i > 1 && i == position){
	new_node = create_node(val);
	temp = node;
	node->prev->next = new_node;
	node->prev = new_node;
	new_node->next = node;
	new_node->prev = temp->prev;
	return;
      }
      node = node->next;
    }
    printf("Index not found \n");
  }
}

void delete_node(node_d** head, int position){
  node_d* node = *head, *temp;
  int i = 0;
  
  if(position == 1){
    temp = *head;
    if(node->next != NULL){
      node->next->prev = NULL;
      *head = node->next;
    }
    free(temp);
    return;
  }
  else{
    while(node != NULL){
      i++;
      if(i > 1 && i == position){
	temp = node;
	node->prev->next = node->next;
	if(node->next != NULL) node->next->prev = node->prev;
	free(node);
	return;
      }
      node = node->next;
    }
    printf("Index not found \n");
  }
}
int main(){
  node_d * head = create_node(1);
  printList(head);
  printf("Adding node...\n");
  append(head, 2);
  printList(head);
  printf("Prepending node...\n");
  prepend(&head, 3);
  printList(head);
  printf("Print reverse list...\n");
  reversePrintList(head);
  printf("Deleting node...\n");
  delete_node(&head, 2);
  printList(head);
  printf("Inserting into list ....\n");
  insert_at(&head, 2, 10);
  printList(head);
  return 0;
}
