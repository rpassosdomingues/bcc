#include <stdio.h>

#define MAX_LENGTH 100

// Function to print the matrix
void printArray(int n, int array[MAX_LENGTH][MAX_LENGTH]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}

// Function to swap two rows of a matrix
void swapRows(int n, int array[MAX_LENGTH][MAX_LENGTH], int row1, int row2) {
    for (int j = 0; j < n; j++) {
        int temp = array[row1][j];
        array[row1][j] = array[row2][j];
        array[row2][j] = temp;
    }
}

// Function to calculate the determinant of a matrix
int calculateDeterminant(int n, int array[MAX_LENGTH][MAX_LENGTH]) {
    int det = 1;
    for (int i = 0; i < n; i++) {
        // Check if the diagonal element is zero and swap rows
        if (array[i][i] == 0) {
            int found = 0;
            for (int j = i + 1; j < n; j++) {
                if (array[j][i] != 0) {
                    swapRows(n, array, i, j);
                    det *= -1; // Swapping rows changes the sign of the determinant
                    found = 1;
                    break;
                }
            }
            if (!found) {
                return 0; // If no non-zero element is found, the determinant is zero
            }
        }
        for (int j = i + 1; j < n; j++) {
            int factor = array[j][i] / array[i][i];
            for (int k = i; k < n; k++) {
                array[j][k] -= factor * array[i][k];
            }
        }
        det *= array[i][i];
    }
    return det;
}

int main() {
    int n;
    int array[MAX_LENGTH][MAX_LENGTH];

    printf("Enter the value of n (n <= 100): ");
    scanf("%d", &n);
    while (n > MAX_LENGTH) {
        printf("Sorry, try again: ");
        scanf("%d", &n);
    }

    printf("\nEnter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("a[%d][%d]: ", i, j);
            scanf("%d", &array[i][j]);
        }
        printf("\n");
    }

    printf("Array:\n");
    printArray(n, array);

    int determinant = calculateDeterminant(n, array);
    printf("\nDeterminant: %d\n", determinant);

    return 0;
}
