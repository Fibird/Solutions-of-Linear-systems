#ifndef BASE_H_INCLUDED
#define BASE_H_INCLUDED
/****************************************************
*   function: Finishes base work like allocating memory,
    swapping lines of matrix.
*****************************************************/
#include <stdlib.h>
#include <stdio.h>
// Memory Allocation
double** memory_allocation(int, int, double**);
// Output matrix L
void output_L_matrix(int, int, double**);
// Output matrix U
void output_U_matrix(int, int, double**);
#endif // BASE_H_INCLUDED
