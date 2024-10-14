#include "matrix.h"
//#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    srand(time(0));
    const matrix A = init_matrix(2, 2,false);
    const matrix B = init_matrix(2, 2, true, 3.0, 10.0);
    set_element(A, 0,0,1);
    set_element(A,0,1,0);
    set_element(A,1,0,0);
    set_element(A,1,1,1);
    const matrix res=dot_product_matrix(A,B);
    print_matrix(res);
    matrix_fill(A,1.0);
    print_matrix(A);

    return 0;
}
