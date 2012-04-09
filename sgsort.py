# sgsort.py
# Author: George Lesica <glesica@gmail.com>
# Description: A Python implementation of Shotgun Sort.

import random


def sgsorted(iterable, reverse=False):
    """
    Accepts an iterable `iterable` and returns a copy of 
    it that has been sorted in ascending order.

    If `reverse` is True, descending order will be used.
    """
    def is_sorted(iterable):
        a = iterable[0]
        for i in iterable:
            if i < a:
                return False
            a = i
        return True

    l = iterable[:] # Makes a copy of iterable

    while (not is_sorted(l)):
        random.shuffle(l)

    if reverse:
        l.reverse()

    return l


if __name__ == '__main__':
    l = [3,2,4,1,5]
    print l
    print sgsorted(l)

    l = [5,4,6,3,7,2,9,8,1]
    print l
    print sgsorted(l)

