/* function to show that arrays are always passed by reference so
a regular swap function will indeed swap the value of the array */

// remember that the array name is a constant pointer
// it cannot point anywhere else

#include <stdio.h>

void swap(int a[], int b[]){
  int temp;
  for(int i = 0; i < 3; i++){
    temp = *(a+i);
    *(a+i) = *(b+i);
    *(b+i) = temp;
  }
}

int main(){
  int arr[] = {1, 2, 3}, arr2[] = {4, 5, 6};
  printf("BEFORE SWAP: arr = { %d, %d, %d } arr2 = { %d, %d, %d }\n ", arr[0], arr[1], arr[2], arr2[0], arr2[1], arr2[2]);
  swap(arr, arr2);
  printf("AFTER SWAP: arr = { %d, %d, %d } arr2 = { %d, %d, %d }\n ", arr[0], arr[1], arr[2], arr2[0], arr2[1], arr2[2]);
  return 0;
}
  
