#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Problem statement: Remove a value from an array of ints, modifying it in-place */

/* Compile with: 
gcc -Wall removevalue.c -o removevalue.o
*/

int main (int argc, char* argv[])
{
  if (argc != 3)
  {
    printf("Usage: ./removevalue <comma separated list of ints> <int to remove>");
    return EXIT_FAILURE;
  }

  int nums[100];

  char *num;
  int totalLen, newLen, val, first, last, i;

  /* Read in array */ 
  num = strtok(argv[1], ",");
  totalLen = 0;

  while (num != NULL)
  {
    sscanf(num, "%d", &val);
    nums[totalLen] = val;
    
    num = strtok(NULL, ",");
    totalLen++;
  }

  /* Read in val */
  sscanf(argv[2], "%d", &val);

  /* Iterate through array, swapping instances of val */
  newLen = 0;
  first = 0;
  last = totalLen - 1;

  while (1)
  {
    while (nums[first] != val && first < last) 
    { 
      first++; 
    }
    /* Once first equals last, we've surveyed all numbers */

    if (first == last) { break; }

    while (nums[last] == val) { last--; }

    nums[first] = nums[last];
    nums[last] = val;
  }

  /* Print output */
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
