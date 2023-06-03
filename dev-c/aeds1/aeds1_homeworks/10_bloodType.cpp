/*
Here I am working on a project that shows possible blood types.
*/

#include<cstdlib>
#include<iostream>

using namespace std;

  int main(void){
    
    string bloodType, RhFactor, motherBloodType, motherRhFactor, fatherBloodType, fatherRhFactor;

    cout << "\n Enter the blood type of the father: ";
    cin >> fatherBloodType >> fatherRhFactor;

    cout << "\n Enter the blood type of the mother: ";
    cin >> motherBloodType >> motherRhFactor;

    // Line 01: Mother A
    if(motherBloodType == "a" && fatherBloodType == "a"){
      bloodType = "a";
      bloodType = "b";
    } else if (motherBloodType == "a" && fatherBloodType == "b") {
        bloodType = "a";
        bloodType = "b";
        bloodType = "ab";
        bloodType = "o";
    } else if (motherBloodType == "a" && fatherBloodType == "ab") {
        bloodType = "a";
        bloodType = "b";
        bloodType == "ab";
    } else if(motherBloodType == "a" && fatherBloodType == "o"){
      bloodType = "a";
      bloodType = "o";
    }

    // Line 02: Mother B
    if(motherBloodType == "b" && fatherBloodType == "a"){
      bloodType = "a";
      bloodType = "b";
      bloodType = "ab";
      bloodType == "o";
    } else if (motherBloodType == "b" && fatherBloodType == "b") {
        bloodType = "b";
        bloodType = "o";
    } else if (motherBloodType == "b" && fatherBloodType == "ab") {
        bloodType = "a";
        bloodType = "b";
        bloodType = "o";
    } else if (motherBloodType == "b" && fatherBloodType == "o") {
        bloodType = "b";
        bloodType = "o";
    }

    // Line 03: Mother AB
    if(motherBloodType == "ab" && fatherBloodType == "a"){
      bloodType = "a";
      bloodType = "b";
      bloodType = "ab";
      bloodType = "o";
    } else if(motherBloodType == "ab" && fatherBloodType == "b"){
      bloodType = "b";
      bloodType = "o";
    } else if(motherBloodType == "ab" && fatherBloodType == "ab"){
      bloodType = "a";
      bloodType = "b";
      bloodType = "o";
    } else if(motherBloodType == "ab" && fatherBloodType == "o"){
      bloodType = "b";
      bloodType = "o";
    }

    // Line 04: Mother O
    if(motherBloodType == "o" && fatherBloodType == "a"){
      bloodType = "a";
      bloodType = "o";
    } else if(motherBloodType == "o" && fatherBloodType == "b"){
        bloodType = "b";
        bloodType = "o";
    } else if (motherBloodType == "o" && fatherBloodType == "ab"){
        bloodType = "a";
        bloodType = "b";
    } else if (motherBloodType == "o" && fatherBloodType == "o"){
      bloodType = "o";
    }

    // Positive or Negative?
    if(motherRhFactor == "p" && fatherRhFactor == "p"){
      RhFactor = "p";
    } else if (motherRhFactor == "p" && fatherRhFactor == "n"){
      RhFactor = "p";
      RhFactor = "n";
    } else if (motherRhFactor == "n" && fatherRhFactor == "p"){
      RhFactor = "p";
      RhFactor = "n";
    } else if (motherRhFactor == "n" && fatherRhFactor == "n") {
      RhFactor = "n";
    }

    cout << "\n\t The possible blood type is: " << bloodType << " " << RhFactor << "\n\n";

  return 0;
}
