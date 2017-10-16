/*
Write a method convertToText that takes int number 
as parameter and returns the text of that number
For example, if 963 is passed, 
convertToText should return "Nine Hundred Sixty Three"
-You can create additional methods if needed
*/
#include <stdio.h>
#include <stdlib.h>

/*
Method: reverse the number and parse through it from the units to the highest
power. Store the growing text into a stack. After parsing is complete,
pop items from the stack to reveal the final text of the submitted
number

get user input -> reverse the number -> set up the stack and its methods ->
create methods to handle teen numbers, tens and powers of ten -> 
parse through the number storing text in the stack -> 
pop everything out of stack
*/

//GET INPUT
void getInput(char** numstr){
  size_t size = 1;
  printf("Please enter the positive integer to convert to text and press ENTER\n");
  getline(numstr, &size,stdin);
}

int getSize(char* numstr){
  int size = 0;
  char c = *numstr;
  while(c != '\n'){
    size++;
    c = *(numstr+size);
  }
  return size;
}

void print_arr(char str_arr[]){
  printf("%s \n", str_arr);
}

// STACK METHODS
struct StringStack{
  char* text;
  struct StringStack* next;
};

typedef struct StringStack stk;

stk* create_node(char* str){
  stk* s = (stk*)malloc(sizeof(stk));
  s->text = str;
  s->next = NULL;
  return s;
}

char* pop(stk** top){
  char* text;
  stk* temp = *top;
  if(*top != NULL){
    text = (*top)->text;
    *top = (*top)->next;
    free(temp);
    return text;
  }
  else{
    printf("Stack is empty\n");
    return NULL;
  }
}

void push(stk** top, char* text){
  stk* node;
  if(*top == NULL){
    *top = create_node(text);
  }
  else{
    node = create_node(text);
    node->next = *top;
    *top = node;
  }
}

//TRANSLATING
char* getUnit(char c){
  char* unit;
  switch(c){
  case '1':
    unit = "ONE";
    break;
  case '2':
    unit = "TWO";
    break;
  case '3':
    unit = "THREE";
    break;
  case '4':
    unit = "FOUR";
    break;
  case '5':
    unit = "FIVE";
    break;
  case '6':
    unit = "SIX";
    break;
  case '7':
    unit = "SEVEN";
    break;
  case '8':
    unit = "EIGHT";
    break;
  case '9':
    unit = "NINE";
    break;
  }
  return unit;
}

char* getTeen(char c){
  char* teen;
  switch(c){
  case '1':
    teen = "ELEVEN";
    break;
  case '2':
    teen = "TWELVE";
    break;
  case '3':
    teen = "THIRTEEN";
    break;
  case '4':
    teen = "FOURTEEN";
    break;
  case '5':
    teen = "FIFTEEN";
    break;
  case '6':
    teen = "SIXTEEN";
    break;
  case '7':
    teen = "SEVENTEEN";
    break;
  case '8':
    teen = "EIGHTEEN";
    break;
  case '9':
    teen = "NINETEEN";
    break;
  }
  return teen;
}

char* getTen(char c){
  char* ten;
  switch(c){
  case '1':
    ten = "TEN";
    break;
  case '2':
    ten = "TWENTY";
    break;
  case '3':
    ten = "THIRTY";
    break;
  case '4':
    ten = "FOURTY";
    break;
  case '5':
    ten = "FIFTY";
    break;
  case '6':
    ten = "SIXTY";
    break;
  case '7':
    ten = "SEVENTY";
    break;
  case '8':
    ten = "EIGHTY";
    break;
  case '9':
    ten = "NINETY";
    break;
  }
  return ten;
}

char* getPower(int index){
  char* p;
  switch(index){
  case 3:
    p = "THOUSAND";
    break;
  case 6:
    p = "MILLION";
    break;
  case 9:
    p = "BILLION";
    break;
  case 12:
    p = "TRILLION";
    break;
  case 15:
    p = "QUADRILLION";
    break;
  }
  return p;
}

int hasNonZero(char num[], int size, int index ){
  for(int i = index; i < index + 3; i++){
    if(i >= size)
      return 0;
    if(num[i] != '0')
      return 1;
  }
  // if it exhausts, return 0
  return 0;
}

int hasTensUnits(char num[], int size, int index){
  for(int i=index-1; i >= index-2; i--){
    if(i < 0) return 0;
    if(num[i] != '0' ) return 1;
  }
  // if it exhausts, return 0
  return 0;
}

int isTeen(char num[], int size, int index){
  int next = index + 1;
  if(next < size){
    if(num[next] == '1' && num[index] != '0') return 1;
    else return 0;
  }
  return 0;
}

int isTen(char num[], int size, int index){
  int next = index + 1;
  if(next < size){
    if(num[next] != '0' && num[index] == '0') return 1;
    else return 0;
  }
  return 0;
}

void translate(char num[],int size, stk** top){
  int index, rem, next;
  for(int i = 0; i <= size/3; i++){
    for(int j = 0; j < 3; j++){
      index = i*3+j;
      if(index >= size || num[index] == '\0') return;
      else{
	//if zero
	if(size == 1 && num[index] == '0') {
	  push(top, "ZERO");
	  return;
	}
	rem = index % 3;
	next = index + 1;
	if(rem == 0){
	  //put names of powers of 10^3 ie thousand, million, billion....quadrillion
	  if(index > 0 && hasNonZero(num, size, index))
	    push(top, getPower(index));
	  if(isTeen(num, size, index) == 0){
	    if(isTen(num, size, index)){
	      push(top, getTen(num[next]));
	      num[next] = '0';
	    }
	    else if(num[index] != '0') push(top, getUnit(num[index]));
	  }
	  else{
	    push(top, getTeen(num[index]));
	    num[next] = '0';
	  }
	}
	else if(rem == 1 && num[index] != '0')
	  push(top, getTen(num[index]));
	else if(rem == 2 && num[index] != '0'){
	  if(hasTensUnits(num, size, index)){
	    push(top, "HUNDRED AND");
	  }
	  else push(top, "HUNDRED");
	  push(top, getUnit(num[index]));
	}
      }
    }
  }
}


int main(){
  int size = 0;
  //use malloc so that you can use getline function in getInput()
  char* numstr = (char*)malloc(sizeof(char));
  getInput(&numstr);
  //get array size for number
  size = getSize(numstr);
  if(size > 0){
    char num[size];
    //populate the array in reverse
    for(int i = 0; i < size; i++){
      num[size-1-i] = *(numstr+i);
    }
    num[size] = '\0';
    free(numstr);
    //start working with the String Stack
    stk* top = NULL;
    translate(num, size, &top);
    while(top != NULL){
      printf("%s ", pop(&top));
    }
    printf("\n");
  }
  else{
    printf("Please enter a positive integer\n");
  }
  return 0;
}
