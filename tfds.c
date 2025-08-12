#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int value;
  struct IntLinkedList *prev;
  // next
} IntLinkedList;


/// Creates the head of the stack
IntLinkedList *int_list_new(int value) {
  IntLinkedList *temp = (IntLinkedList *)malloc(sizeof(IntLinkedList));
  temp->value = value;
  return temp;
}

/// Pushes an integer onto the list
IntLinkedList *int_list_push(IntLinkedList *list, int value) {
  IntLinkedList *newList = int_list_new(value);
  newList->prev = list;

  return newList;
}

void print_list(IntLinkedList *list) {}

int tfds_IntLinkedList_pop(IntLinkedList *list) {
  // int value = &stack.value;
  int value = list->value;
  printf("%d", value);
}

int main() {
  IntLinkedList *list = int_list_new(1);
  list = tfds_IntLinkedList_push(list, 2);

  

  printf("hi\n");
}