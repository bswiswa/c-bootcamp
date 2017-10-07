/* calculate average of two integers */
#include <stdio.h>

int main(){
  int i = 1;
  int j = 2;
  float average = (i + j)/2.0;
  // divide with 2.0 not 2 because it would default to integer division
  printf("Average of %d and %d is %f\n", i, j, average);
  return 0;
}
