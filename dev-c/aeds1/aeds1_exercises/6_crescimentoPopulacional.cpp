/*
  Problem 6: Suppose that the population of country A is on the order of 90,000,000
  with an annual growth rate of 1.5% and that the population of a country
  country B is approximately 200,000,000 inhabitants with an annual growth rate
  annual growth rate of 3%, make a program that calculates and writes down the
  number of years it will take for the population of country A to exceed the population of country B
  population of country B, given these growth rates.
*/
#include<iostream>
using namespace std;

int main(void){

    float growthRateA, growthRateB;
    long int yearsToSurpass, populationA, populationB;

    yearsToSurpass = 0;

    populationA = 90000000;
    growthRateA = 0.015;

    populationB = 200000000;
    growthRateB = 0.03;

    while (populationA <= populationB){
      populationA = populationA + populationA * growthRateA;
      populationB = populationB + populationB * growthRateB;
      yearsToSurpass++;
    }

    cout << "\n\t\t It takes " << yearsToSurpass << " years\n\n";

    return 0;
}
