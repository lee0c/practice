#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Problem statement: integer to Roman numeral
I   1
V   5
X   10
L   50
C   100
D   500
M   1000
Constraints: 
  input number is in the range [1, 3999]
  longest possible roman numeral by char count is 15 chars
*/

/* Compile with: 
gcc -Wall integertoroman.c -o integertoroman.o
*/

int main (int argc, char* argv[])
{
  if (argc != 2)
  {
    printf("Usage: ./integertoroman <integer>");
    return EXIT_FAILURE;
  }

  /* user input */
  int input;
  sscanf(argv[1], "%d", &input);
  printf("Input:\t%d\n", input);

  if (input < 1 || input > 3999) { return EXIT_FAILURE; }

  /* For easier math/clarity */
  int numValues = 13;
  int values[]      = {1,   4,    5,   9,    10,  40,   50,  90,   100, 400,  500, 900,  1000};
  char* numerals[]  = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};

  /* convert */
  char output[16];
  int i;

  for (i = numValues - 1; i >= 0; i--)
  {
    while (input >= values[i])
    {
      strcat(output, numerals[i]);
      input -= values[i];
    }
  }

  printf("Output:\t%s\n", output);

  return EXIT_SUCCESS;
}
