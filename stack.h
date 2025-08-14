#ifndef STACK_H
#define STACK_H

typedef struct Stack Stack;

Stack *new_stack(int value);
void print_stack(Stack *stack);
Stack *push(Stack *stack, int value);
int peek(Stack *stack);
Stack *pop(Stack *stack);
void delete(Stack *stack);

#endif