/**
 * A program to generate a random doubly linked list of integers.
 * All operations in this version are recursive (as opposed to the singly linked
 * list implementation)
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
  // Points to the previous node in the list
  struct node *previous;
};

/**
 * Traverses a linked list, printing the nodes as it goes.
 */
void print_list_backwards(struct node *node)
{
  // If there is a next node, recurse down the list
  if(node->next)
  {
    print_list_backwards(node->next);
    // Print the connector between nodes if we recursed
    printf("<->");
  }
  // Always print the node at this level
  printf("%d", node->value);
  // If there's no previous node, then we've reached the end and can print a
  // newline
  if(!node->previous)
  {
    printf("\n");
  }
}

/**
 * Traverses a linked list, printing the nodes as it goes.
 */
void print_list(struct node *node)
{
  // Always print the node at this level
  printf("%d", node->value);
  // If there is another node, print the connector and recurse
  if(node->next)
  {
    printf("<->");
    print_list(node->next);
  }
  else
  {
    // Print a newline if we reached the end
    printf("\n");
  }
}

/**
 * Recursively generates a linked list
 */
struct node * generate_list_extension(int length, int max_value,
  struct node *previous)
{
  if(length == 0)
  {
    return NULL;
  }
  else
  {
    struct node *node = malloc(sizeof(struct node));
    // Give the node a random value between the min and max values
    node->value = (rand() % max_value);
    // Set the previous node
    node->previous = previous;
    node->next = generate_list_extension(length - 1, max_value, node);
    return node;
  }
}

/**
 * Generate a random linked list of length 'length' and with each node having
 * a value from 0 to 'max_value'
 */
struct node * generate_list(int length, int max_value)
{
  struct node *root = malloc(sizeof(struct node));
  // Give the node a random value between the min and max values
  root->value = (rand() % max_value);
  // Set the previous node
  root->previous = NULL;
  // Generate the list recursively
  root->next = generate_list_extension(length - 1, max_value, root);
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
  
  // Print the list again, but backwards
  print_list_backwards(root);

  return(0);
}