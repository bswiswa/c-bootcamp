/* how to write and read to a file */

#include <stdio.h>

struct Student {
  char name[50];
  int age;
  int marks;
};

void writeStructureToFile(struct Student student){
  // 1. get a file pointer
  FILE* fp = fopen("Student.dat", "w");
  /* note that fopen is a function that takes the name of the file as a string
     and the mode as a character(in this case w. Other modes are r for read and a for append). f\
open returns a pointer to the
     file it creates
  */

  // 2. write to the file
  fprintf(fp, "Name \t Age \t Marks \n");
  fprintf(fp, "%s \t %d \t %d \n", student.name, student.age, student.marks); 
  // 3. close the file otherwise it can get corrupted
  fclose(fp);

}

int main(){

  struct Student student = { "Ruva", 29, 99 };
  writeStructureToFile(student);
  return 0;
}
