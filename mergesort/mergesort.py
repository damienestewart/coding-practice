__author__ = 'Damiene'
# Learning Python: Merge Sort

import math

x = [1, 12, 99, 84, 3, 6, 7, 2, -8, 20]

def merge(left, right):
    new_list = []
    left_counter = 0
    right_counter = 0

    left_len = len(left)
    right_len = len(right)

    total = left_len + right_len

    for i in range(0, total):
        if left_counter > left_len - 1 or right_counter > right_len - 1:
            if left_counter > left_len - 1:
                new_list.extend(right[right_counter:])
                break
            else:
                new_list.extend(left[left_counter:])
                break

        if left[left_counter] < right[right_counter]:
            new_list.append(left[left_counter])
            left_counter += 1
        else:
            new_list.append(right[right_counter])
            right_counter += 1

    return new_list

def mergesort(the_list):

    if len(the_list) == 1:
        return the_list

    mid = math.floor(len(the_list) / 2)
    left = the_list[0:mid]
    right = the_list[mid:]

    new_left = mergesort(left)
    new_right = mergesort(right)

    return merge(new_left, new_right)

def main():
    print('Original list: {}'.format(x))
    print('Sorted list: {}'.format(mergesort(x)))

if __name__ == '__main__': main()
