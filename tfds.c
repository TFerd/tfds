#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode { 
  int value;
  struct ListNode *prev;
}ListNode;

ListNode* new_node(int value) {
  ListNode *node = (ListNode*)malloc(sizeof(ListNode));
  node->value = value;

  return node;
}

void print_list(ListNode *list) {
  if (list == NULL){
    printf("Failed to print list: given list was NULL!");
    exit(0);
  }

  ListNode *c = list;
  
  printf("%d", c->value);

  while (c->prev != NULL) {
    c = c->prev;
    printf(",%d", c->value);
  }
}

/// Returns tail of the list
ListNode* push(ListNode *list, int value) {
  ListNode *node = new_node(value);
  node->prev = list;

  return node;
}

// ListNode* pop(ListNode *list) {}

// ListNode* reverse(ListNode *list) {}

int main() {
  ListNode *list = new_node(1);
  list = push(list, 2);
  list = push(list, 3);

  print_list(list);
}