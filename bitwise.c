/* using bitwise operators - these operate on the bit level.
   They are sometimes used because they are much faster than operands like +/- and much
   faster than * or /
   &  Bitwise AND - returns 1 if both bits are 1
   |  Bitwise OR - returns 1 if one of the bits is 1 
   ^  Bitwise Exclusive OR (XOR) - returns 1 if only one of the bits is 1
   ~  Bitwise NOT - flips all the bits in use
   <<N Shifts bits to the left by a number N
   >>N Shifts bits to the right by a number N
*/

#include <stdio.h>

int main(){

  int a = 1, b = 2;
  /*a = 00000001
    b = 00000010
  a&b = 00000000 
  a|b = 00000011 [3]
  a^b = 00000011 [-(2^31-3)]
 a<<1 = 00000010 [2]
 b>>1 = 00000001 [1]
 ~b   = 0000001 */
  printf("a&b = %d \n", a&b);
  printf("a|b = %d \n", a|b);
  printf("a^b = %d \n", a^b);
  printf("a<<1 = %d \n", a<<1);
  printf("b>>1 = %d \n", b>>1);
  printf("~b = %d \n", ~b);
  printf("%s","XOR can be used to efficiently store a doubly linked list into one address.\n To get the value of an the previous or the next node\n\
you need to have one of the other addresses eg node N has xnp where xnp is the XOR of the next and previous address thus\n\
to get one of the addresses you need either the next address or the previous address\n");
  printf("%s","Bit wise operator & can be used to quickly check whether a number is even or odd eg.3&1 = 00000011 & 00000001 = 00000001 \n\
So any number x & 1 should return 1 if it is odd otherwise it is even");

	 
  return 0;
}
