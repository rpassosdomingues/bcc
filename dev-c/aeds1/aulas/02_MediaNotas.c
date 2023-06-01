// This program receives as input
// the numerical values that represent the grades of a fictional student
// and its assignment command -media- returns the weighted average of the student.

#include<stdio.h>

int main(void){
  float grade1, grade2, workGrade, average; // Reserve four memory spaces
                                          // to store variables of type float.

  printf("\n\t Enter grade 1: ");
  scanf(" %f", &grade1);  // Read and store in the memory address -&grade1-
                        // what the user types in the input.

  printf("\n\t Enter grade 2: ");
  scanf(" %f", &grade2);

  printf("\n\t Enter work grade: ");
  scanf(" %f", &workGrade);

  average = (3*grade1 + 3*grade2 + 4*workGrade)/10;  // Assignment command.
                                                     // Create a variable to receive the x input values
                                                     // and return the y output values.

  printf("\n\t Average of AEDs I: %f\n\n", average);

  printf("\t If the average is equal to or higher than 6.0, you are approved. \n");
  printf("\t If the average is lower than 6.0, you are failed. \n\n");

  return 0;
}
