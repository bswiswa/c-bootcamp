/* how to increment attribute values in a structure
 - introduces structure pointers
 - introduces structure pointer notation
*/
#include <stdio.h>

struct Coordinates {
  int x, y;
};

typedef struct Coordinates Coordinates;

void increment(Coordinates a){
  a.x++;
  a.y++;
}

void incrementByReference(Coordinates * p){
  p->x++;
  p->y++;
  /* OR (*p).x++; (p*).y++ */
}

int main(){
  Coordinates a = { 1, 1 };
  Coordinates* p = &a;
  increment(a);
  printf("By Value: a.x = %d a.y = %d \n", a.x, a.y);
  incrementByReference(p);
  printf("By Reference: a.x = %d a.y = %d \n", a.x, a.y);
  return 0;
}
