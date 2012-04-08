/*
    demo.c
    Author: George Lesica <glesica@gmail.com>
    Description: Demo program for shotgun sort.
*/

#include <stdio.h>
#include "sgsort.h"

void print_array(void *base, size_t num, size_t size) {
    int i;
    int *b = (int *) base;

    for (i=0; i<num; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");
}

int main() {
    int i;
    int test[] = {3,2,4,1,5};

    print_array(test, 5, sizeof(int));
    sgsort(test, 5, sizeof(int), int_compare);
    print_array(test, 5, sizeof(int));
}

