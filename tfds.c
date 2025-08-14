#include <stdio.h>
#include <stdlib.h>

/* TODO: move to its own stack.c file
   TODO: Make this generic
*/

typedef struct StackNode {
  int value;
  struct StackNode *prev;
} StackNode;

StackNode *stack_node(int value) {
  StackNode *node = (StackNode *)malloc(sizeof(StackNode));
  node->value = value;

  return node;
}

StackNode *stack_new(int value) { return stack_node(value); }

/* Prints the stack */
void print_stack(StackNode *list) {
  if (list == NULL) {
    printf("Failed to print list: given list was NULL!");
    return;
  }

  StackNode *c = list;

  printf("%d", c->value);

  while (c->prev != NULL) {
    c = c->prev;
    printf(",%d", c->value);
  }

  printf("\n");
}

/* Pushes a value to the end of the list and
 returns the tail. */
StackNode *push(StackNode *list, int value) {
  StackNode *node = stack_node(value);
  node->prev = list;

  return node;
}
/*
 StackNode* peek(StackNode *list) {}

 StackNode* pop(StackNode *list) {}

 StackNode* reverse(StackNode *list) {}
*/

int main() {
  StackNode *list = stack_node(1);
  list = push(list, 2);
  list = push(list, 3);

  print_stack(list);
}