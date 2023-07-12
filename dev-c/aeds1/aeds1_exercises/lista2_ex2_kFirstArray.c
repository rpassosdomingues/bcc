/*
Exercise 2: Modify the sort by selection algorithm to sort only the k
first values of a vector of 100 elements of integer type. The value k must be read.
*/

# include <stdio.h>

# define MAX_LENGTH 10

void printArray (int k, int array[]) {
  for (int i = 0; i < k; i++) {
    printf(" %d", array[i]);
  }
  printf("\n");
}

void swap (int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void selectionSort (int length, int array[MAX_LENGTH]) {
  for (int i = 0; i < length - 1; i++) {
    int minIndex = i;
    for (int j = i + 1; j < length; j++) {
      if (array[j] < array[minIndex]) {
        minIndex = j;
      }
    }
    swap(&array[i], &array[minIndex]);
  }
}

int main () {
  
  // Build the array
  int array[MAX_LENGTH];
  printf("\n Enter a elements of array \n");
  for (int i = 0; i < MAX_LENGTH; i++) {
    printf("\n\t Enter a %d value: ", i+1);
    scanf(" %d", &array[i]);
  }

  int k;
  printf("\n Enter a [k <= 10] value: ");
  scanf(" %d", &k);
  while (k > MAX_LENGTH) {
    printf("\n\t Sorry, try again: ");
    scanf(" %d", &k);
  }

  // Passes the array to sort function
  selectionSort(k, array);

  // Show sort array
  printf("\n The first %d sort elements: ", k);
  printArray(k, array);

  return 0;

}