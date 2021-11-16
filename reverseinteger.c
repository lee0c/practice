#include <stdio.h>
#include <stdlib.h>

/* Problem statement: Reverse the digis of a signed 32-bit integer, or return
0 if the answer would overflow the range of a signed 32-bit integer. */

/* Compile with: 
gcc -Wall reverseinteger.c -o reverseinteger.out
*/

int main (int argc, char* argv[])
{
  if (argc != 2)
  {
    printf("Usage: ./reverseinteger <int>");
    return EXIT_FAILURE;
  }

  /* declare vars */
  int input, output, active;

  /* user input */
  sscanf(argv[1], "%d", &input);
  
  active = input;
  output = 0;

  while (active != 0)
  {
    /* modulus 10 returns the last digit */
    output = output * 10 + (active % 10);

    /* divide by 10 to get all digits but the last one, or 0 for a single
    digit number */
    active /= 10;
  }

  if ((output < 0 && input > 0) ||
      (output > 0 && input < 0))
  {
    /* If signs don't match, output overflowed. Return 0 */
    output = 0;
  }

  printf("Input:\t%d\n", input);
  printf("Output:\t%d\n", output);

  return EXIT_SUCCESS;
}
