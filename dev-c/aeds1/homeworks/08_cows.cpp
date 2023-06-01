// This project recognizes the lightest and the heaviest steer from a database.

#include <cstdlib>
#include <fstream>
#include <iostream> 

using namespace std;

int main(void){
    
  int identifier, weight, id_HEAVY, weight_HEAVY, id_light, weight_light;

  ifstream inputFile("data.txt");
  if(!inputFile.is_open()){
    cout << "\n File not found. \n";
    return 1;
  }
  inputFile >> identifier >> weight;

  id_HEAVY = identifier;
  id_light = identifier;
  weight_HEAVY = weight;
  weight_light = weight;

  while (inputFile >> identifier >> weight){
    if(weight > weight_HEAVY){
      id_HEAVY = identifier;
      weight_HEAVY = weight;
    } else if (weight < weight_light) {
        id_light = identifier;
        weight_light = weight;
    }
  }

  cout << "\n\t The heaviest bull is number " << id_HEAVY << " and its weight is " << weight_HEAVY << "\n";
  cout << "\n\t The lightest bull is number " << id_light << " and its weight is " << weight_light << "\n\n";

  return 0;
}
