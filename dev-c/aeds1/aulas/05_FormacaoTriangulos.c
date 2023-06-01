// Here I have written a program that takes three input values
// representing the sides of a triangle and tells me if it's possible to form a triangle
// and in case of a true test, it classifies the type of triangle based on the distribution.

#include <stdio.h>

int main(void){
  float sideA, sideB, sideC;

  printf("\n\t Types of Triangles. \n\n");
    
  printf("\n\t Enter the first side: ");
  scanf(" %f", &sideA);
  while (sideA <= 0.0){
    printf("\n\t Invalid value, please enter the first side again: ");
    scanf(" %f", &sideA);
  }
  
  printf("\n\t Enter the second side: ");
  scanf(" %f", &sideB);
  while (sideB <= 0.0){
    printf("\n\t Invalid value, please enter the second side again: ");
    scanf(" %f", &sideB);
  }
  
  printf("\n\t Enter the third side: ");
  scanf(" %f", &sideC);
  while (sideC <= 0.0){
    printf("\n\t Invalid value, please enter the third side again: ");
    scanf(" %f", &sideC);
  }

  if ((sideA + sideB < sideC) || (sideB + sideC < sideA) || (sideA + sideC < sideB)){
    printf("\n\t These sides cannot form a triangle.\n\n");
  } else if ((sideA == sideB) && (sideA == sideC)){
      printf("\n\t These sides form an equilateral triangle.\n\n");
  } else if ((sideA == sideB) || (sideA == sideC) || (sideB == sideC)){
    printf("\n\t These sides form an isosceles triangle.\n\n");
  } else printf("\n\t These sides form a scalene triangle.\n\n");

  if ((sideA*sideA == sideB*sideB + sideC*sideC) || (sideB*sideB == sideA*sideA + sideC*sideC) || (sideC*sideC == sideB*sideB + sideA*sideA)){
    printf("\t These sides form a rectangle triangle.\n\n");
  }

  return 0;
}
