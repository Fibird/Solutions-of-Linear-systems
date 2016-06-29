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
        printf("Format Error! Please check your input!");
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
    no_swap_GR(row, col, A);

    printf("This is Matrix L:\n");
    output_L_matrix(row, col, A);
    printf("This is Matrix U:\n");
    output_U_matrix(row, col, A);

    printf("The solution set is:\n");
    solution_set(row, col, A, b);
    free(A);
    return 0;
}

// Experiment Data
/*matrix
3X3
2 3 1
4 1 4
3 4 6
*/

/*b
-4 9 0
*/
