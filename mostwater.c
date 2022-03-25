#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "debug.h"

/* Problem statement: Given an array of integer heights of length n such that 
entry i represents a vertical line from 0 to height[i], find the pair of 
entries i,j such that a rectangle formed by i, j, the x-axis, and a line
parallel to the x-axis at height min(i,j) holds the largest possible volume.
Return that volume.

Constraints:
  n: [2, 10^5]
  height[i] for all i: [0, 10^4] */

/* Compile with: 
gcc -Wall mostwater.c -o mostwater.o

Toggle debug mode in debug.h
*/

int countChar(char* str, char chr)
{
  int i;
  int count = 0;

  for (i = 0; str[i]; i++)
  {
    if (str[i] == chr) count++;
  }

  return count;
}

int min(int a, int b)
{
  if (a < b) return a;
  return b;
}

int main (int argc, char* argv[])
{
  if (argc != 2)
  {
    printf("Usage: ./mostwater int,int,...");
    return EXIT_FAILURE;
  }

  /* get the length of the heights array for dynamic mem alloc */
  int n = countChar(argv[1], ',') + 1;
  int* height = (int *)malloc(sizeof(int) * n);
  
  /* Read from argv into heights array */
  int i, val;
  char *num;

  num = strtok(argv[1], ",");
  for (i = 0; i < n; i++)
  {
    sscanf(num, "%d", &val);
    height[i] = val;

    num = strtok(NULL, ",");
  }

  /* Print input for verification */
  printf("Input:\t");
  for (i = 0; i < n; i++)
  {
    printf("%d", height[i]);
    if (i < n - 1) printf(", ");
  }
  printf("\t(len %d)\n", n);
  
  /* Iterate through and test each pair */
  int best = 0;
  int j, vol;

  for (i = 0; i < n - 1; i++)
  {
    for (j = i + 1; j < n; j++)
    {
      vol = (j - i) * min(height[i], height[j]);
      if (vol > best) best = vol;
    }
  }

  /* Print output */
  printf("Output:\t%d\n", best);

  /* Free dynamically allocd mem */
  free(height);

  return EXIT_SUCCESS;
}
