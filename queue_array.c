/* create a queue using a circular array */
/* create a to do list */
#include <stdio.h>

struct ToDo{
  char * task;
};
typedef struct ToDo todo;

int isFull(int max, int front, int rear){
  if(front == ((rear+1) % max)) return 1;
  else return 0;
}

int isEmpty(int front, int rear){
  if(front == -1 && rear == -1) return 1;
  else return 0;
}

char* Front(todo* queue, int front, int rear){
  if(isEmpty(front, rear) == 1){
    printf("Queue is empty\n");
    return NULL;
  }
  else return queue[front].task;
}

char* rear(todo* queue, int front, int rear){
  if(isEmpty(front, rear) == 1){
    printf("Queue is empty\n");
    return NULL;
  }
  else return queue[rear].task;
}

void enqueue(todo* queue, int max, int *front_ptr, int* rear_ptr, char * task){
  int rear = *rear_ptr;
  int front = *front_ptr;
  if(isFull(max, front, rear) != 1){
    if(isEmpty(front, rear) == 1){
      *front_ptr = (front+1)%max;
    }
    rear = (rear+1) % max;
    queue[rear].task = task;
    *rear_ptr = rear;
  }
  else{
    printf("Queue is full!\n");
    return;
  }
}

char* dequeue(todo* queue, int max, int* front_ptr, int* rear_ptr){
  int front = *front_ptr;
  int rear = *rear_ptr;
  if(isEmpty(front, rear) == 1){
    printf("Queue is empty!\n");
    return NULL;
  }
  else{
    front = (front + 1) % max;
    if(front == ((rear+1) % max)){
      front = -1;
      rear = -1;
      *front_ptr = front;
      *rear_ptr = rear;
      printf("Queue is now empty!\n");
      return NULL;
    }
    else {
      *front_ptr = front;
      return queue[front].task;
    }
  }
}

int main(){
  int max = 5, front = -1, rear = -1, i = 0;
  todo todos[max];
  
  // if(isEmpty(front, rear) == 1) printf("Queue is empty!\n");
  printf("Front is: %s \n", Front(todos,front, rear));
  enqueue(todos, max, &front, &rear, "Cook");
  if(isEmpty(front, rear) == 1) printf("Queue is empty!\n");
  printf("Front is: %s \n", Front(todos,front, rear));
  printf("Dequeueing... \n");
  dequeue(todos, max, &front, &rear);
  if(isEmpty(front, rear) == 1) printf("Queue is empty!\n");
  printf("Enqueueing again... \n");
  enqueue(todos, max, &front, &rear, "Cook");
  enqueue(todos, max, &front, &rear, "Code");
  enqueue(todos, max, &front, &rear, "Eat");
  enqueue(todos, max, &front, &rear, "TV");
  enqueue(todos, max, &front, &rear, "Shower");
  printf("Printing To Do List...\n");
  i = front;
  while(i != rear){
    printf("%d) %s\n",i, todos[i].task);
    i = (i+1) % max;
  }
  printf("%d) %s\n",++i, todos[rear].task);

  printf("Front is: %s \n", Front(todos,front, rear));
  printf("Trying to add another one...\n");
  enqueue(todos, max, &front, &rear, "Sleep");
  
return 0;  
}
