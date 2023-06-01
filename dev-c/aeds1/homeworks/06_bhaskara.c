// This project determine if a quadratic equation has real roots.

#include <stdio.h>

int main(void){
  
  float a, b, c, delta;

  printf("\n Enter the coefficients a, b, c: ");
  scanf("%f %f %f", &a, &b, &c);

  delta = b*b - 4 * a * c;

  if(delta >= 0){
    printf("\n The equation has real roots \n\n");
  } else printf("\n The equation does not have real roots \n\n");

return 0;
}
