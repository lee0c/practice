#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "debug.h"

/* Problem statement: Given two non-negative integers as strings, return
their product. Do not convert the inputs directly to integers. 

Constraints: 
  string length [0,200]
  no leading 0s except for a value of 0
*/

/* Compile with: 
gcc -Wall multiplystrings.c -o multiplystrings.o

Toggle debug mode in debug.h
*/

int main (int argc, char* argv[])
{
  if (argc != 3)
  {
    printf("Usage: ./multiplystrings <int1> <int2>");
    return EXIT_FAILURE;
  }

  char num1[201];
  char num2[201];

  strcpy(num1, argv[1]);
  strcpy(num2, argv[2]);

  int len1 = strlen(num1);
  int len2 = strlen(num2);

  printf("Input:");
  printf("\tnum1:\t%s\t(%d)\n", num1, len1);
  printf("\tnum2:\t%s\t(%d)\n", num2, len2);

  int product = 0;
  int place1, place2, dig1, dig2;
  int i, j;

  for (i = len1 - 1; i >= 0; i--)
  {
    dig1 = num1[i] - '0';
    place1 = len1 - 1 - i; /* exp of 10 needed to get the place of this digit */

    for (j = len2 - 1; j >= 0; j--)
    {
      dig2 = num2[j] - '0';
      place2 = len2 - 1 - j; /* exp of 10 needed to get the place of this digit */

      product += dig1 * dig2 * (int)pow(10, place1 + place2);
    }
  }

  printf("Output:\t%d\n", product);
  return EXIT_SUCCESS;
}
