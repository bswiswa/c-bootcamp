/* void pointers */
// tutorial from Function Pointers in C Programming language - DeccanSoft
#include <stdio.h>

int n;
double d;
void* add_int(void* a, void* b){
  int* s = (int*)a;
  int* t = (int*)b;
  n = *s + * t;
  return &n;
}

void* add_double(void* a, void* b){
  double* s = (double*)a;
  double* t = (double*)b;
  d = *s + *t;
  return &d;
}

void* calculate(void* x, void* y, void* (*operation)(void* x, void* y)){
  void* res = operation(x, y);
  return res;
}

int main(){
  double n1 = 10, n2 = 20;
  void* (*p)(void*, void*);
  p = add_double;
  double result = *((double*)calculate(&n1, &n2,p));
  printf("result = %f\n", result);
  p = add_int;
  int i = (int)n1;
  int j = (int)n2;
  int r = *((int*)calculate(&i, &j,p));
  printf("result = %d\n", r);

  return 0;
}
