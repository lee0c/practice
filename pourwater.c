#include <stdio.h>
#include <stdlib.h>

#include "debug.h"

/* Problem statement: Given n buckets with variable integer amounts of water
and given a spillage percentage 'loss', return the maximum amount of water in
each bucket after pouring water between buckets to make them equal.

Pouring mechanic:
  Water can be poured in any amount from one bucket to another
  Pouring k gallons of water results in spilling loss percent of k

Constraints:
  Number of buckets [1, 10^5]
  Gallons per bucket (integer) [0, 10^5]
  Loss percentage (integer) [0, 99]
*/

/* Compile with: 
gcc -Wall pourwater.c -o pourwater.o
gcc -Wall pourwater.c -o pourwater.o -D DEBUG
*/
#define DELTA 1e-6

int compareInt (const void * a, const void * b)
{
  int *x = (int *)a;
  int *y = (int *)b;

  if (*x < *y) return -1;
  if (*x > *y) return 1;
  return 0;
}

float average (float *array, int numElements)
{
  int i;
  float sum = 0;

  for (i = 0; i < numElements; i++) sum += array[i];
  
  return sum / numElements;
}

int main (int argc, char* argv[])
{
  if (argc < 3)
  {
    printf("Usage: ./pourwater <loss percentage> <gallons in bucket 0> ...");
    return EXIT_FAILURE;
  }

  /* user input: loss % */
  int loss;
  float unspilled;
  sscanf(argv[1], "%d", &loss);
  unspilled = 1.0 - (loss / 100.0);
  printf("Spillage:\t%.2f%%\n", 1.0 - unspilled);

  /* user input: bucket amts */

  int i;
  int numBuckets = argc - 2;
  int bucket;

  int * bucketsInt = (int *)malloc(numBuckets * sizeof(int));
  float * buckets = (float *)malloc(numBuckets * sizeof(float));

  for (i = 0; i < numBuckets; i++)
  {
    sscanf(argv[i + 2], "%d", &bucket);
    bucketsInt[i] = bucket;
  }

  /* Sort bucket array and create array of floats */

  qsort(bucketsInt, numBuckets, sizeof(int), compareInt);

  printf("Buckets:\t[ ");
  for (i = 0; i < numBuckets; i++)
  {
    buckets[i] = (float)bucketsInt[i];
    printf("%.2f ", buckets[i]);
  }
  printf("]\n");

  printf("Precision:\t%f\n", DELTA);

  /* Logic */

  float avg, excessWater, desiredWater;

#if DEBUG
  int iteration = 0;
#endif

  while (buckets[numBuckets - 1] - buckets[0] > 2 * DELTA)
  {
    avg = average(buckets, numBuckets);
    /* Reset to prevent floating point oddities*/
    excessWater = 0;

#if DEBUG
    printf("Iteration %d:\n", iteration);
    printf("\tAvg: %f\n", avg);

    printf("\tBuckets:\t[ ");
    for (i = 0; i < numBuckets; i++) printf("%f ", buckets[i]);
    printf("]\n");

    printf("\t\t\t  ");
    for (i = 0; i < numBuckets; i++)
    {
      if (buckets[i] - buckets[0] < DELTA) printf("%-9s", "v");
      else if (buckets[i] - avg > DELTA) printf("%-9s", "^");
      else printf("%-9s", "");
    }
    printf("\n");

    iteration++;

    getchar();
#endif

    for (i = numBuckets - 1; buckets[i] > avg; i--)
    {
      /* If above the average, bucket donates anything over average */
      excessWater += buckets[i] - avg;
      buckets[i] = avg;
    }

    /* Pour water into the lowest buckets until out of water */
    i = 0;
    while (excessWater > DELTA)
    {
      desiredWater = buckets[i + 1] - buckets[i];
      if (excessWater >= desiredWater / unspilled)
      {
        buckets[i] = buckets[i + 1];
        excessWater -= desiredWater / unspilled;
      }
      else
      {
        buckets[i] += excessWater * unspilled;
        excessWater = 0;
      }
      
      /* If we're not on the first bucket, check on lower buckets. Otherwise,
      find the last bucket that shares a value with the first bucket */
      if (i != 0) i--;
      else
      {
        while (buckets[i] - buckets[0] < DELTA) i++;
      }
    }
  }

  avg = average(buckets, numBuckets);
  printf("\nFinal average:\t%.5f\n", avg);

  return EXIT_SUCCESS;
}
