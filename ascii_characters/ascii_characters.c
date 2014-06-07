/**
 * Prints out all the ascii characters
 */
#include <stdio.h>

int main()
{
  int i;

  // Iterate through and print out all the ascii characters
  for(i=0; i<128; i++)
  {
    printf("%d\t: %c\n", i, (char)i);
  }

  return(0);
}