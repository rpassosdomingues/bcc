/*
Exercise 3: Develop an algorithm that reads a matrix of nxn (for n ≤ 100) values
values, calculate and display the transpose of this matrix.
*/

# include <stdio.h>

# define MAX_LENGTH 100

// Function to transpose the array
void transposeArray (int n, int array[MAX_LENGTH][MAX_LENGTH]) {
  int transpose[MAX_LENGTH][MAX_LENGTH];
  // Calculation of the transposed array
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      transpose[i][j] = array[j][i];
    }
    printf("\n");
  }

  // Show the array transposed
  printf("Transposed Array \n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf(" %d ", transpose[i][j]);
    }
    printf("\n");
  }
}

int main () {
  int n;
  int array[MAX_LENGTH][MAX_LENGTH];

  printf("Enter a [n <= 100] value: ");
  scanf(" %d", &n);
  while (n > MAX_LENGTH) {
    printf("Sorry, try again: ");
    scanf(" %d", &n);
  }
  
  // Build the array
  printf("\n Enter a elements of array: \n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("a[%d][%d]: ", i,j);
      scanf(" %d", &array[i][j]);
    }
    printf("\n");
  }

  // Passes the array to the transpose function
  transposeArray(n, array);
  
  return 0;
}
