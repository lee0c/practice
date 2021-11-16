#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Problem statement: Given a signed 32-bit integer, return true if it is
palindromic and false otherwise. Implemented without string handling methods */

/* Compile with:
`-lm` links the math library
gcc -Wall palindromeinteger-int.c -o palindromeinteger.out -lm
gcc -Wall palindromeinteger-int.c -o palindromeinteger.out -lm -D DEBUG
*/

int main (int argc, char* argv[])
{
  if (argc != 2)
  {
    printf("Usage: ./palindromeinteger-int <int>");
    return EXIT_FAILURE;
  }

  int input;

  sscanf(argv[1], "%d", &input);
  printf("Input:\t%d\n", input);

  if (input < 0)
  {
    /* Negative sign at start is an auto disqualifier, quick to rule out */
    printf("Output:\tfalse\n");
    return EXIT_SUCCESS;
  }

  /* largest possible power of 10 that can divide into a 32-bit signed int is 10^9
  INT_MAX = 2 147 483 647 (10 digits)
  10^9    = 1 000 000 000
  */
  double exp = 9;
  int first, last;

  /* Reduce power of 10 until it divides into input value */
  while (input / pow(10, exp) <= 1) { exp--; }

#ifdef DEBUG  
  printf("DEBUG:\tStarting at exp %f\n", exp);
#endif

  while (input > 0)
  {
    first = input / (int)pow(10, exp);
    last = input % 10;

#ifdef DEBUG  
    printf("DEBUG:\tWorking val: %11d\tfirst: %d\tlast: %d\n", input, first, last);
#endif

    if (first != last)
    {
      printf("Output:\tfalse\n");
      break;
    }

    /* Take off first digit */
    input -= (int)pow(10, exp) * first;
    /* Take off last digit */
    input -= last;
    input /= 10;

    /* We've taken the working number down /2/ powers of 10 with those last few
    lines, so decrement exp by 2, not just 1  */
    exp -= 2;
  }

  if (input <= 0)
  {
    printf("Output:\ttrue\n");
  }

  return EXIT_SUCCESS;
}
