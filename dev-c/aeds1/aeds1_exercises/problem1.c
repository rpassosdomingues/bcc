/*
  Project 1: Create an algorithm that reads a set of data containing height (from 1.00 m to 2.30 m) and gender ('F' or 'M'), ensuring data consistency. Stop entering data when the height is zero. Calculate and present:

    [1] the percentage of people with height greater than 1.80 m;
    [2] the average height of men;
    [3] the percentage of women shorter than 1.70 m among all individuals.
*/

#include <stdio.h>

int main(void){

  char gender;
  float averageHeightMen, totalPeople, pc180, pcWomen170;

  float height = -1;
  float numMen = 0;
  float numWomen = 0;
  float sumHeightMen = 0;
  float numPeople180 = 0;
  float numWomen170 = 0;

  while (height != 0) {

    printf("\n Enter the height [1.00 < height < 2.30]: ");
    scanf(" %f", &height);
    while (height > 0 && (height < 1.00 || height > 2.30)) {
      printf("\n Sorry, try again: ");
      scanf(" %f", &height);
    }

    if (height >= 1.80) {
      numPeople180++;
    }

    printf("\n Enter the gender (M/F): ");
    scanf(" %c", &gender);
    while (gender != 'M' && gender != 'm' && gender != 'F' && gender != 'f') {
      printf("\n Sorry, try again: ");
      scanf(" %c", &gender);
    }

    if(gender == 'm' || gender == 'M'){
      numMen++;
      sumHeightMen += height;
    } else if(gender == 'f' || gender == 'F'){
        numWomen++;
        if(height <= 1.70){
          numWomen170++;
        }
      }

    }

    totalPeople = numMen + numWomen;
    
    pc180 = (numPeople180 / totalPeople) * 100;
    
    if(numMen > 0){
      averageHeightMen = sumHeightMen / numMen;
    }
    
    pcWomen170 = (numWomen170 / numWomen) * 100;
    
    printf("\n\t ===================== Results ===================== \n");
    
    printf("\n\t %.2f%% of people have a height greater than 1.80 m. \n", pc180);
    printf("\t The average height of men is %.2f m. \n", averageHeightMen);
    printf("\n\t %.2f%% of women have a height shorter than 1.70 m. \n", pcWomen170);
    
    printf("\n\t ===================== ------- ===================== \n");
  return 0;
}
