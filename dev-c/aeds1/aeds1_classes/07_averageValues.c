/*
This project calculate the average of values > 0 entered
by the user, where the last value, which will not be included
in the calculations, is 0 (zero).

Here, zero will be the stop condition.
*/
#include <stdio.h>

int main(void){
  
  int count;
  float total, quantity, value, average;

  count = 0;
  total = 0;
  value = -1;

  if(value != 0){
  
    while (value != 0){

      printf("\n Enter a value: ");
      scanf(" %f", &value);

      total = total + value;
      count = count + 1;
      quantity = count - 1;
      
    }

    if(quantity != 0){
      average = total/quantity;
    }
  
    printf("\n\t\t The average of values is: %.2f \n\n", average);
  }

  return 0;
}
