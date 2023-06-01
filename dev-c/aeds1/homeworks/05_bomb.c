// Here I created a project to display the countdown of a bomb.

#include <stdio.h>

int main(void){
  
  int countdown_timer;

  printf("\n Enter the countdown time: ");
  scanf(" %d", &countdown_timer);

  while (countdown_timer > 0){
    printf(" \n%d \n", countdown_timer);
    countdown_timer--;
  }

  printf("\n\t Boom!!! \n\n");

  return 0;
}
