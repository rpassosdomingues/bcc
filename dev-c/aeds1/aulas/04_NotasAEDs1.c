/*
  Here I have written a code implementing the features I have learned
  using the conditional if statements and while loops.
  
  This program informs the user, given the input grades,
  whether they are approved or not based on their average.
*/

#include<stdio.h>

int main(void){
  
  float grade1, grade2, labGrade, average;

  printf("\n Enter grade1: ");
  scanf(" %f", &grade1);
  while (grade1 < 0.0 || grade1 > 10.0){
    printf("\n\t Sorry, try again: ");
    scanf(" %f", &grade1);
  }

  printf("\n Enter grade2: ");
  scanf(" %f", &grade2);
  while (grade2 < 0.0 || grade2 > 10.0){
    printf("\n\t Sorry, try again: ");
    scanf(" %f", &grade2);
  }

  printf("\n Enter labGrade: ");
  scanf(" %f", &labGrade);
  while (labGrade < 0.0 || labGrade > 10.0){
    printf("\n\t Sorry, try again: ");
    scanf(" %f", &labGrade);
  }
  
  average = (3 * grade1 + 3 * grade2 + 4 * labGrade) / 10;  // Assignment

  printf("\n Your average is: %.2f \n", average);

  if (average >= 6.0){
    printf("\n\t You are approved. \n\n");
  } else{
      printf("\n\t You are failed. \n\n");
  }

  return 0;
}
