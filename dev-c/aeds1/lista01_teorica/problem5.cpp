#include <iostream>
#include <cmath>

using namespace std;

int main(void){
    
  // variable declaration
  long int n, factorialN;
  float x, sum, numTerms, numerator, denominator, nextTerm;

  // variable initialization
  sum = 0.0;
  numTerms = 1.0;

  numerator = 1.0;
  denominator = 1.0;

  nextTerm = 1.0;

  // read input
  cout << "\n x = ";
  cin >> x;
    
  cout << "\n n = ";
  cin >> n;

  factorialN = 1;
  while(n > 0){
    factorialN = n * factorialN;
    n--;
  }

  while (nextTerm < factorialN){
    numerator += pow(x,n);
    denominator += n;
    nextTerm = numerator/denominator;

    sum += nextTerm;

    n++;
    numTerms++;
  }
    
  // write results
  cout << "\n\t exp(x) = " << sum << "\t|\t The series has " << numTerms << " terms. \n\n";

  return 0;
}
