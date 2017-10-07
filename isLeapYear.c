/* function to determine if a year is a leap year = div by 4 && !(div by 100 && !div by 400) */

#include <stdio.h>

int isLeapYear(int x){
  if(x % 400 == 0) return 'T';
  else if(x % 100 == 0) return 'F';
  else if(x % 4 == 0) return 'T';
  else return 'F';
}

int main(){
  int years [] = {2000, 1900, 1904, 1901};
  for(int i = 0; i < 4; i++){
    printf("%d is a leap year? %c \n", years[i], isLeapYear(years[i]));
  }
  return 0;
}
