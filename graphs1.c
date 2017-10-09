/* introduction to graphs */
/* two lists - list of vertices & list of edges */

#include <stdio.h>
struct Edge{
  char* startVertix;
  char* endVertix;
  //if weighted
  int weight;
};

int main(){
  printf("%lu %lu %lu", sizeof(int), sizeof(char*), sizeof(char));
  return 0;
}
