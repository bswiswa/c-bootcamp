/* creating, writing and reading from files
 */
#include <stdio.h>

int main(){
  FILE* filestream = fopen("data.dat", "w");
  size_t obj_size = sizeof(char)*30;
  size_t obj_count = 4;
  char * message[] = { 
    "-------------------------\n",
    "--Welcome to C File I/O--\n",
    "-------------------------\n"
  };
  // note that message is an array of character pointers
  //write
  char str[4][30];
  for(int i = 0; i < 3;i++){
    fprintf(filestream,"%s", message[i]);
  }
  //close
  fclose(filestream);
  //append
  filestream = fopen("data.dat", "a");
  fprintf(filestream,"%s", "--w--w+---a--a+---r--r+--");
 
//close
  fclose(filestream);
  //read
  filestream = fopen("data.dat", "r");
  
  fread(&str, obj_size, obj_count, filestream);
 
  printf("%s \n", *str);
  
  fclose(filestream);

  return 0;
}
