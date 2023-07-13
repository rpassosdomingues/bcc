/*
Project 8 - A survey was conducted to determine the ı́ rate of infant mortality in a
certain period. Make an algorithm that:

Read the number of children born in the perı́odo investigated.

Read an indeterminate number with the sex of the child killed(male or female) and the
number of months the child was born. The last value read contains the word "END" for the
sex.

The algorithm should then determine and print:
- The percentage of children killed in the perı́odo.
- The percentage of male children killed in the perı́odo.
- The percentage of children who lived 24 months or less in the perı́odo.
*/

#include <iostream>

using namespace std;

int main(void){
  
  float percentDeaths, percentDeathsMale, percentAlive24;
  char gender = 'm';
  int numBirths = 0, numDeaths = 0;
  int numDeathsMale = 0, numDeathsFemale = 0;
  int numMonthsAlive = 0, numMonthsAlive24 = 0;

  cout << "\n Enter the number of children born: ";
  cin >> numBirths;

  cout << "\n Enter the gender (M/F) or 'E' to exit: ";
  cin >> gender;
  while(gender != 'm' && gender != 'M' && gender != 'f' && gender != 'F' && gender != 'e' && gender != 'E'){
    cout << "\n Something is wrong! Try again: ";
    cin >> gender;
  }

  while(gender != 'e' && gender != 'E'){

    cout << "\n How many months did the child live? ";
    cin >> numMonthsAlive;

    if(gender == 'M' || gender == 'm') {
      numDeathsMale++;
    }

    if(numMonthsAlive <= 24) {
      numMonthsAlive24++;
    }

    numDeaths++;
    
    cout << "\n Enter the gender (M/F) or 'E' to exit: ";
    cin >> gender;
    while(gender != 'm' && gender != 'M' && gender != 'f' && gender != 'F' && gender != 'e' && gender != 'E'){
      cout << "\n Something is wrong! Try again: ";
      cin >> gender;
    }
  }

  percentDeaths = (float)numDeaths / numBirths * 100;
  percentDeathsMale = (float)numDeathsMale / numBirths * 100;
  percentAlive24 = (float)numMonthsAlive24 / numDeaths * 100;

  cout << "\n\t === Results === \n";

  cout << "\n\t " << percentDeaths << "% of children died in the period. \n";
  cout << "\n\t " << percentDeathsMale << "% of male children died in the period. \n";
  cout << "\n\t " << percentAlive24 << "% of children lived for 24 months or less in the period. \n\n";

  return 0;
}
