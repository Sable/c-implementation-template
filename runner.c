#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "common.h"
#include "ostrich_twister_rand.h"
#include "./kernel.c"
#include "./verify.c"

int main(int argc, char** argv) {
    int input_size = 0;
    int output_size = 0;
    double elapsedTime = 0.0;
    unsigned int checksum = 0;
    stopwatch timer;

    if (argc < 2) {
        fprintf(stderr, "usage: %s <input_size>\n", argv[0]);
        return 1;
    }
    input_size = atoi(argv[1]);
    output_size = input_size * input_size;

    // Create or load input data
    double* input = (double*)malloc(input_size*sizeof(double));
    double* output = (double*)malloc(output_size*sizeof(double));
    ostrich_rand_matrix(input, 1, input_size);
    
    // Run kernel and measure time for core computation
    stopwatch_start(&timer);
    kernel(output, input_size*input_size, input, input_size);
    stopwatch_stop(&timer);
    elapsedTime = get_interval_by_sec(&timer); 

    // Verify output
    checksum = verify(input_size, output, output_size); 

    // Display output
    printf("{ \"input\": %d, \"time\": %f, \"output\": %d}", input_size, elapsedTime, checksum);
    
    return 0;    
}
