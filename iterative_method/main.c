#include "base.h"
#include "iterative.h"

int main()
{
    double **A = NULL;
    double *b, *x;      // Vector b and initiative x
    int row, col;
    double i, j;
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
    //printf("Please enter the data of your matrix:\n");
    for (i = 1.0; i <= row; i++)
    {
        for (j = 1.0; j <= col; j++)
        {
            //scanf("%lf", &A[i][j]);
            A[(int)(i - 1)][(int)(j - 1)] = 1 / (i + j - 1);
        }
    }
    //printf("Please enter the right value of systems:\n");
    for (i = 1.0; i <= row; i++)
    {
        //scanf("%lf", &b[i]);
        b[(int)(i - 1)] = 0;   // clears array b
        for (j = 1.0; j <= col; j++)
        {
            b[(int)(i - 1)] += 1 / (i + j - 1);
        }
    }
    for (i = 0.0; i < row; i++)
    {
        x[(int)i] = 0.0;
    }
    // Use Jacobi iterative method
    //J_iterative_method(row, col, A, b, x, t);
    // Use Gsuss-Seidel iterative method
    //GS_iterative_method(row, col, A, b, x, t);
    // Use SOR iterative method
    SOR_iterative_method(row, col, A, b, x, t);

    printf("The solution set is:\n");
    for (i = 0.0; i < row; i++)
    {
        printf("%lf ", x[(int)i]);
    }
    printf("\n");
    free(A);
    free(b);
    return 0;
}

/*test data
3*3
8 -3 2
4 11 -1
6 3 12
 */
/*b
20
33
36
 */
