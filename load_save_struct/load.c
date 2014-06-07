/**
 * A program to load a coordinate from a file
 */

#include <stdio.h>
#include "coordinate.h"

int main(int argc, char *argv[])
{
  FILE *file;
  // Check we have a file name in the command line args
  if(argv[1])
  {
    // Open the file
    file = fopen(argv[1], "r");
  }
  else
  {
    printf("Usage: <program_name> <file_to_read>");
    return(1);
  }

  // Define a struct and pointer to it to read into
  struct coordinate data;
  struct coordinate *ptr = &data;
 
  // Read from the input file
  fread(ptr, sizeof(struct coordinate), 1, file);

  // Print out what was read
  printf("Read (%d, %d) from %s.\n", data.x, data.y, argv[1]);

  return(0);
}