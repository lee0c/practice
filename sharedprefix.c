#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Problem statement: Find the longest common prefix string shared by all
  strings in an array. 
Constraints:
  1-200 strings given
  strings are 0-200 characters in length
  strings are only lowercase alpha chars
*/

/* Compile with: 
gcc -Wall sharedprefix.c -o sharedprefix.o
*/

int main (int argc, char* argv[])
{
  if (argc < 2)
  {
    printf("Usage: ./sharedprefix <string1> ...");
    return EXIT_FAILURE;
  }

  char strs[200][201];
  char substr[201];

  int i, j, total;
  total = argc - 1;

  for (i = 0; i < total; i++)
  {
    strcpy(strs[i], argv[i+1]);
  }

  printf("Input:\n");
  for (i = 0; i < total; i++)
  {
    printf("\t%s\n", strs[i]);
  }
  printf("\n");

  for (i = 0; i < 200; i++)
  {
    for (j = 1; j < total; j++)
    {
      if (strs[j][i] != strs[0][i]) break;
    }

    if (j != total) break;
  }

  strncpy(substr, strs[0], i);
  substr[i] = '\0';

  printf("Output:\t%s\n", substr);

  return EXIT_SUCCESS;
}
