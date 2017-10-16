/* 
Notes from mycodeschool videos - Function Pointers; Function pointers and callbacks
function is a set of instructions.
Function pointers store the starting address or the entry
point of a block of memory containing instructions of a
particular function
*/

#include <stdio.h>
#include <stdlib.h>
// stdlib.h is for the abs() function
#include <math.h>
// math.h is for qsort function
int Add(int a, int b){
  return a+b;
}

void printHello(){
  printf("Hello!\n");
}

void A(){
  printf("Hello\n");
}

void B(void (*ptr)()){
  ptr();
}

void BubbleSort(int a[], int size){
  int temp;
  for(int i = 0; i < size; i++){
    for(int j = 0; j < size-1; j++){
      if(a[j] > a[j+1]){
	temp = a[j+1];
	a[j+1] = a[j];
	a[j] = temp;
      }
    }
  }
}

int ascending(int a, int b){
  if(a > b) return 1;
  else return -1;
}

int descending(int a, int b){
  if(a > b) return -1;
  else return 1;
}

int absoluteCompare(int a, int b){
  if(abs(a) > abs(b)) return 1;
  else return -1;
}


void smartBubbleSort(int a[], int size, int (*compare)(int,int)){
  /* callback function should compare two integers, should return 1 if
     first element is greater, 0 if elements are equal and -1 if 
     second element is greater
  */
  int temp;
  for(int i = 0; i < size; i++){
    for(int j = 0; j < size-1; j++){
      if(compare(a[j], a[j+1]) > 0 ){
        temp = a[j+1];
        a[j+1] = a[j];
        a[j] = temp;
      }
    }
  }
}

int qcompare(const void* a, const void* b){
  int x = *((int*)a); // typecast to integer pointer (since it was void*) then dereference to get the value
  int y = *((int*)b);
  return x - y;
}

int main(){
  // pointer to function tht
  // RETURN TYPE (*NAME OF F POINTER) (ARG TYPES)
  int (*p)(int, int);
  // INITIALIZE
  p = Add;
  // this works because the name of a function returns
  // the pointer to that function
  int c = (*p)(2,3);
  printf("%d\n", c);
  
  void (*h)();
  h = printHello;
  (*h)();

  /* function pointers are used when we want to pass functions
     as arguments to other functions
  */
  void (*fp)() = A;
  B(fp);
  B(A);
  /* want to write a function that takes an array and sorts them
     in increasing order 
  */
  int arr[] = { -3,2,1,5,6,4,7};
  BubbleSort(arr,7);
  for(int i = 0; i < 7; i++) printf("%d ", arr[i]); 
  printf("\n");
  /* what if we want to return the sorting in increasing order
     at times but also in decreasing order at times? 
  */
  /* we can write a smartBubbleSort method which takes in an extra
   parameter or flag to indicate the order which we want
   in the BubbleSort method, the order of sorting is determined by
   one point - the comparison between item[j] and item[j+1]
   we can calculate this part by using a function pointer
  */
  printf("better sort\nAscending\n");
  smartBubbleSort(arr, 7, ascending);
  for(int i = 0; i < 7; i++) printf("%d ", arr[i]);
  printf("\n");
  
  printf("better sort\nDescending\n");
  smartBubbleSort(arr, 7, descending);
  for(int i = 0; i < 7; i++) printf("%d ", arr[i]);
  printf("\n");

  printf("better sort\nAbsolute\n");
  smartBubbleSort(arr, 7, absoluteCompare);
  for(int i = 0; i < 7; i++) printf("%d ", arr[i]);
  printf("\n");
  /*  
  qsort can sort any array. You only have to specify the compare logic.
  qsort function takes an array, size of array, size of array data type
  and a pointer to a comparison function.
    the comparison function must take two const void pointers and returns
    an integer eg int qcompare(const void* a, const void* b)
*/
  qsort(arr, 7, sizeof(int), qcompare);
  for(int i = 0; i < 7; i++) printf("%d ", arr[i]);
  printf("\n");
  return 0;
}
