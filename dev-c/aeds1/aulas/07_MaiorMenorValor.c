// This project find the smallest and largest value entered.

#include <stdio.h>

int main(void){
  
  float value, largestValue, smallestValue;
  
  printf("\n Enter a value: ");
  scanf(" %f", &value);
  
  if (value != 0){
  
    largestValue = value;
    smallestValue = value;
  
    while (value != 0){
  
    if(value < smallestValue){
      smallestValue = value;
    } else if(value > largestValue){
        largestValue = value;
      }
  
    printf("\n Enter a value: ");
    scanf(" %f", &value);
  
  }
  
  printf("\n\t\t The largest value is: %.2f \n", largestValue);
  printf("\n\t\t The smallest value is: %.2f \n\n", smallestValue);
  
}

return 0;
}
