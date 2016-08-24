unsigned int verify(int input_size, double* output, int output_size) {
    double total_sum = 0;
    double checksum = 0;
    double eps = 0.000001 * ((double)output_size);

    for (int i = 0; i < output_size; ++i) {
        total_sum = (total_sum + output[i]);
    }

    checksum = floor(total_sum/eps);
    return (unsigned int)checksum;
}
