#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Problem statement: Roman numeral to integer 
I   1     <- possible subtraction - if next digit is V or X
V   5
X   10    <- possible subtraction - if next digit is L or C
L   50
C   100   <- possible subtraction - if next digit is D or M
D   500
M   1000
Constraints: 
  input string is less than or equal to 15 characters
  input string is a valid roman numeral containing only the above chars
  input string is in the range [1, 3999]
*/

/* Compile with: 
gcc -Wall romantointeger.c -o romantointeger.o
*/

/* For easier math/clarity */
enum NUMERAL {
  I = 1,
  V = 5,
  X = 10,
  L = 50,
  C = 100,
  D = 500,
  M = 1000
};

int main (int argc, char* argv[])
{
  if (argc != 2)
  {
    printf("Usage: ./romantointeger <roman numeral string>");
    return EXIT_FAILURE;
  }

  char input[16];
  int output = 0;
  unsigned short int i, inputLen;

  strcpy(input, argv[1]);
  inputLen = strlen(input);

  /* Loop through input string */
  for (i = 0; i < inputLen; i++)
  {
    switch (input[i])
    {
      case 'I':
        if (input[i+1] == 'V' || input[i+1] == 'X') { output -= I; }
        else { output += I; }
        break;
      case 'V':
        output += V;
        break;
      case 'X':
        if (input[i+1] == 'L' || input[i+1] == 'C') { output -= X; }
        else { output += X; }
        break;
      case 'L':
        output += L;
        break;
      case 'C':
        if (input[i+1] == 'D' || input[i+1] == 'M') { output -= C; }
        else { output += C; }
        break;
      case 'D':
        output += D;
        break;
      case 'M':
        output += M;
        break;
    }
  }

  printf("Input:\t%s\n", input);
  printf("Output:\t%d\n", output);

  return EXIT_SUCCESS;
}
