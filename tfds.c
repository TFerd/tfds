#include "./stack.h"
#include <stdio.h>

/* TODO: move to its own stack.c file
   TODO: Make this generic
*/

int main() {
  Stack *stack = new_stack(1);

  printf("%d", peek(stack));
  /* StackNode *list = stack_node(1);
  list = push(list, 2);
  list = push(list, 3);

  print_stack(list);

  list = pop(list);

  print_stack(list);

  list = push(list, 5);
  list = push(list, 66);

  print_stack(list);
  printf("%d", peek(list)); */
}