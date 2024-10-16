#ifndef MATRIX_H
#define MATRIX_H

#include <stddef.h>
#include <stdbool.h>


typedef struct {
    size_t rows;
    size_t cols;
    //size_t stride;
    double* start;
} matrix;

double get_rand_double(double low, double high);

double get_element(matrix A, size_t row, size_t col);

void set_element(matrix A, size_t row, size_t col, double val);

void matrix_fill(matrix A,double val);

matrix init_matrix(size_t rows, size_t cols,bool randomize, ...);

matrix randomize_matrix(matrix A, double low, double high);

matrix dot_product_matrix(matrix A, matrix B);

void add_matrix(matrix res, matrix B);

void print_matrix(matrix A);

#endif //MATRIX_H
