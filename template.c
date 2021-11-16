#include <stdio.h>
#include <stdlib.h>

/* Problem statement: */

/* Compile with: 
gcc -Wall name.c -o name.out
gcc -Wall name.c -o name.out -D DEBUG
*/

int main (int argc, char* argv[])
{
  if (argc != /* val */)
  {
    printf("Usage: ");
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
