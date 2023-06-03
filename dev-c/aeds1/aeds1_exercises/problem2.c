/*
Project 2 - A survey was conducted on some physical characteristics of inhabitants
in a certain region. The following data were collected
for each inhabitant:

- blood type ("O", "A", "B", or "AB"), RH factor (positive "+" or negative "-"),

- maximum blood pressure (between 7 and 25), minimum blood pressure (between 2 and 20),

- and age (between 18 and 130 years).

Do not allow the user to enter incorrect information in the fields and establish a
stopping criterion. Create an algorithm that calculates the percentage of
people with blood type A- or B- among individuals with high blood pressure,
where high blood pressure is defined as a maximum blood pressure
above 14 or a minimum blood pressure above 10.
*/

#include<stdio.h>

int main(void){

  int numPeopleAnBn = 0;
  int numPeopleHighPressure = 0;
  int numPeopleAnBnHighPressure = 0;
  int numPeople = 0;

  int systolicBloodPressure;
  int diastolicBloodPressure;
  int age;

  char bloodType, rhFactor;

  while(numPeople < 5){

    printf("\n Enter the age [18 < age < 130]: ");
    scanf(" %d", &age);
    while (age < 18 || age > 130) {
      printf("\n Sorry, try again: ");
      scanf(" %d", &age);
    }

    printf("\n Enter the blood type ['a', 'b', 'ab', 'o'] --SPACE-- ['p', 'n']: ");
    scanf(" %c %c", &bloodType, &rhFactor);
    while((bloodType != 'a' && bloodType != 'b' && bloodType != 'ab' && bloodType != 'o') || (rhFactor != 'p' && rhFactor != 'n')){
      printf("\n Sorry, try again: ");
      scanf(" %c %c", &bloodType, &rhFactor);
    }

    printf("\n Enter the blood pressure [Systolic --SPACE-- Diastolic]: ");
    scanf(" %d %d", &systolicBloodPressure, &diastolicBloodPressure);
    while ((systolicBloodPressure < 7 || systolicBloodPressure > 25) || (diastolicBloodPressure < 2 || diastolicBloodPressure > 20)) {
      printf("\n Sorry, try again: ");
      scanf(" %d %d", &systolicBloodPressure, &diastolicBloodPressure);
    }

    if(systolicBloodPressure > 14 || diastolicBloodPressure > 10){
      numPeopleHighPressure++;
      if(bloodType == 'a' || bloodType == 'b'){
        if (rhFactor == 'n') {
          numPeopleAnBnHighPressure++;
        }
      }
    }

    numPeople++;

  }

  float pcPeopleAnBn = (float)numPeopleAnBn / numPeople * 100;
  float pcPeopleHighPressure = (float)numPeopleHighPressure / numPeople * 100;
  float pcPeopleAnBnHighPressure = (float)numPeopleAnBnHighPressure / numPeopleHighPressure * 100;

  printf("\n\t ===================== Results ===================== \n");

  printf("\n\t %.2f%% of people have high blood pressure. \n", pcPeopleHighPressure);
  printf("\n\t Among those with high blood pressure, %.2f%% have blood type A- or B-. \n", pcPeopleAnBnHighPressure);
  
  printf("\n\t ===================== ------- ===================== \n");

  return 0;
}
