// http://www.geeksforgeeks.org/find-the-element-that-appears-once-in-a-sorted-array/
// Find the element that appears only once in logn time.

#include <stdio.h>
#include <stdlib.h>

int appears_once(int *, int);

int main(int argc, char *argv[]) {

    if (argc < 4) {
        printf("You must provide at least 3 elements.");
        exit(1);
    }

    int count = argc-1;

    if (argc-1 % 2 == 0) {
        printf("You have an even number of elements. I know what you're doing. Stop.");
        exit(1);
    }

    int elements[count];

    int i ;
    for(i = 0; i < count; i++) {
        elements[i] = atoi(argv[i+1]);
    }

    printf("The element that appears once is %d.", appears_once(elements, count));

    return 0;
}

int appears_once(int *elements, int count) {
    int left = 0;
    int right = count-1;
    int mid;
    while (left < right) {
        mid = (left + right) / 2;

        if (elements[mid] != elements[mid+1] && elements[mid] != elements[mid-1])
            return elements[mid];
        else if (mid % 2 != 0 && elements[mid] == elements[mid+1])
            right = mid-1;
        else if (mid % 2 != 0 && elements[mid] != elements[mid+1])
            left = mid+1;
        else if (mid % 2 == 0 && elements[mid] == elements[mid+1])
            left = mid+2;
        else {
            right = mid-2;
        }
    }

    return elements[left];
}