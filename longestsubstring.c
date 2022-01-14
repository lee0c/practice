#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Problem statement: Find the length of the longest substring without
repeating characters in a string
Constraints:
  string contains English letters, digits, symbols, and spaces
  string is at most 5 * 10^4 (50k) characters */

/* Compile with: 
gcc -Wall longestsubstring.c -o longestsubstring.o
gcc -Wall longestsubstring.c -o longestsubstring.o -D DEBUG
*/

int main (int argc, char* argv[])
{
  if (argc != 2)
  {
    printf("Usage: ./longestsubstring <string>");
    return EXIT_FAILURE;
  }

  /* let's use ASCII to track which characters show up
  the relevant set of characters is 32 (space) through 126 (~)
  that's 95 characters
  so let's set 32 to index 0 of our tracking "map" (actually an array)
  aka, for any char we subtract 32 to get its index
  */

  char input[50001];
  int tracker[95];

  int i;
  for (i=0; i<95; i++)
  {
    tracker[i] = -1;
  }

  strcpy(input, argv[1]);
  int inputLen = strlen(input);

  int start, end, lastOccurrence, bestLen;
  start = 0;
  bestLen = 0;

#ifdef DEBUG
      printf("Set start to index %d\n", start);
#endif

  for (end = 0; end < inputLen; end++)
  {

    if (tracker[input[end] - 32] != -1)
    {
#ifdef DEBUG
      for (i = start; i <= end; i++)
      {
        printf("%c ", input[i]);
      }
      printf("\n");

      printf("Duplicate letter %c at indices %d, %d\n", input[end], tracker[input[end] - 32], end);
#endif        

      if (end - start > bestLen)
      {
        bestLen = end - start;

#ifdef DEBUG
        printf("Found new best length %d w/ substring [%d, %d]\n", bestLen, start, end-1);
#endif        
      }

      lastOccurrence = tracker[input[end] - 32];
      /* we're going to zero out any numbers we are removing from the
      window, so the last occurrence MUST be within our window 
      
      this loop needs to start at the 'start' position of the window and
      zero (-1) out the chars between 'start' and 'lastOccurrence' (incl) */
      for (; start <= lastOccurrence; start++)
      {
        tracker[input[start] - 32] = -1;
      }

#ifdef DEBUG
      printf("\nMoved start to index %d\n", start);
#endif

    }
    
    /* Set the most recent position of this letter in the tracker */
    /* This needs to happen whether or not we found a duplicate - even if we
    did, we still need to note this character in the tracker */
    tracker[input[end] - 32] = end;
  }

#ifdef DEBUG
  for (i = start; i <= end; i++)
  {
    printf("%c ", input[i]);
  }
  printf("\n");
#endif

  /* Check one last time at end of string */
  if (end - start > bestLen) { bestLen = end - start; }

  printf("\nLength:\t%d\n", bestLen);

  return EXIT_SUCCESS;
}
