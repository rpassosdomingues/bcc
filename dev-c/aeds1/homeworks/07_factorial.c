// Here I created a project to calculate the factorial of a number n.

#include <stdio.h>

int main(void){

  long int n, factorial_n;

  printf("\n Enter the number n: ");
  scanf(" %ld", &n);

  // factorial_n = n * factorial(n-1)
  factorial_n = 1;
  while (n > 0){
    factorial_n = n * factorial_n;
    n = n - 1;
  }

  printf("\n The factorial of this number is = %ld \n\n", factorial_n);

  return 0;
}
