/*
This program converts temperature values
from Celsius (from 0°C to 100°C) to Fahrenheit.
*/ 

#include<stdio.h>

int main(void){
  
  int count;
  float celsius, fahrenheit, increment, limit;

  count = 0;
  increment = 1;

  celsius = -increment;
  limit = 100;

  printf("----------------------------\n");
  printf("  Count | (°C) | (°F) \n");
  printf("----------------------------\n");

  while (celsius < limit){
	
    count = count + increment;
    celsius = celsius + increment;

    fahrenheit = (9 * celsius/5) + 32;

	printf("\n    %d \t %.2f \t %.2f\n", count, celsius, fahrenheit);

  }

return 0;
}
