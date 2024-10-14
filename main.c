#include "neural.h"
//#include <stdio.h>


int main(void)
{
    const matrix A = init_matrix(2, 2,false);
    const matrix B = init_matrix(2, 2, true, 3.0, 10.0);
    set_element(A, 0,0,1);
    set_element(A,0,1,0);
    set_element(A,1,0,0);
    set_element(A,1,1,1);
    const matrix res=dot_product_matrix(A,B);
    print_matrix(res);

    return 0;
}
