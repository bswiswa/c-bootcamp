// create a heap in an array
#include <stdio.h>
#include <stdlib.h>
#define MAX 20
int maxIndex = 1, size = 0;

void print(int h[]){
  for(int i = 1; i <= size; i++){
    printf("%d : %d \n",i , h[i]);
  }
}

void swap(int h[], int i, int j){
  int temp;
  if(i >= 0 && j >= 0){
    temp = h[i];
    h[i] = h[j];
    h[j] = temp;
  }
}

void siftUp(int h[], int index){
  int temp, parent = index/2;
  if(parent < 1 || parent > MAX)
    return;
  else if(h[parent] < h[index]){
      swap(h, parent, index);
      if(parent > 0) siftUp(h,parent);
    }
}


void insert(int h[], int val){
  int index;
  if(size == MAX){
    printf("Heap is full\n");
    return;
  }
  else{
    index = ++size;
    h[index] = val;
    siftUp(h,index);
  }
}

int get_max(int h[]){
  return h[maxIndex];
}

int get_size(){
  return size;
}

int is_empty(){
  if(size < 1) return 1;
  else return 0;
}

void siftDown(int h[], int index){
  int left_child = 2*index;
  int right_child = 2*index + 1;
  int no_left_child = (left_child < 1 || left_child > size)? 1:0;
  int no_right_child =  (right_child < 1 || right_child > size)? 1:0;
  int swapi;
  
  if(no_left_child == 1 && no_right_child == 1) return;
  else if(no_left_child != 1 && no_right_child != 1){
    if(h[left_child] > h[right_child]) {
      swapi = left_child;
    }
    else swapi = right_child;
  }
  else if(no_left_child != 1)
    swapi = left_child;
  else 
    swapi = right_child;

  if(h[index] < h[swapi]){
    swap(h, index, swapi);
    siftDown(h, swapi);
  }
}

int extract_max(int h[]){
  int max, temp;
  if(is_empty() == 1){
    printf("Heap is empty. Returning 0");
    return 0;
  }
  else{ 
    max = h[maxIndex];
    h[maxIndex] = h[size];
    size--;
    siftDown(h, maxIndex);
    return max;
  }
}

void removeIndex(int h[], int index){
  if(index > size || index < 1) {
    printf("Index not found");
    return;
  }
  else{
    h[index] = h[maxIndex]+1;
    siftUp(h,index);
    extract_max(h);
  }
}


void hSiftDown(int h[], int index, int arr_size){
  int left_child = 2*index;
  int right_child = 2*index + 1;
  int no_left_child = (left_child < 1 || left_child > arr_size)? 1:0;
  int no_right_child =  (right_child < 1 || right_child > arr_size)? 1:0;
  int swapi;

  if(no_left_child == 1 && no_right_child == 1) return;
  else if(no_left_child != 1 && no_right_child != 1){
    if(h[left_child] > h[right_child]) {
      swapi = left_child;
    }
    else swapi = right_child;
  }
  else if(no_left_child != 1)
    swapi = left_child;
  else
    swapi = right_child;

  if(h[index] < h[swapi]){
    swap(h, index, swapi);
    hSiftDown(h, swapi,arr_size);
  }
}

void heapify(int h[], int arr_size){
  h[arr_size] = h[0];
  for(int i = arr_size/2; i > 0; i--){
    hSiftDown(h,i, arr_size);
  }
}

int main(){
  int h[MAX];
  printf("Heap is empty? : %s \n", is_empty() == 1? "True":"False");
  insert(h,0);
  printf("Heap is empty? : %s \n",is_empty() == 1? "True":"False");
  insert(h,1);
  printf("Binary heap contents after inserting 0 and 1\n");
  print(h);
  insert(h,5);
  printf("Binary heap contents after inserting 0,1 and 5\n");
  print(h);
  insert(h,3);
  printf("Binary heap contents after inserting 0,1,5,3\n");
  print(h);
  insert(h,2);
  printf("Binary heap contents after inserting 0,1,5,3,2\n");
  print(h);
  insert(h,7);
  printf("Binary heap contents after inserting 0,1,5,3,2,7\n");
  print(h);
  insert(h,10);
  printf("Binary heap contents after inserting 0,1,5,3,2,7,10\n");
  print(h);
  printf("Binary heap contents\n");
  print(h);
  printf("Size of the heap is: %d", get_size());
  printf("\nMax is: ");
  printf("%d ", get_max(h));
  printf("\nExtracting the max...extracted %d \n", extract_max(h));
  printf("Binary heap contents\n");
  print(h);
  printf("Deleting index 2 from the heap...printing contents after deletion\n");
  removeIndex(h, 2);
  print(h);
  return 0;
}
