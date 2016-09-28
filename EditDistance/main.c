//
// Created by Damiene Andre Stewart on 3/8/16.
// Coded to solve the minimum edit distance problem.
// Treats lower and uppercase characters as different.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

    if (argc < 3) {
        printf("USAGE: editdistance string_a string_b");
        exit(1);
    }

    const char *string_a = argv[1];
    const char *string_b = argv[2];

    size_t string_a_length = strlen(string_a) + 1; // Keep a row to account for empty string edit distance.
    size_t string_b_length = strlen(string_b) + 1;

    printf("String A: %s, String B: %s\n", string_a, string_b);

    // Create 2-D array to hold the edit distances for each sub-problem.
    // Array Dimensions: size_a_length + 1 X size_b_length
    int **edit_distance_array = (int **) malloc(string_a_length * sizeof(int*));
    int i;
    for (i = 0; i < string_a_length; i++)
        edit_distance_array[i] = (int *) malloc(string_b_length * sizeof(int));

    // Initialize first row.
    for (i = 0; i < string_b_length; i++) {
        edit_distance_array[0][i] = i;
    }

    // Initialize first column.
    for (i = 0; i < string_a_length; i++) {
        edit_distance_array[i][0] = i;
    }

    // Solve:
    int j;
    for (i = 1; i < string_a_length; i++)
        for (j = 1; j < string_b_length; j++) {
            if (string_a[i] == string_b[j]) {
                edit_distance_array[i][j] = edit_distance_array[i-1][j-1];
            } else {
                edit_distance_array[i][j] = edit_distance_array[i-1][j] < edit_distance_array[i][j-1]?
                                            edit_distance_array[i-1][j] : edit_distance_array[i][j-1];
                edit_distance_array[i][j] = edit_distance_array[i][j] < edit_distance_array[i-1][j-1] ?
                                            edit_distance_array[i][j] : edit_distance_array[i-1][j-1];
                edit_distance_array[i][j]++;
            }
        }

    printf("Minimum edit distance: %d\n", edit_distance_array[string_a_length-1][string_b_length-1]);

    return 0;
}
