/* introduction to structures 
   covers how to define a structure, declare a structure variable, changing member values,
    and passing structures into functions
*/

#include <stdio.h>

struct Student {
  char name[50];
  int age;
  int marks;
};

void printStudent(struct Student student){
  printf("Name: %s, Age: %d, Marks: %d \n", student.name, student.age, student.marks);
}

int main(){
  struct Student student1 = { "Batsi", 29, 99 }, student2 = { "Ruva", 28, 100 };
  //printing
  printf("Student 2's name is %s \n", student2.name);
  // changing member value
  student1.marks = 10;
  printf("Student 1's marks are %d \n", student1.marks);
  // passing into functions
  printStudent(student1);
  printStudent(student2);
  return 0;
}
