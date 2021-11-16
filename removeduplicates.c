#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Problem statement: Remove duplicates from a sorted array of ints, modifying it in-place */

/* Compile with: 
gcc -Wall removeduplicates.c -o removeduplicates.out
*/

int main (int argc, char* argv[])
{
  if (argc != 2)
  {
    printf("Usage: ./removeduplicates <comma separated list of ints>");
    return EXIT_FAILURE;
  }

  int nums[30000];

  char *num;
  int totalLen, newLen, current, val, i;

  num = strtok(argv[1], ",");
  totalLen = 0;

  while (num != NULL)
  {
    sscanf(num, "%d", &val);
    nums[totalLen] = val;
    
    num = strtok(NULL, ",");
    totalLen++;
  }

  newLen = 0;

  for (current = 0; current < totalLen; current++)
  {
    if (nums[newLen] != nums[current])
    {
      newLen++;
      nums[newLen] = nums[current];
    }
  }
  newLen++;

  printf("Length:\t%d\n", newLen);
  
  printf("[");
  for (i = 0; i < totalLen; i++)
  {
    if (i > 0) { printf(","); }

    if (i >= newLen) { printf("_"); }
    else { printf("%d", nums[i]); }
  }
  printf("]\n");
  

  return EXIT_SUCCESS;
}
