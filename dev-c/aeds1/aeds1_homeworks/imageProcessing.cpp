#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

typedef int tImage[1000][1000];

string error;

int uploadPGM (string name, tImage image, int *lines, int *columns, int *tones) {
  
  string type;
  ifstream file(name);
  if (!file.is_open()) {
    error = "Error: File not found.";
    return 1;
  }

  file >> type;
  if (type != "P2") {
    error = "Error: The file don't have P2 format.";
    return 2;
  }

  file >> *columns >> *lines >> *tones;
  for (int i = 0; i < *lines; i++) {
    for (int j = 0; j < *columns; j++) {
      file >> image[i][j];
    }
  }
  file.close();
  return 0;
}

int savePGM(string name, tImage image, int lines, int columns, int tones){
  ofstream file(name);
  if (!file.is_open()){
    error = "Error: File not found."; 
    return 1;
  }

  file << "P2" << endl << columns << " " << lines << endl << tones << endl;
  for (int i = 0; i < lines; i++){
    for (int j = 0; j < columns; j++){
      file << image[i][j] << " ";
    }
    file << endl;
  }
  file.close();
  return 0;
}

/*
 * Read and Write of files in PGM format PGM with functions.
 */
int main (void) {
  
  tImage inputImage, outputImage;
  int columns = 10, lines = 10, tones;
  string inputFile, outputFile;

  // Read file of image input.    
  cout << " Enter a input image name: ";
  cin >> inputFile;
  inputFile = inputFile + ".pgm";
  if (uploadPGM(inputFile, inputImage, &lines, &columns, &tones) != 0){
    cout << "\n" + error + "\n";
    return 1;
  }
    
  // Building the negative image.
  for (int i = 0; i < lines; i++){
    for (int j = 0; j < columns; j++){
      outputImage[j][i] = tones - inputImage[i][j];
    }
  }
    
  // Writing the image output file.
  cout << " Enter a output image name: ";
  cin >> outputFile;
  outputFile = outputFile + ".pgm";
  if (savePGM(outputFile, outputImage, columns, lines, tones) != 0){
    cout << "\n" + error + "\n";
    return 1;
  }
 
  return 0;
}
