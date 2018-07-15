#include "base.h"
#include "solutions.h"

int main()
{
    double **A = NULL;
    double *b;      // Vector b
    int row, col;
    int i, j;

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
    b = (double*) malloc(col * sizeof(double));
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
    for (i = 0; i < col; i++)
    {
        scanf("%lf", &b[i]);
    }
    // Use LU reduction which don't swap lines
    GR(row, col, A, b);

    for (i = 0; i < row; ++i)
    {
        for ( j = 0; j < col; ++j)
        {
            printf("%lf ", A[i][j]);
        }
        printf("\n");
    }
/*    printf("This is Matrix L:\n");
    output_L_matrix(row, col, A);
    printf("This is Matrix U:\n");
    output_U_matrix(row, col, A);

    printf("The solution set is:\n");
    solution_set(row, col, A, b);*/
    free(A);
    return 0;
}

// Experiment Data
/*matrix1
3*3
2 3 1
4 1 4
3 4 6
*/

/*b
-4 9 0
*/

/*matrix2
3*3
6 -4 2
4 2 1
2 -1 1
*/

/*b
-2 4 -1
*/

/*matrix3
4*4
10 -7 0 1
-3 2.099999 6 2
5 -1 5 -1
2 1 0 2
*/

/*b
8 5.900001 5 1
*/
