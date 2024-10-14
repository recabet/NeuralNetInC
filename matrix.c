#include "matrix.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>



double get_rand_double(const double low, const double high)
{
    return (double) rand() / (double) RAND_MAX * (high - low) + low;
}

double get_element(const matrix A, const size_t row, const size_t col)
{
    if (!A.start)
    {
        perror("Matrix uninitialized!\n");
        exit(EXIT_FAILURE);
    }
    if (row > A.rows || col > A.cols)
    {
        perror("Invalid index!\n");
        exit(EXIT_FAILURE);
    }
    return *(A.start + A.cols * (row) + col);
}


void set_element(const matrix A, const size_t row, const size_t col, const double val)
{
    if (!A.start)
    {
        perror("Matrix uninitialized!\n");
        exit(EXIT_FAILURE);
    }
    *(A.start + A.cols * (row) + col) = val;
}


void matrix_fill(const matrix A,const double val)
{
    if(!A.start)
    {
        perror("Matrix uninitialized!\n");
        exit(EXIT_FAILURE);
    }
    for (size_t i=0;i<A.rows;++i)
    {
        for (size_t j=0;j<A.cols;++j)
        {
            set_element(A,i,j,val);
        }
    }
}

matrix randomize_matrix(const matrix A, const double low, const double high)
{
    if(!A.start)
    {
        perror("Matrix uninitialized!\n");
        exit(EXIT_FAILURE);
    }
    for (size_t i = 0; i < A.rows; ++i)
    {
        for (size_t j = 0; j < A.cols; ++j)
        {
            set_element(A, i, j, get_rand_double(low, high));
        }
    }
    return A;
}

matrix init_matrix(const size_t rows, const size_t cols, const bool randomize, ...)
{
    matrix A = {
        .rows = rows,
        .cols = cols,
        .start = malloc(rows * cols * sizeof(double))
    };

    if (!A.start)
    {
        perror("Could not initialize the matrix!\n");
        exit(EXIT_FAILURE);
    }

    if (randomize)
    {
        va_list list;
        va_start(list, randomize);
        const double low = va_arg(list, double);
        const double high = va_arg(list, double);
        va_end(list);

        A = randomize_matrix(A, low, high);
    }

    return A;
}

void print_matrix(const matrix A)
{
    if(!A.start)
    {
        perror("Matrix uninitialized!\n");
        exit(EXIT_FAILURE);
    }
    for (size_t i = 0; i < A.rows; ++i)
    {
        for (size_t j = 0; j < A.cols; ++j)
        {
            printf("%lf ", get_element(A, i, j));
        }
        putchar('\n');
    }
}

void add_matrix(const matrix res, const matrix B)
{
    if(!B.start||!res.start)
    {
        perror("Matrix uninitialized!\n");
        exit(EXIT_FAILURE);
    }
    if (res.cols != B.cols || res.rows != B.rows)
    {
        perror("Invalid sizes!\n");
        exit(EXIT_FAILURE);
    }
    for (size_t i = 0; i < res.rows; i++)
    {
        for (size_t j = 0; j < res.cols; j++)
        {
            set_element(res, i, j, (get_element(B, i, j) + get_element(res, i, j)));
        }
    }
}

matrix dot_product_matrix(const matrix A, const matrix B)
{
    if (!A.start || !B.start)
    {
        perror("Uninitialized matrices!\n");
        exit(EXIT_FAILURE);
    }

    if (A.cols != B.rows)
    {
        perror("Size mismatch for matrix multiplication!\n");
        exit(EXIT_FAILURE);
    }

    const matrix res = {
        .rows = A.rows,
        .cols = B.cols,
        .start = malloc(A.rows * B.cols * sizeof(double))
    };

    if (!res.start)
    {
        perror("Could not allocate memory for result matrix!\n");
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < A.rows; ++i)
    {
        for (size_t j = 0; j < B.cols; ++j)
        {
            double sum = 0.0;
            for (size_t k = 0; k < A.cols; ++k)
            {
                sum += get_element(A, i, k) * get_element(B, k, j);
            }
            set_element(res, i, j, sum);
        }
    }

    return res;
}
