/* for, do while and while loops */
#include <stdio.h>

int main(){
  int scores[10] = { 106, 15, 145, 23 };
  //note that when array is created larger than the current values in it
  // the empty cells will have a value of zero

  // also note that when you ask for a cell that is outside of the array,
  // you get garbage values

  int i = 0;
  printf("For loop: ");
  for(int i = 0; i < 10; i++){
    printf(" %d ", scores[i]);
  }
  printf("\n");
  //note that the i initialized in the for loop is a local variable
  printf("While loop: ");
  while(i < 10){
    printf(" %d ", scores[i]);
    i++;
  }
  
  printf("\n");
  
  printf("Do While loop: ");
   i = 0;
 do{
   printf(" %d ", scores[i]);
   i++;
 }
 while(i < 10);

  return 0;
}
