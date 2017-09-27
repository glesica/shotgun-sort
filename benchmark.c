/*
 * benchmark.c
 * Author: George Lesica <george@lesica.com>
 * Description: Benchmark for shotgun sort.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "sgsort.h"

int max_length = 0;
int num_iters = 10;

int main(int argc, char **argv) {
    if (argc < 2 || argc > 3) {
        fprintf(stderr, "Usage: benchmark <max length> [iterations]");
        return 1;
    }

    if (argc >= 2) {
        max_length = atoi(argv[1]);
    }

    if (argc == 3) {
        num_iters = atoi(argv[2]);
    }

    if (max_length == 0) {
        fprintf(stderr, "Invalid max length: %s", argv[1]);
        return 1;
    }

    if (num_iters == 0) {
        fprintf(stderr, "Invalid iterations: %s", argv[2]);
        return 1;
    }

    int *arr = calloc(max_length, sizeof(int));

    int len;
    for (len = 2; len <= max_length; len++) {
        int iter;
        for (iter = 0; iter < num_iters; iter++) {

            int i = 0;
            for (i = 0; i < len; i++) {
                arr[i] = rand();
            }

            sgsort(arr, (size_t) len, sizeof(int), int_compare);
        }
    }

    free(arr);
}
