// This project calculate the area of a circle.

#include <stdio.h>

int main(void){
  
  float radius, circle_area;
  const float pi = 3.1415;

  printf("\n Enter the value of the radius: ");
  scanf(" %f", &radius);

  circle_area = pi * radius * radius;

  printf("\n\t The area of the circle is: %.2f m² \n\n", circle_area);

  return 0;
}
