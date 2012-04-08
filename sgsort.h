/*
    shotgun.h
    Author: George Lesica <glesica@gmail.com>
    Description: An ANSI C implementation of the shotgun sorting algorithm.
*/

void sgsort(
    void * base, 
    size_t num, 
    size_t size, 
    int (*comparator) (const void *, const void *)
);

int int_compare(const void *a, const void *b);

