// This program calculates the average height of a universe.

#include<stdio.h>

int main(void){
  
  int count;
  float height, total, quantity, average;

  count = 0;
  total = 0;
  quantity = 10;

  while (count < quantity){

    printf("\n Enter the height: ");
    scanf(" %f", &height);
    while (height < 0.0 || height > 2.5){
      printf("\n\t Sorry, try again: ");
      scanf(" %f", &height);
    }
  
    total = total + height;
    count++;
  }

  average = total/quantity;

  printf("\n\t\t The average height is: %.2f meters \n\n", average);

  return 0;
}
