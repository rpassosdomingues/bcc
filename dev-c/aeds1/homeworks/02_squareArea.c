// This project calculate of the square area.

#include <stdio.h>

int main(void){

 float side, squareArea;

  printf("\n Enter the value of the side: ");
  scanf(" %f", &side);

  squareArea = side * side;

  printf("\n\t The area of the square is: %.2f m² \n\n", squareArea);

return 0;
}
