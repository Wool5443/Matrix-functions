#include <stdio.h>
#include "MatrixFunctions.hpp"

int main()
{
    double Aels[5][5] = 
    {
        { 0,  1,  2,  3,  4},
        {10, 11, 12, 13, 14},
        {20, 21, 22, 23, 24},
        {30, 31, 32, 33, 34},
        {40, 41, 42, 43, 44}
    };

    double Bels[5][1] = 
    {
        {1},
        {1},
        {1},
        {1},
        {1}
    };

    double Cels[5][1] = 
    {
        {0},
        {0},
        {0},
        {0},
        {0}
    };

    Matrix A = {.elements = (double*)Aels, .rows = 5, .cols = 5};
    Matrix B = {.elements = (double*)Bels, .rows = 5, .cols = 1};
    Matrix C = {.elements = (double*)Cels, .rows = 5, .cols = 1};

    MatrixProduct(&A, &B, &C);

    PrintMatrix(&A, stdout);

    PrintMatrix(&B, stdout);

    PrintMatrix(&C, stdout);

    int scores[] = 
    {
        1,
        2, 0,
        -1, -2, 1,
        5, 6, 1, 0,
        3, -1, 2, 4, 5
    };

    TriangleMatrix triMatrix = {.elements = scores, .size = 5};

    PrintTriangleMatrix(&triMatrix, stdout);

    return 0;
}