#ifndef MATRIX_FUNCTIONS_HPP
#define MATRIX_FUNCTIONS_HPP

#include <stddef.h>
#include <stdio.h>

struct Matrix
{
    double* elements;
    size_t rows;
    size_t cols;
};

struct TriangleMatrix
{
    int* elements;
    size_t size;    
};

void PrintMatrix(const Matrix* matrix, FILE* file);

Matrix* MatrixProduct(const Matrix* A, const Matrix* B, Matrix* C);

double* GetElementPtr(const Matrix* matrix, size_t i, size_t j);

void PrintTriangleMatrix(const TriangleMatrix* matrix, FILE* file);

int* GetTriangleElementPtr(const TriangleMatrix* matrix, size_t i, size_t j);


#endif
