//
// Created by Damiene Andre Stewart on 3/9/16.
// Calculates the floor(sqrt(x));
//

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <time.h>

int iterative_dc(int);
int recursive_dc(int);
int recursive_dc_lr(int, int, int);

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("Usage: %s {int} {iterative|recursive}\n", argv[0]);
        exit(1);
    }

    int x = atoi(argv[1]);

    if (x < 0) {
        printf("Cannot take the square root of a negative number.\n");
        exit(1);
    }

    clock_t start = clock();
    printf("\nFloor(sqrt(%d) = %d (iterative) in time: %.4f s.\n", x, iterative_dc(x), (double)(clock() - start));
    start = clock();
    printf("Floor(sqrt(%d) = %d (recursive) in time: %.4f s.\n", x, recursive_dc(x), (double)(clock() - start));

    return 0;
}

// Iterative divide & conquer implementation.
int iterative_dc(int x) {
    int i;
    int fsqrt;
    int right = x/2;
    int left = 1;
    int mid;

    while (left <= right) {
        mid = (left + right) / 2;
        if (mid*mid == x) {
            fsqrt = mid;
            break;
        } else if (mid*mid < x) {
            fsqrt = mid;
            left = mid+1;
        } else {
            right = mid-1;
        }
    }
    return fsqrt;
}

// Recursive implementation.
int recursive_dc(int x) {
    return recursive_dc_lr(1, x/2, x);
}

// Recursive implementation.
int recursive_dc_lr(int a, int b, int x) {
    if (a > b)
        return b;

    int ret = 0;
    int mid = (a + b) / 2;
    if (mid*mid == x)
        return mid;
    else if (mid*mid < x)
        return recursive_dc_lr(mid+1, b, x);
    else
        return recursive_dc_lr(a, mid-1, x);
}
