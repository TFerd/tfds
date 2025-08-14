#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
  int value;
  struct Stack *prev;
} Stack;

Stack *stack_node(int value) {
  Stack *node = (Stack *)malloc(sizeof(Stack));
  node->value = value;

  return node;
}

Stack *new_stack(int value) { return stack_node(value); }

void print_stack(Stack *stack) {
  if (stack == NULL) {
    printf("Failed to print list: given list was NULL!");
    return;
  }

  Stack *c = stack;

  printf("%d", c->value);

  while (c->prev != NULL) {
    c = c->prev;
    printf(",%d", c->value);
  }

  printf("\n");
}

/* Pushes a value to the end of the stack and
 returns the tail. */
Stack *push(Stack *stack, int value) {
  Stack *node = stack_node(value);
  node->prev = stack;

  return node;
}

int peek(Stack *stack) { return stack->value; }

Stack *pop(Stack *stack) {
  Stack *temp = stack->prev;
  free(stack);

  return temp;
}

/*TODO: verify this works*/
void delete(Stack *stack) {
  Stack *tempA = stack->prev;
  free(stack);

  while (tempA != NULL) {
    Stack *tempB = tempA->prev;
    tempA = tempB->prev;

    free(tempB);
  }
}
