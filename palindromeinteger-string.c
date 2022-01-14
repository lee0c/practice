#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Problem statement: Given a signed 32-bit integer, return true if it is
palindromic and false otherwise */

/* Compile with:
gcc -Wall palindromeinteger-string.c -o palindromeinteger.out
*/

int main (int argc, char* argv[])
{
  if (argc != 2)
  {
    printf("Usage: ./palindromeinteger <int>");
    return EXIT_FAILURE;
  }

  /* declare vars */
  unsigned short int firstChar, lastChar;

  /* input integer can be 11 characters max - min and max vals are 10 digits,
  then account for negative sign (and null byte). */
  char input[12];
  
  /* Copy over user input */
  strcpy(input, argv[1]);
  printf("Input:\t%s\n", input);

  /* Iterate through string from front and back */
  lastChar = strlen(input) - 1;

  for (firstChar = 0; firstChar <= lastChar; firstChar++, lastChar--)
  {
    /* Debug statement */
    printf("DEBUG:\t[%d]: %c\t[%d]: %c\n", firstChar, input[firstChar], lastChar, input[lastChar]);

    if (input[firstChar] != input[lastChar])
    {
      printf("Output:\tfalse\n");
      break;
    }
  }

  if (firstChar >= lastChar)
  {
    printf("Output:\ttrue\n");
  }

  return EXIT_SUCCESS;
}
