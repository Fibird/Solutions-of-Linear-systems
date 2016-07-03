#include "base.h"

double** memory_allocation(int row, int col, double **a)
{
    int i;
    a = (double**) malloc(row * sizeof(double));
    if (a == NULL)
    {
        printf("Allocation Failed!");
        exit(EXIT_FAILURE);
    }
    for (i = 0; i < row; i++)
    {
        a[i] = (double*) malloc(col * sizeof(double));
        if (a[i] == NULL)
        {
            printf("Allocation Failed!");
            exit(EXIT_FAILURE);
        }
    }
    return a;
}

