/**
 * A program to generate a random linked list of intergers
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// The data structure for the linked list
struct node
{
  // The value for this node
  int value;
  // Points to the next node in the list
  struct node *next;
};

int main()
{
  // Initialise a root node and define a traversal node
  struct node *root = malloc(sizeof(struct node));
  struct node *traverse = root;

  // Make the 'rand' function generate random numbers
  srand(time(NULL));

  /**
   * Generate a linked list of length 5-30
   */
  int i;
  int limit = (rand() % 25) + 4;
  for(i=0; i<limit; i++)
  {
    // Give the node a random value between 0 and 10
    traverse->value = rand() % 10;
    // Allocate the memory for the next node
    traverse->next = malloc(sizeof(struct node));
    // Move the pointer to the next node
    traverse = traverse->next;
  }
  // Set the value of the last node in the list 
  traverse->value = rand() % 10;
  // Make sure the last node has a null pointer 
  traverse->next = 0;

  /**
   * Print out the linked list
   */
  traverse = root;
  // Print out the first node without a trailing arrow
  printf("%d", traverse->value);
  traverse = traverse->next;
  // Iterate through the rest of the list and print the value of each node
  while(traverse != NULL)
  {
    printf("->%d", traverse->value);
    traverse = traverse->next;
  }
  // Print a trailing newline
  printf("\n");

  return(0);
}