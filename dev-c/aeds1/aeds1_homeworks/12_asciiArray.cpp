/*
  This project print the ASCII table using a array.
*/

#include <iostream>
#include <vector>

using namespace std;

int main(){
  
  int lenght = 256;
  vector<int> asciiArray;

  for(int start = 0; start < lenght; start++){
    asciiArray.push_back(start);
  }

  // Print the characters
  for (int start = 0; start < asciiArray.size(); start++) {
    char character = static_cast<char>(asciiArray[start]);
    cout << character << " ";
  }

  return 0;
}
