#ifndef SOLUTIONS_H_INCLUDED
#define SOLUTIONS_H_INCLUDED

// Gauss-Jordan reduction(no line swap)
void GR(int row, int col, double **a, double *b);
// Computes the solution set of the systems
void solution_set(int row, int col, double **a, double *b);
#endif // SOLUTIONS_H_INCLUDED
