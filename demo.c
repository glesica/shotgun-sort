/*
    demo.c
    Author: George Lesica <glesica@gmail.com>
    Description: Demo program for shotgun sort.
*/

#include <stdio.h>
#include "sgsort.h"

void test(
    void *base,
    size_t num,
    size_t size,
    int (*comparator) (const void *, const void *)
) {
    int i;
    
    /* Assumes the test array is type int because I'm lazy. */
    int *b = (int *) base;

    /* Output the original ordering. */
    printf("Original: ");
    for (i=0; i<num; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");

    /* Release the hounds! */
    sgsort(base, num, sizeof(int), comparator);

    /* Output the (hopefully) sorted ordering. */
    printf("Sorted:   ");
    for (i=0; i<num; i++) {
        printf("%d ", b[i]);
    }
    printf("\n\n");
}

int main() {
    int test1[] = {3,2,4,1,5};
    test(test1, 5, sizeof(int), int_compare);

    int test2[] = {5,4,3,2,1};
    test(test2, 5, sizeof(int), int_compare);

    int test3[] = {5,9,1,8,2,7,4,6,3};
    test(test3, 9, sizeof(int), int_compare);
}

