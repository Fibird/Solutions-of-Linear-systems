#include "solutions.h"

void no_swap_GR(int row, int col, double **a)
{
    int i, k, j;
    double m;  // Multipliers
    for (i = 0; i < row - 1; i++)
    {
        for (k = i + 1; k < row; k++)
        {// Assuming a[i][i] <> 0
            m = a[k][i] / a[i][i];      // Computes the Multipliers
            for (j = i + 1; j < row; j++)
            {
                a[k][j] = a[k][j] - m * a[i][j];
            }
            a[k][i] = m;
        }
    }
}
