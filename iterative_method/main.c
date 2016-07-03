#include "base.h"
#include "iterative.h"

int main()
{
    double **A = NULL;
    double *b, *x;      // Vector b and initiative x
    int row, col;
    int i, j;
    int t = 7;              // Times of iterative

    printf("Please enter the size of your matrix(row*col): ");
    scanf("%d*%d", &row, &col);
    while (row != col)
    {
        // row must be equal to col
        printf("Format Error! Please check your input!\n");
        exit(EXIT_FAILURE);
    }
    // Memory Allocation
    A = memory_allocation(row, col, A);
    b = (double*) malloc(row * sizeof(double));
    x = (double*) malloc(row * sizeof(double));
    // Inputs data
    printf("Please enter the data of yout matrix:\n");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            scanf("%lf", &A[i][j]);
        }
    }
    printf("Please enter the right value of systems:\n");
    for (i = 0; i < row; i++)
    {
        scanf("%lf", &b[i]);
    }
    for (i = 0; i < row; i++)
    {
        x[i] = 0.0;
    }

    // Use iterative method
    iterative_method(row, col, A, b, x, t);

    printf("The solution set is:\n");
    for (i = 0; i < row; i++)
    {
        printf("%lf ", x[i]);
    }
    printf("\n");
    free(A);
    free(b);
    return 0;
}
