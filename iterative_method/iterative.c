#include "iterative.h"

void iterative_method(int row, int col, double **a, double *b, double *x, int t)
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

