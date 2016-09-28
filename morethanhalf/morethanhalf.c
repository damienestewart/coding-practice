/* This program is for the following problem:
 * Imagine you are given n plastic reader numbers, where each has a number
 * stored on a magnetic strip. Your intern ordered the wrong int reader, and
 * now all you can do is find if any two given numbers have equal numbers. Devise
 * an algorithm that will find if there exists a number that is stored on more
 * than half of the numbers and runs in O(nlogn) time.
 *
 * This program takes an array of random positive integers and checks to see if
 * any number in the array occurs in more than half the indices in O(nlogn) time.
 * You can see how the answer to this can be extended to the original problem.
 */
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <math.h>
 #include <time.h>

 #define MAXNUMBERS 6

 /*
  * Prints all the numbers.
  */
 void printnumbers(int *, int);

 /*
  * Returns the number that is in more than half the indices.
  */
 int moreThanHalfR(int *, int);

 int main(void) {
   time_t t;
   int *numbers = malloc(MAXNUMBERS*sizeof(int));
   srand((unsigned) time(&t));


   int i;
   for (i = 0; i < MAXNUMBERS; i++) {
     numbers[i] = rand() % 5;
   }

   int n = moreThanHalfR(numbers, MAXNUMBERS);
   printf("The list: ");
   printnumbers(numbers, MAXNUMBERS);

   if (n == -1)
    printf("No number exist in more than half the indices of the array.\n");
   else
    printf("The number that exists in more than half the indices is: %d\n.", n);

   return 0;
 }

 /*
  * Returns the number that is in more than half the indices.
  */
 int moreThanHalfR(int *thenumbers, int theSize) {
   // Base case check size == 1.
   if (theSize == 1)
    return thenumbers[0]; // This number satisfies the condition at this level.

   // Base case check size == 2.
   if (theSize == 2) {
     // Are they the same?
     if (thenumbers[0] == thenumbers[1])
      return thenumbers[0];
     else
      return -1; // There is no int that is stored on more than half.
   }

   // Figure out sizes for dividing the list.
   int leftSize = theSize/2;
   int rightSize = theSize - leftSize;

   int *left = malloc(leftSize*sizeof(int));
   int *right = malloc(rightSize*sizeof(int));

   // Copy memory to copy the lists.
   left = memcpy(left, (const int *)thenumbers, leftSize*sizeof(int));
   right = memcpy(right, (const int *)thenumbers +
   leftSize, rightSize*sizeof(int));

   int leftResult = moreThanHalfR(left, leftSize);
   int rightResult = moreThanHalfR(right, rightSize);

   int opposite_count = 0;
   int i;

   if (leftResult == rightResult)
    return leftResult;


   if (leftResult == -1 && rightResult == -1) // No half had the desired number.
    return -1;

   if (leftResult != -1 && rightResult != -1) { // Both halves had such a num.
     int leftCount = 0;
     int rightCount = 0;

     // Figure out how many times the number appears.

     for (i = 0; i < leftSize; i++) {
       if (left[i] == rightResult) {
         rightCount++;
       }

       if (left[i] == leftResult) {
         leftCount++;
       }
     }

     for (i = 0; i < rightSize; i++) {
       if (right[i] == leftResult) {
         leftCount++;
       }

       if (right[i] == rightResult) {
         rightCount++;
       }
     }

     // How many times does the left vs right number appear?
     // Return the one that appears the most overall.
     // If they appear the same amount of times, there is no winner. -1.
     if (leftCount > theSize/2 && leftCount > rightCount)
      return leftResult;

     if (rightCount > theSize/2 && rightCount > leftCount)
      return rightResult;

     return -1;
   }

   // If there is no winner in left.
   if (leftResult == -1) {

     int rightCount = 0;
     for (int i = 0; i < rightSize; i++) {
       if (right[i] == rightResult)
        rightCount++;
     }

     for (i = 0; i < leftSize; i++) {
       if (left[i] == rightResult)
        rightCount += 1;
     }

     if (rightCount > theSize/2)
      return rightResult;
     else
      return -1;
   }

   // If there is no winner in right.
   if (rightResult == -1) {

     int leftCount = 0;
     for (int i = 0; i < leftSize; i++) {
       if (left[i] == leftResult)
        leftCount++;
     }

     for (i = 0; i < rightSize; i++) {
       if (right[i] == leftResult)
        leftCount++;
     }

     if (leftCount > theSize/2) {
      return leftResult;
    }
     else
      return -1;
   }
   return -1;
 }

 /*
  * Prints the numbers bro.
  */
 void printnumbers(int *thenumbers, int theSize) {
   printf("{");
   int i;
   for (i = 0; i < theSize - 1; i++) {
     printf("%d, ", thenumbers[i]);
   }
   printf("%d}\n", thenumbers[i]); // not happy about doing this, but whatever.
 }
