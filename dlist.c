/* Double (Linked) List
  NULL  <- (head) -> (tail)
      <-prev    next->
*/
/*
TODO: make generic
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct DListNode {
  int value;
  struct DListNode *next;
  struct DListNode *prev;
} DListNode;

typedef struct DList {
  DListNode *head;
  DListNode *tail;
} DList;

DListNode *ferds_dlist_node_new(int value) {
  DListNode *node = (DListNode *)malloc(sizeof(DListNode));
  node->value = value;

  return node;
}

DList *ferds_dlist_init(int value) {
  DList *list;
  DListNode *node = ferds_dlist_node_new(value);

  list->head = node;
  list->tail = node;

  return list;
}

void ferds_dlist_print_front(DList *list) {
  DListNode *cursor = list->head;

  while (cursor != NULL) {
    printf("%d\n", cursor->value);
    cursor = cursor->next;
  }
}

void ferds_dlist_print_back(DList *list) {
  DListNode *cursor = list->tail;

  while (cursor != NULL) {
    printf("%d\n", cursor->value);
    cursor = cursor->prev;
  }
}

DList *ferds_dlist_push_front(DList *list, int value) {
  DListNode *node = ferds_dlist_node_new(value);

  node->next = list->head;
  list->head->prev = node;
  list->head = node;

  return list;
}

DList *ferds_dlist_push_back(DList *list, int value) {
  DListNode *node = ferds_dlist_node_new(value);
  node->prev = list->tail;
  list->tail->next = node;
  list->tail = node;

  return list;
}

int ferds_dlist_peek_front(DList *list) { return list->head->value; }

int ferds_dlist_peek_back(DList *list) { return list->tail->value; }

DList *ferds_dlist_pop_front(DList *list) {}

DList *ferds_dlist_pop_back(DList *list) {}