#include <stdio.h>
#include "utils.hpp"
#include "MatrixFunctions.hpp"

double* GetElementPtr(const Matrix* matrix, size_t i, size_t j);

void PrintMatrix(const Matrix* matrix, FILE* file)
{
    MyAssertHard(matrix, ERROR_NULLPTR, );

    fprintf(file, "%14lu ", 0lu);
    for (size_t j = 1; j < matrix->cols; j++)
        fprintf(file, "%10lu ", j);
    fprintf(file, "\n");

    for (size_t i = 0; i < matrix->rows; i++)
    {
        fprintf(file, "%3lu ", i);
        for (size_t j = 0; j < matrix->cols; j++)
            fprintf(file, "%10.2lf ", *GetElementPtr(matrix, i, j));
        fprintf(file, "\n");
    }
    fprintf(file, "\n");
}

Matrix* MatrixProduct(const Matrix* A, const Matrix* B, Matrix* C)
{
    MyAssertHard(A, ERROR_NULLPTR, );
    MyAssertHard(B, ERROR_NULLPTR, );
    MyAssertHard(C, ERROR_NULLPTR, );

    if (A->cols != B->rows)
        return NULL;

    for (size_t i = 0; i < C->rows; i++)
        for (size_t j = 0; j < C->cols; j++)
        {
            double sum = 0;
            for (size_t k = 0; k < A->cols; k++)
                sum += *GetElementPtr(A, i, k) * *GetElementPtr(B, k, j);
            *GetElementPtr(C, i, j) = sum;
        }
    return C;
}


double* GetElementPtr(const Matrix* matrix, size_t i, size_t j)
{
    MyAssertHard(matrix, ERROR_NULLPTR, );

    return (double*)((size_t)matrix->elements + (i * matrix->cols + j) * sizeof(double));
}
void PrintTriangleMatrix(const TriangleMatrix* triMatrix, FILE* file)
{
    MyAssertHard(triMatrix, ERROR_NULLPTR, );

    fprintf(file, "%9lu ", 0lu);
    for (size_t j = 1; j < triMatrix->size - 1; j++)
        fprintf(file, "%5lu ", j);
    fprintf(file, "\n");

    for (size_t i = 0; i < triMatrix->size; i++)
    {
        printf("%3lu ", i);
        for (size_t j = 0; j < i; j++)
            fprintf(file, "%5d ", *GetTriangleElementPtr(triMatrix, i, j));
        fprintf(file, "\n");
    }
    fprintf(file, "\n");
    
}


int* GetTriangleElementPtr(const TriangleMatrix* triMatrix, size_t i, size_t j)
{
    if (i < j)
    {
        i += j;
        j = i - j;
        i -= j;
    }
    return triMatrix->elements + i * (i + 1) / 2 + j;
}