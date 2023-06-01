/*
  Here I have developed a project to calculate the Body Mass Index (BMI) of a patient
  and inform their classification.

  BMI, body mass index; WHO, World Health Organization.
  WHO 1998 classification of BMI categories for Europids

  Reference: url<https://onlinelibrary.wiley.com/doi/full/10.1046/j.1440-6047.11.s8.5.x>
*/

#include<cstdlib>
#include<iostream> // scanf and printf to cin e cout
#include<math.h>   // Import the library that provides mathematical functions.

using namespace std;

int main(void){

  float weight, height, bmi;

  cout << "\n Enter weight (in kilograms): ";
  cin >> weight;
  while (weight < 0.0 || weight > 200.0){  // BMI calculated here
                                           // is limited for weight < 200 kg.
    cout << "\n\t Invalid value. Please enter weight again:";
    cin >> weight;
  }

  cout << "\n Enter height (in meters): ";
  cin >> height;
  while (height < 1.0 || height > 2.5){  // BMI calculated here
                                         // is limited for 1.0 m < height < 2.5 m.
    cout << "\n\t Invalid value. Please enter height again:";
    cin >> height;
  }

  bmi = weight/(pow(height,2));  // Body Mass Index (BMI)
                                 // The pow(height, 2) function squares the value
                                 // stored in &height.

  cout << "\n Your BMI is: " << bmi << " kg/m²" << endl;

  if (bmi <= 18.5){                                 // if bmi is less than or equal to 18.5
    cout << "\n\t You are underweight." << endl;
  }else if (bmi > 18.5 && bmi <= 24.9){             // if 18.5 <= bmi <= 24.9
    cout << "\n\t You are normal weight." << endl;
  }else if (bmi > 25.0){
    cout << "\n\t You are overweight. \n" << endl;  // if bmi > 25
  }

  return 0;
}
