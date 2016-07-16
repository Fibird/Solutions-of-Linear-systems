#ifndef ITERATIVE_H_INCLUDED
#define ITERATIVE_H_INCLUDED
#include "base.h"
#define omega 1.5

// Use Gauss-Seidel iterative method
void GS_iterative_method(int row, int col, double **a, double *b, double *x, int t);
// Use Jacobi iterative method
void J_iterative_method(int row, int col, double **a, double *b, double *x, int t);
// Use successive over relaxation method
void SOR_iterative_method(int row, int col, double **a, double *b, double *x, int t);
#endif // ITERATIVE_H_INCLUDED
