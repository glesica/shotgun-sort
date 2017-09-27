/*
 * shotgun.c
 * Author: George Lesica <george@lesica.com>
 * Description: An ANSI C implementation of the "shotgun sort" algorithm.
 *
 */

#include <stdlib.h>
#include <string.h>

/* Private utility functions. */

int sorted(
    const void *base,
    size_t num,
    size_t size,
    int (*comparator) (const void *, const void *)
) {
    int i;

    char *b = (char *) base;

    for (i=1; i<num; i++) {
        if (comparator(&b[(i-1)*size], &b[i*size]) > 0) {
            return 0;
        }
    }
    return 1;
}

void randomize(
    void *base,
    size_t num,
    size_t size
) {
    size_t i, j;
    char *b = (char *) base;
    void *temp = malloc(size);

    for (i=0; i<num; i++) {
        j = rand() % num;
        memcpy(temp, &b[i*size], size);
        memcpy(&b[i*size], &b[j*size], size);
        memcpy(&b[j*size], temp, size);
    }

    free(temp);
}

/* Public Functions */

int int_compare(const void *a, const void *b) {
    return (*(int *) a - *(int *) b);
}

void sgsort(
    void *base, 
    size_t num, 
    size_t size, 
    int (*comparator) (const void *, const void *)
) {
    /* Loop until the array is sorted */
    while (! sorted(base, num, size, comparator)) {
        randomize(base, num, size);
    }

}

