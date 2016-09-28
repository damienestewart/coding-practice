__author__ = 'Damiene'
# Learning python: binary search.

import math

def _binarysearch(n, left, right, search_list):

    if left > right:
        return -1

    mid = math.floor((left + right) / 2)
    mid_value = search_list[mid]

    if n == mid_value:
        return mid
    elif n < mid_value:
        return _binarysearch(n, left, mid-1, search_list)
    elif n > mid_value:
        return _binarysearch(n, mid+1, right, search_list)

def binarysearch(n, search_list):
    list_length = len(search_list)

    if list_length == 0:
        raise ValueError('List is empty.')

    return _binarysearch(n, 0, list_length-1, search_list)


def main():
    x = [0, 3, 4, 8, 29]
    print(binarysearch(8, x))

if __name__ == '__main__': main()