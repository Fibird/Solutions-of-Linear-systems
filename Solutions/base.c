#include "base.h"

SWAP_VALUES(int)
SWAP_VALUES(double)
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

void output_L_matrix(int row, int col, double** a)
{
    int i, j;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            if (i < j)
            {
                printf("%lf ", 0.0);
            }
            else if (i == j)
            {
                printf("%lf ", 1.0);
            }
            else
            {
                printf("%lf ", a[i][j]);
            }
        }
        printf("\n");
    }
}

void output_U_matrix(int row, int col, double**a)
{
    int i, j;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            if (i > j)
            {
                printf("%lf ", 0.0);
            }
            else
            {
                printf("%lf ", a[i][j]);
            }
        }
        printf("\n");
    }
}

int select_pivot(int row, int col, double **a, int *p, double *b)
{
    int i;
    int t = 0;

    for (i = 1; i < row; i++)
    {
        if (fabs(a[t][col]) < fabs(a[i][col]))
        {
            t = i;
            int_swap(&p[t], &p[i]);
            double_swap(&b[t], &b[i]);
        }
    }
    return t;
}

