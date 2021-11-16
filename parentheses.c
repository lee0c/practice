#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Problem statement: Determine if a string of parentheses is valid. 
  Open brackets must be closed by the same type of brackets
  Open brackets must be closed in the correct order

Constraints:
  String length of at least 1, at most 10000 
  Consists only of [](){} characters  
*/

/* Compile with: 
gcc -Wall parentheses.c -o parentheses.out
*/

int isLeft(char paren)
{
  if (paren =='(' || paren == '[' || paren == '{') { return 1; }
  return 0;
}

int leftMatchesRight(char left, char right)
{
  if (left ==  '(' && right == ')') { return 1; }
  if (left ==  '[' && right == ']') { return 1; }
  if (left ==  '{' && right == '}') { return 1; }
  return 0;
}

int main (int argc, char* argv[])
{
  if (argc != 2)
  {
    printf("Usage: ");
    return EXIT_FAILURE;
  }

  char input[1001];
  char leftBuffer[501];
  unsigned short int i, inputLen, halfLen, bufferLoc;

  strcpy(input, argv[1]);
  inputLen = strlen(input);

  printf("Input:\t%s\n", input);

  /* Quick invalidation: odd-length strings (parens can't pair up) */
  if (inputLen % 2 == 1) {
    printf("Output:\tfalse\n");
    return EXIT_SUCCESS;
  }
  halfLen = inputLen / 2;

  /* # of lefts in the buffer / next open slot in the buffer */
  bufferLoc = 0;

  for (i = 0; i < inputLen; i++)
  {
    if (isLeft(input[i])) /* left parentheses */
    {
      leftBuffer[bufferLoc] = input[i];
      bufferLoc++;
      
      /* If we ever have more left parens than half the string length,
      parens can't pair up evenly and this must be invalid */
      if (bufferLoc > halfLen) { break; }
    }
    else /* right parentheses */
    {
      /* If we ever have a right paren and no lefts, failure */
      if (bufferLoc <= 0) { break; }

      if (leftMatchesRight(leftBuffer[bufferLoc - 1], input[i]))
      {
        /* That left paren has been matched, back up to the previous one in the buffer */
        bufferLoc--;
      }
      else { break; }
    }
  }

  if (i == inputLen)
  {
    printf("Output:\ttrue\n");
    return EXIT_SUCCESS;
  }
  else
  {
    printf("Output:\tfalse\n");
    return EXIT_SUCCESS;
  }

  return EXIT_SUCCESS;
}
