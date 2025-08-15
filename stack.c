#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
  int value;
  struct Stack *prev;
} Stack;

Stack *ferds_stack_new_node(int value) {
  Stack *node = (Stack *)malloc(sizeof(Stack));
  node->value = value;

  return node;
}

Stack *ferds_stack_init(int value) { return ferds_stack_new_node(value); }

void ferds_stack_print(Stack *stack) {
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
Stack *ferds_stack_push(Stack *stack, int value) {
  Stack *node = ferds_stack_new_node(value);
  node->prev = stack;

  return node;
}

int ferds_stack_peek(Stack *stack) { return stack->value; }

Stack *ferds_stack_pop(Stack *stack) {
  Stack *temp = stack;
  stack = temp->prev;

  free(temp);
  return stack;
}

/*TODO: verify this works*/
void ferds_stack_destroy(Stack *head) {
  Stack *cursor = head;
  Stack *prev = cursor->prev;

  free(cursor);

  while (prev != NULL) {
    cursor = prev;
    prev = cursor->prev;

    free(cursor);
  }
}

int main() {
  Stack *stack = ferds_stack_init(1);
  stack = ferds_stack_push(stack, 7);
  stack = ferds_stack_push(stack, 345);
  stack = ferds_stack_push(stack, 3049);

  ferds_stack_print(stack);

  ferds_stack_destroy(stack);
  stack = NULL;

  return 0;
}
