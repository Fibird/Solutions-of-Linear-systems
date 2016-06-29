#ifndef BASE_H_INCLUDED
#define BASE_H_INCLUDED
/****************************************************
*   function: Finishes base work like allocating memory,
    swapping lines of matrix.
*****************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// Swaps values of element
#define SWAP_VALUES(type)       \
void type##_swap(type *l, type *r)  \
{                   \
    type t;         \
    t = *l;         \
    *l = *r;        \
    *r = t;         \
}

// Memory Allocation
double** memory_allocation(int, int, double**);
// Outputs matrix L
void output_L_matrix(int, int, double**);
// Outputs matrix U
void output_U_matrix(int, int, double**);
// Selects the pivot and reorders b
int select_pivot(int row, int col, double **a, int* p, double *b);

#endif // BASE_H_INCLUDED
