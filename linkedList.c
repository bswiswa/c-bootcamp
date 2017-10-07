/* working with linked lists */
/* to understand how linked lists work you have to go back and think
about your understanding of how values are stored eg, if you are storing an integer
say int a = 2, there are 2 boxes of information, side by side that hold that value
 - the easy one is the one on the right, it contains an integer value of 2
 - the box on the left is one which contains the memory location which has a type int*
 since it is an integer pointer.
 Thus if you were creating a pointer for an integer a.k.a you want to store the value of
 the variable a's int*-type-pointer, you would declare this pointer as int* pointer = &a

Take this another level up now to a pointer variable.Lets use the same int* pointer from above.
 It has 2 boxes as well - 
- the easy one on the right stores a value of type int* which is equivalent to the address
 of integer variable a (or &a)
- the box on the left is therefore the address of our pointer variable. This is an address for a variable that stores the address of an integer variable hence it is of type int** (notice the 
double ** here as it is the pointer of a pointer) 

Thus when we want to pass a pointer variable by reference, we must pass it with the double ** say int** which gives us access to the direct location of the pointer in memory so we can change
its value so it applies outside of functions 

This explanation is relevant to understanding the prepend function and the remove_first and all others that involve us passing **pointers or pointers of pointers */


#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int val;
  struct node* next;
} node_t;

void printList(node_t* head){
  int i = 1;
  node_t* node = head;
  while(node != NULL){
    printf("%d) %d \n", i, node->val);
    node = node->next;
    i++;
  }
}

node_t* create_node(int val){
  node_t* new_node = malloc(sizeof(node_t));
  new_node->val = val;
  new_node->next = NULL;
  return new_node;
}

void append(node_t* head, int val){
  node_t* last = head;
  while(last->next != NULL){
    last = last->next;
  }
  last->next = create_node(val);
}

void  prepend(node_t** head, int val){
  node_t* new_first = create_node(val);
  new_first->next = *head;
  *head = new_first;
}

void remove_first(node_t** head){
  node_t* temp = *head;
  *head = (*head)->next;
  free(temp);
}

void remove_last(node_t* head){
  node_t* node = head; 
  node_t* last;
  last = NULL;
  if(node->next == NULL)
    free(node);
  else{
    while(node->next->next != NULL){
      node = node->next;
    }
    last = node->next->next;
    node->next = NULL;
    free(last);
  }
}

void remove_val(node_t** head, int val){
  node_t* node = *head;
  node_t* prev;
  node_t* match;
  //if match is at head
  if(node->val == val){
    remove_first(head);
    return;
  }
  else{
    while(node->next != NULL){
      if(node->next->val == val){
	match = node->next;
	node->next = node->next->next;
	free(match);
	return;
      }
      node = node->next;
    }
  }
}

void sortList(node_t** head){
  node_t* cursor,*current, *node;
  cursor = *head;
  *head = NULL;
  while(cursor != NULL){
    current = cursor;
    cursor = cursor->next;
    if(*head != NULL){
      if(current->val > (*head)->val){
	node = *head;
	while((node->next != NULL) && (current->val > node->next->val)){
	  node = node->next;
	}
	// either we have reached last node of the developing chain  and it is less than current OR we 
	// are at the node before the one whose value is bigger than the current value
	current->next = node->next;
	node->next = current;
      }
      else{
	current->next = *head;
	*head = current;
      }
    }
    else{
      //pre-assign head as first element
      current->next = NULL;
      *head = current;
    }
  }
}

void reverse(node_t ** head){
  node_t *cursor = *head, *node;
  *head = NULL;
  while(cursor != NULL){
  node = cursor;
  cursor = cursor->next;
  node->next = *head;
  *head = node;
 }
}

int main(){
 
  // head
  printf("Created head = 1 \n");
  node_t* head = create_node(1);
  printList(head);
  printf("Appending 2... \n");
  append(head,2);
  printList(head);
  printf("Appending 3... \n");
  append(head,3);
  printf("Appending 9... \n");
  append(head,9);
  printf("Appending 7... \n");
  append(head,7);
  printf("Appending 4... \n");
  append(head,4);
  printList(head);
  printf("Prepending... \n");
  prepend(&head, 10);
  printList(head);
  printf("Removing first element... \n");
  remove_first(&head);
  printList(head);
  printf("Removing last element... \n");
  remove_last(head);
  printList(head);
  printf("Removing particular element... \n");
  remove_val(&head, 1);
  printList(head);
  printf("Sorting list...\n");
  sortList(&head);
  printList(head);
  printf("Reversing list...\n");
  reverse(&head);
  printList(head);
  free(head);
  return 0;
}
