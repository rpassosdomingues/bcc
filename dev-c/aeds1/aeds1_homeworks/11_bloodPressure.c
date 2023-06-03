/*
Project - Here I have created a project to determine if your blood pressure is high, normal, or low.
Reference: \url{https://www.ahajournals.org/doi/full/10.1161/01.CIR.93.6.1160}.
*/

#include <stdio.h>

int main(void){

  int systolicBloodPressure, diastolicBloodPressure;

  printf("\n Enter the blood pressure [(7 < systolic < 25) (2 < diastolic < 20)]: ");
  scanf(" %d %d", &systolicBloodPressure, &diastolicBloodPressure);
  
  if(systolicBloodPressure >= 13 || diastolicBloodPressure >= 10){
    printf("\n\t Your blood pressure is high. \n\n");
  } else if (systolicBloodPressure <= 9 || diastolicBloodPressure <= 6) {
    printf("\n\t Your blood pressure is low. \n\n");
  } else printf("\n\t Your blood pressure is normal. \n\n");

  return 0;
}
