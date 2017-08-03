/**
  Created by Rodrigo Cezar Silveira
  july 30, 2017
 */

#ifndef DOUBLE_LINKED_LIST
  #define DOUBLE_LINKED_LIST

typedef struct SCell Cell;
typedef struct SDoubleLinkedList DoubleLinkedList;

DoubleLinkedList* DoubleLinkedList_new();
void DoubleLinkedList_add(DoubleLinkedList *doubleLinkedList, int i, void* object);
void DoubleLinkedList_addOrigin(DoubleLinkedList *doubleLinkedList, void* object);
void DoubleLinkedList_addAtBegin(DoubleLinkedList *doubleLinkedList, void* object);
void DoubleLinkedList_addAtEnd(DoubleLinkedList *doubleLinkedList, void* object);
void* DoubleLinkedList_extract(DoubleLinkedList* doubleLinkedList, int i);
void* DoubleLinkedList_dequeue(DoubleLinkedList *doubleLinkedList);
void* DoubleLinkedList_unstack(DoubleLinkedList *doubleLinkedList);
Cell* DoubleLinkedList_search(DoubleLinkedList *doubleLinkedList, int i);
void* DoubleLinkedList_get(DoubleLinkedList *doubleLinkedList, int i);
void DoubleLinkedList_destroy(DoubleLinkedList* doubleLinkedList);
int DoubleLinkedList_size(DoubleLinkedList* doubleLinkedList);
void DoubleLinkedList_echo(DoubleLinkedList* doubleLinkedList);

#endif
