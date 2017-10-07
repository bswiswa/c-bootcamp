/* using the define directive */

// the define directive directly replaces its definition with its values
// whenever it is encountered in the program
#include <stdio.h>

#define DIFF 2 - 1
#define MAX(a,b) a>b? a:b
int main(){
  int i = 0, j = 1;
  printf("DIFF is a directive that equates to: %d \n", DIFF);
  printf("The larger number between i and j is %d \n", MAX(i,j));
  printf("Study the behaviour of our definition in MAX(++i, ++j) = %d \n", MAX(++i, ++j));
  // note that after replacement MAX(++i, ++j) becomes ++0 > ++1 ? which returns ++2 
  return 0;
}
