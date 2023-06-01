/*
Problem 7: A given radioactive material loses half its mass every 50
seconds. Given the initial mass, in grams, make a program that determines
the time required for this mass to become less than 0.5 grams.
Write the initial mass, the final mass, and the calculated time in hours, minutes, and
seconds.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    
  float initialMass, finalMass, halfLife, time;

  cout << "\n Enter the initial mass of the radioactive material: ";
  cin >> initialMass;

  cout << "\n Enter the final mass: ";
  cin >> finalMass;

  cout << "\n Enter the half-life of the radioactive material: ";
  cin >> halfLife;

  time = (halfLife * log(initialMass / finalMass)) / log(2.0);

  cout << "\n\t Time required to reach the final mass: " << time << " units of time \n\n";

  return 0;
}
