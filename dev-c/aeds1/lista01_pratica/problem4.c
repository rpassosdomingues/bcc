#include <stdio.h>

int main(void) {
    
  int m, n, x, y, expression, maxValue, maxX, maxY;

  x = 1;
  y = 1;
  maxValue = 0;

  printf("\n Enter the value of m: ");
  scanf("%d", &m);
  printf("\n Enter the value of n: ");
  scanf("%d", &n);

  while (x < m) {
    y = 1; // Reset y for each new value of x
    while (y < n) {
      expression = x * y - x * x + y;
      if(expression > maxValue){
        maxValue = expression;
        maxX = x;
        maxY = y;
      }
      y++;
    }
    x++;
  }

  printf("\n\t The pair (x, y) that maximizes the expression is: (%d, %d)\n", maxX, maxY);
  printf("\t The maximum value found is: %d \n\n", maxValue);

  return 0;

}
