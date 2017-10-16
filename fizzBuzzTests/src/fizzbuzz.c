#include "fizzbuzz.h"
#include <stdbool.h>

static bool is_multiple_of_5(int value){
  return ((value % 5) == 0);
}

static bool is_multiple_of_3(int value){
  return ((value % 3) == 0);
}

color_t get_color(int value){
  if(is_multiple_of_3(value) && is_multiple_of_5(value)) return BLUE;
  if(is_multiple_of_5(value)) return RED;
  if(is_multiple_of_3(value)) return GREEN;
  return NONE;
}
