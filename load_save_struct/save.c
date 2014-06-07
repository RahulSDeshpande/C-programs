#include <stdio.h>
#include "coordinate.h"

int main(int argc, char *argv[])
{
  FILE *file;

  // Check we have the correct command line argument
  if(argv[1])
  {
    // Open the file to write to
    file = fopen(argv[1], "w");
  }
  else
  {
    printf("Usage: <program_name> <file_to_write>");
    return(1);
  }

  // Create a 'coordinate' and a pointer to it
  struct coordinate data;
  struct coordinate *ptr = &data;

  // Collect the data via stdin
  printf("Enter a 'x' coordinate: ");
  scanf("%d", &data.x);
  
  printf("Enter a 'y' coordinate: ");
  scanf("%d", &data.y);

  // Write to the file
  fwrite(ptr, sizeof(struct coordinate), 1, file);

  // Tell the user what we wrote
  printf("Wrote (%d, %d) to %s.\n", data.x, data.y, argv[1]);

  return(0);
}