#include "neural.h"
#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

st_neural init_neural(const size_t* layers, const size_t layers_count) {
    if(layers_count<=0)
    {
        perror("Invalid number of layers!\n");
        exit(EXIT_FAILURE);
    }
    st_neural network;
    network.inner_layer_count = layers_count - 1;

    network.weights = malloc(sizeof(network.weights[0]) * network.inner_layer_count);
    if (!network.weights) {
        perror("Malloc error for weights!\n");
        exit(EXIT_FAILURE);
    }

    network.biases = malloc(sizeof(network.biases[0]) * network.inner_layer_count);
    if (!network.biases) {
        perror("Malloc error for biases!\n");
        free(network.weights);
        exit(EXIT_FAILURE);
    }

    network.activations = malloc(sizeof(network.activations[0]) * (1+network.inner_layer_count));
    if (!network.activations) {
        perror("Malloc error for activations!\n");
        free(network.weights);
        free(network.biases);
        exit(EXIT_FAILURE);
    }
    network.activations[0]=init_matrix(1,layers[0],false);
    for(size_t i=0;i<network.inner_layer_count;++i)
    {
        network.weights[i]=init_matrix(network.activations[i].cols,layers[i+1],false);
        network.biases[i]=init_matrix(1,layers[i+1],false);
        network.activations[i+1]=init_matrix(1,layers[i+1],false);

    }
    return network;
}

