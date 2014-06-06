/**
 * A replica of the Linux 'cat' program
 */

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
  // Open the file (or stdin)
  FILE *fp;
  if(argv[1])
  {
    fp = fopen(argv[1], "r");
  }
  else
  {
    fp = stdin;
  }

  // Check the file was opened correctly.
  if(!fp)
  {
    if(argv[1])
    {
      printf("Unable to open '%s'.\n", argv[1]);
    } 
    else
    {
      printf("Unable to read from stdin");
    }
    return(1);
  }


  // Read each character from the input file and print it
  int c = (char) fgetc(fp);
  do
  {
    printf("%c", c);
    c = (char) fgetc(fp);
  } while(c != EOF);

  // Close the file
  fclose(fp);

  // Exit
  return(0);
}