#ifndef NEURAL_H
#define NEURAL_H

#include <stddef.h>
#include "matrix.h"

#define LEN(arr) sizeof(arr)/sizeof(arr[0])

typedef struct {
    size_t inner_layer_count;
    matrix* weights;
    matrix* biases;
    matrix* activations;
}st_neural;

st_neural init_neural(size_t* layers,size_t layers_count);

#endif //NEURAL_H
