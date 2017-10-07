// read from file

#include <stdio.h>

struct Student{
  char name[50];
  int age;
  int marks;
};

struct Student readFromFile(){
  // 1. get file pointer by using fopen in r mode
  FILE* fp = fopen("ReadFromFile.dat", "r");
  // 2. scan/read from the file
  struct Student student;
  fscanf(fp, "%s \t %d \t %d", student.name, &student.age, &student.marks);
  // fscanf takes in the pointer to the file, the format and the addresses to store the
  // values read
  // note that student.name did not need to be changed to &student.name because arrays by default pass the address


  // 3. close the file
  fclose(fp);

  return student;
}

int main(){

  struct Student student = readFromFile();
  printf("Name: %s \t Age: %d \t Marks: %d \n", student.name, student.age, student.marks);
  return 0;
}
