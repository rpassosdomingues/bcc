/*
Project 1: Company XYZ did a market research to find out whether its customers liked
or not a new product that was recently launched by the company. To do this, it asked
the customer's age and whether or not they liked the product. Knowing that 200 interviews were made,
make an algorithm that calculates and writes:

1 - The number of people who answered yes.
2 - The number of people who answered no.
3 - The average age of the people who answered yes.
4 - The oldest and youngest people who answered yes.
*/

#include<iostream>

using namespace std;

int main(void) {

  char response;
  int age, avgAgeYes;

  int count = 1, limit = 4; // repetition limit
  int numYes = 0, numNo = 0;
  int sumAgeYes = 0;
  int oldestYes = 150;
  int youngestYes = -1;

  while(count < limit){

    cout << "\n How old are you? ";
    cin >> age;

    cout << "\n Did you like the new product? (y/n) ";
    cin >> response;

    if(response == 'y' || response == 'Y'){
      numYes++;
      sumAgeYes += age;
      if(age > oldestYes){
        oldestYes = age;
      }
      if(age < youngestYes){
        youngestYes = age;
      }
      } else if(response == 'n' || response == 'N'){
          numNo++;
        }

    count++;
    }

    if(numYes > 0){
      avgAgeYes = sumAgeYes / numYes;
    }

    cout << "\n\t ===================== Results ===================== \n" << endl;

    cout << "\t " << numYes << " people answered -YES- \n";
    cout << "\t " << numNo << " people answered -NO- \n";

    cout << "\n\t The average age of people who answered -YES- is " << avgAgeYes << " years \n";

    cout << "\n\t The oldest person is " << oldestYes << " years old \n";
    cout << "\t The youngest person is " << youngestYes << " years old \n";

    cout << "\n\t ===================== ------- ===================== \n" << endl;


    return 0;
}
