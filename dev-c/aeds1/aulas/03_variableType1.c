/*
This program aims to print on the screen different types of variables
and how each type is allocated in the computer's memory.

   It's interesting to note how much memory each variable type occupies.
*/
#include<stdio.h>

int main(void){
  
  printf("\n\t Variable Types and Memory Allocation \n\n");

  int integerValue = 50;

  printf("\t Integer Variable: \n");
  printf("\t\t Stored Value: %d\n", integerValue);  // %d indicates that printf()
                                                    // should print an integer value.
  printf("\t\t Memory Address: %p\n", &integerValue);
  printf("\t\t Size in bytes: %ld\n\n", sizeof(int));  // -sizeof- calculates the size
                                                       // of the operand.

  float floatValue = 50;

  printf("\t Float Variable: \n");
  printf("\t\t Stored Value: %f\n", floatValue);  // %f indicates that printf()
                                                  // should print a floating-point value.

  printf("\t\t Memory Address: %p\n", &floatValue);
  printf("\t\t Size in bytes: %ld\n\n", sizeof(float));

  char charValue = 64;

  printf("\t Char Variable: \n");
  printf("\t\t Stored Value: %c\n", charValue);  // %c indicates that printf()
                                                 // should print a character.

  printf("\t\t Memory Address: %p\n", &charValue);
  printf("\t\t Size in bytes: %ld\n\n", sizeof(char));

  return 0;
}
