void kernel(double* output, int output_size, double* input, int input_size) {
    if (input_size*input_size > output_size) {
        fprintf(stderr, "output matrix too small to hold the output\n");
    }

    // Multiply input by its transpose to create a 2D-matrix
    // output = input' * input;
    for (int col = 0; col < input_size; ++col) {
        for (int row = 0; row < input_size; ++row) {
            output[col*input_size+row] = input[row] * input[col];
        }  
    }

    // Add to itself
    for (int col = 0; col < input_size; ++col) {
        for (int row = 0; row < input_size; ++row) {
            output[col*input_size+row] *= output[col*input_size+row];
        }  
    }
}
