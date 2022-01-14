#include <stdio.h>
#include <stdlib.h>

/* Problem statement: */

/* Compile with: 
gcc -Wall name.c -o name.o
gcc -Wall name.c -o name.o -D DEBUG
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
