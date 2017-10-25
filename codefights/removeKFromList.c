/*Given a singly linked list of integers l and an integer k, remove all elements from list l that have a value equal to k.

Example

For l = [3, 1, 2, 3, 4, 5] and k = 3, the output should be
removeKFromList(l, k) = [1, 2, 4, 5];
For l = [1, 2, 3, 4, 5, 6, 7] and k = 10, the output should be
removeKFromList(l, k) = [1, 2, 3, 4, 5, 6, 7].
Input/Output

[time limit] 4000ms (py3)
[input] linkedlist.integer l

A singly linked list of integers.

Guaranteed constraints:
0 ≤ list size ≤ 10^5,
-1000 ≤ element value ≤ 1000.

[input] integer k

An integer.

Guaranteed constraints:
-1000 ≤ k ≤ 1000.

[output] linkedlist.integer

Return l with all the values equal to k removed.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct list_integer{
  int value;
  struct list_integer* next;
} list_integer;

list_integer* alloc_list(int v){
  list_integer* node = (list_integer*)calloc(1, sizeof(list_integer));
  node->value = v;
  return node;
}

list_integer* removeKFromList(list_integer* l, int k){
  list_integer *head, *node, *tmp;
  head = l;
  node = tmp = NULL;
  if(head == NULL) return NULL;
  else{
    // if head == k
    while(head->value == k){
      tmp = head;
      head = head->next;
      free(tmp);
    }
    //if other nodes == k
    node = head;
    while(node!= NULL && node->next != NULL){
      if(node->next->value == k){
	tmp = node->next;
	node->next = tmp->next;
	free(tmp);
      }
      node = node->next;
    }
    return head;
  }
}

void printList(list_integer* l){
  list_integer* node = l;
  while(node != NULL){
    printf("%d ", node->value);
    node = node->next;
  }
  printf("\n");
}

int main(){
  list_integer* head = alloc_list(2);
  list_integer* node = NULL;
  node = alloc_list(2);
  head->next = node;
  /*
for(int i = 0; i < 10; i++){
     node->next = alloc_list(i % 3);
     node = node->next;
  }
  */
  printf("\n Original List\n");
  printList(head);
  printf("\n Removing 2 from list\n");
  head = removeKFromList(head, 2);
  if(head != NULL) printList(head);
  else printf("Empty list\n");
return 0;
}
