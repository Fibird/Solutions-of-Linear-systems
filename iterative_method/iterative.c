#include "iterative.h"

void GS_iterative_method(int row, int col, double **a, double *b, double *x, int t)
{
    int i, j, k;
    double sum = 0.0;
    for (k = 0; k < t; k++)
    {
        for (i = 0; i < row; i++)
        {
            sum = 0.0;      // Sum must be cleared to 0
            for (j = 0; j < col; j++)
            {
                if (j == i)
                    continue;
                sum += a[i][j] * x[j];
            }
            x[i] = (b[i] - sum) / a[i][i];
        }
    }
}

void J_iterative_method(int row, int col, double **a, double *b, double *x, int t)
{
    int i, j, k;
    double sum = 0.0;
    double *temp_x = (double*) malloc(row * sizeof(double));

    for (k = 0; k < t; k++)
    {
        for (i = 0; i < row; i++)
        {
            sum = 0.0;      // Sum must be cleared to 0
            for (j = 0; j < col; j++)
            {
                if (j == i)
                    continue;
                sum += a[i][j] * x[j];
            }
            temp_x[i] = (b[i] - sum) / a[i][i];
        }
        for (i = 0; i < row; i++)
        {
            x[i] = temp_x[i];
        }
    }
    free(temp_x);
}

void SOR_iterative_method(int row, int col, double **a, double *b, double *x, int t)
{
    int i, j, k;
    double sum = 0.0;

    for (k = 0; k < t; k++)
    {
        for (i = 0; i < row; i++)
        {
            sum = 0.0;      // Sum must be cleared to 0
            for (j = 0; j < col; j++)
            {
                sum += a[i][j] * x[j];
            }
            x[i] = (x[i] + omega * (b[i] - sum)) / a[i][i];
        }
    }
}
