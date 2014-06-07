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

/**
 * Reverses a linked list.
 */
struct node * reverse_linked_list(struct node *root)
{
  // We need three pointers to keep track of the nodes
  struct node *one;
  struct node *two;
  struct node *three;

  // Assign the three pointers to their starting positions
  one = root->next;
  two = one->next;
  three = two->next;

  // Do the first swap
  one->next = root;
  root->next = 0;

  // While we're not at the end of the list, traverse it, swapping as we go
  while(three)
  {
    two->next = one;
    one = two;
    two = three;
    three = three->next;
  }

  // Do the final swap and return the result
  two->next = one;
  return two;
}

/**
 * Traverses a linked list, printing the nodes as it goes.
 */
void print_list(struct node *root)
{
  // Print out the first node without a trailing arrow
  printf("%d", root->value);
  root = root->next;
  // Iterate through the rest of the list and print the value of each node
  while(root != NULL)
  {
    printf("->%d", root->value);
    root = root->next;
  }
  // Print a trailing newline
  printf("\n");
}

/**
 * Generates a linked list of a random length between min and max and of random
 * values
 */
struct node * generate_list(int length, int max_value)
{
  struct node *root = malloc(sizeof(struct node));
  struct node *traverse = root;
  int i;
  for(i=0; i<(length - 1); i++)
  {
    // Give the node a random value between the min and max values
    traverse->value = (rand() % max_value);
    // Allocate the memory for the next node
    traverse->next = malloc(sizeof(struct node));
    // Move the pointer to the next node
    traverse = traverse->next;
  }
  // Set the value of the last node in the list 
  traverse->value = rand() % 10;
  // Make sure the last node has a null pointer 
  traverse->next = 0;
  // Return the root node
  return root;
}

int main()
{
  // Initialise a root node and define a traversal node
  struct node *root;

  // Make the 'rand' function generate random numbers
  srand(time(NULL));
  
  // Generate a random linked list
  root = generate_list(5, 10);

  // Print the list
  print_list(root);

  // Reverse the list
  root = reverse_linked_list(root);
  
  // Print the list again
  print_list(root);

  return(0);
}