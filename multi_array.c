#include <stdio.h>

#define ROWS 3
#define COLS 3

/* Function declaration */
void inputMatrix(int (*mat)[COLS]);
void printMatrix(int mat[][COLS]);

int main()
{
    int mat[ROWS][COLS];

    // Input elements in matrix using function
    inputMatrix(mat);

    // Print elements of matrix using function
    printMatrix(mat);

    return 0;
}

/**
 * Function to accept a two dimensional array and input
 * elements in matrix from user.
 *
 * @mat     Two dimensional integer array to store user input.
 */
void inputMatrix(int (*mat)[COLS])
{
    int i, j;

    // Input elements in 2D matrix
    printf("Enter elements in 2D matrix: \n");
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            scanf("%d", (*(mat + i) + j));
        }
    }
}

/**
 * Function to accept a two dimensional array and print
 * its elements.
 *
 * @mat     Two dimensional integer array to print.
 */
void printMatrix(int (*mat)[COLS])
{
    int i, j;

    // Print elements of two dimensional array.
    printf("Elements in matrix: \n");
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            printf("%d ", *(*(mat + i) + j));
        }
        printf("\n");
    }
}
