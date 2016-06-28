//#include <stdio.h>
//#include <stdlib.h>
#include "base.h"

int main()
{
    double **A = NULL;
    int row, col;
    int i, j;

    printf("Please enter the size of your matrix(row X col): ");
    scanf("%dX%d", &row, &col);
    while (row != col)
    {
        // row must be equal to col
        printf("Format Error! Please check your input!");
        exit(EXIT_FAILURE);
    }
    // Memory Allocation
    A = memory_allocation(row, col, A);

    // Inputs data
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            scanf("%lf", &A[i][j]);
        }
    }
    no_swap_GR(row, col, A);
    printf("This is Matrix L:\n");
    output_L_matrix(row, col, A);
    printf("This is Matrix U:\n");
    output_U_matrix(row, col, A);

    return 0;
}
