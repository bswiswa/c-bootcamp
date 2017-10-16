#include <stdio.h>
#include <stdlib.h>

void myfunc(int i){
  printf("%d\n", i);
}

int alph(const void* a, const void* b){
  char c1 = *((char*)a);
  char c2 = *((char*)b);
  if(c1 > c2) return 1;
  else return -1;
}

int main(){
  int i = 0;
  void (*mfp)(int) = myfunc;
  mfp(2);
  char str[10] = "ajyecsbiqr";
  qsort(str, 10, sizeof(char),alph);
  while(i < 10){
    printf("%c", str[i]);
    i++;
  }
  printf("\n");
  return 0;
}
