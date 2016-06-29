#include "solutions.h"
#include "base.h"

void GR(int row, int col, double **a, double *b)
{
    int i, k, j;
    double m;  // Multipliers
    // array is used to swap lines
    int p[row];
    for (i = 0; i < row; i++)
    {
        p[i] = i;
    }
    for (i = 0; i < row; i++)
    {
        select_pivot(row, i, a, p, b);
        for (k = i + 1; k < row; k++)
        {// Assuming a[i][i] <> 0
            m = a[p[k]][i] / a[p[i]][i];      // Computes the Multipliers
            for (j = i + 1; j < row; j++)
            {
                a[p[k]][j] = a[p[k]][j] - m * a[p[i]][j];
            }
            a[p[k]][i] = m;
        }
    }
}

void solution_set(int row, int col, double **a, double *b)
{
    int i, j;
    double y[col + 1], x[col + 1];
    double t = 0.0;

    // Forward substitution
    for (i = 0; i < row; i++)
    {
        t = 0.0;    // Must be cleared to 0
        for (j = 0; j < i; j++)
        {
            if (i == 0)
            {
                t = 0;
                continue;
            }
            t += a[i][j] * y[j];
        }
        y[i] = b[i] - t;
    }

    // Back substitution
    for (i = col - 1; i >= 0; i--)
    {
        t = 0.0;    // Must be cleared to 0
        for (j = i + 1; j < col; j++)
        {
            if (i == col - 1)
            {
                t = 0.0;
                continue;
            }
            t += x[j] * a[i][j];
        }
        x[i] = ((y[i] - t) / a[i][i]);
    }
    // Outputs solution set of this linear systems
    for (i = 0; i < col; i++)
    {
        printf("%lf ", x[i]);
    }
    printf("\n");
}
