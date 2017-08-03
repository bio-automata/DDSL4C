/**
  Created by Rodrigo Cezar Silveira
  july 30, 2017
 */

#include <stdio.h>
#include <stdlib.h>
#include "doubleLinkedList.h"

typedef struct SCell{
	void *data;
	struct SCell *left;
	struct SCell *right;
} Cell;

typedef struct SDoubleLinkedList
{
	int size;
	Cell *begin;
  Cell *end;
	Cell *cell;
} DoubleLinkedList;


DoubleLinkedList* DoubleLinkedList_new(){
  DoubleLinkedList* doubleLinkedList;
  
  doubleLinkedList = (DoubleLinkedList*)malloc(sizeof(DoubleLinkedList));
  doubleLinkedList->size = 0;
  doubleLinkedList->begin = NULL;
  doubleLinkedList->end = NULL;
  doubleLinkedList->cell = NULL;
  
  return doubleLinkedList;
}

void DoubleLinkedList_add(DoubleLinkedList *doubleLinkedList, int i, void* object, int objectSize){
  if(doubleLinkedList->size==0){
    DoubleLinkedList_addOrigin(doubleLinkedList, object, objectSize);
  }
  else{
    if(i==0){
      DoubleLinkedList_addAtBegin(doubleLinkedList, object, objectSize);
    }
    else if(i>=doubleLinkedList->size){
      DoubleLinkedList_addAtEnd(doubleLinkedList, object, objectSize);
    }
    else{
      Cell *cell = (Cell*)malloc(objectSize);
  
      cell->data = object;
      doubleLinkedList->cell = DoubleLinkedList_search(doubleLinkedList, i);
      
      cell->left = doubleLinkedList->cell;
      cell->right = doubleLinkedList->cell->right;
      
      doubleLinkedList->cell->right->left = cell;
      doubleLinkedList->cell->right = cell;
      
      doubleLinkedList->size++;
    }
  }
}

void DoubleLinkedList_addOrigin(DoubleLinkedList *doubleLinkedList, void* object, int objectSize){
  doubleLinkedList-> cell = (Cell*)malloc(objectSize);
  
  doubleLinkedList->cell->data = object;
  doubleLinkedList->cell->left = doubleLinkedList->cell;
  doubleLinkedList->cell->right = doubleLinkedList->cell;
  
  doubleLinkedList->begin = doubleLinkedList->cell;
  doubleLinkedList->end = doubleLinkedList->cell;
  
  doubleLinkedList->size++;
}

void DoubleLinkedList_addAtBegin(DoubleLinkedList *doubleLinkedList, void* object, int objectSize){
  if(doubleLinkedList->size==0){
    DoubleLinkedList_addOrigin(doubleLinkedList, object, objectSize);
  }
  else{
    doubleLinkedList->cell = (Cell*)malloc(objectSize);
  
    doubleLinkedList->cell->data = object;
    doubleLinkedList->cell->left = doubleLinkedList->begin;
    doubleLinkedList->cell->right = doubleLinkedList->end;    

    doubleLinkedList->end->left = doubleLinkedList->cell;
    doubleLinkedList->begin->right = doubleLinkedList->cell;
    
    doubleLinkedList->begin = doubleLinkedList->cell;
    
    doubleLinkedList->size++;
  }
}

void DoubleLinkedList_addAtEnd(DoubleLinkedList *doubleLinkedList, void* object, int objectSize){
  if(doubleLinkedList->size==0){
    DoubleLinkedList_addOrigin(doubleLinkedList, object, objectSize);
  }
  else{
    doubleLinkedList->cell = (Cell*)malloc(objectSize);
  
    doubleLinkedList->cell->data = object;
    doubleLinkedList->cell->right = doubleLinkedList->end;
    doubleLinkedList->cell->left = doubleLinkedList->begin;

    doubleLinkedList->begin->right = doubleLinkedList->cell;
    doubleLinkedList->end->left = doubleLinkedList->cell;
    doubleLinkedList->end = doubleLinkedList->cell;
    
    doubleLinkedList->size++;
  }
}


void *DoubleLinkedList_extract(DoubleLinkedList* doubleLinkedList, int i){
  void* data;
  
  if(doubleLinkedList->size==0){
    return DoubleLinkedList_dequeue(doubleLinkedList);
  }
  else{
    if(i==0){
      return DoubleLinkedList_dequeue(doubleLinkedList);
    }
    else if(i>=doubleLinkedList->size-1){
      return DoubleLinkedList_unstack(doubleLinkedList);
    }
    else{
      doubleLinkedList->cell = DoubleLinkedList_search(doubleLinkedList, i);
      data = doubleLinkedList->cell->data;
      
      doubleLinkedList->cell->right->left = doubleLinkedList->cell->left;
      doubleLinkedList->cell->left->right = doubleLinkedList->cell->right;
      
      free(doubleLinkedList->cell);
      doubleLinkedList->cell = NULL;
      doubleLinkedList->size--; 
      return data;
    }
  }
}

void* DoubleLinkedList_dequeue(DoubleLinkedList *doubleLinkedList){
  void* data;
  
  data = doubleLinkedList->begin->data;
  doubleLinkedList->cell = doubleLinkedList->begin;
  
  doubleLinkedList->begin->right->left = doubleLinkedList->cell->left;
  doubleLinkedList->begin->left->right = doubleLinkedList->cell->right;
  
  doubleLinkedList->begin = doubleLinkedList->cell->left;  
  free(doubleLinkedList->cell);
  doubleLinkedList->cell = NULL;
  doubleLinkedList->size--; 
  
  return data;
}

void* DoubleLinkedList_unstack(DoubleLinkedList *doubleLinkedList){
  void* data;
  
  data = doubleLinkedList->end->data;
  doubleLinkedList->cell = doubleLinkedList->end;
  
  doubleLinkedList->end->left->right = doubleLinkedList->cell->right;
  doubleLinkedList->end->right->left = doubleLinkedList->cell->left;
  
  doubleLinkedList->end = doubleLinkedList->cell->right;
  free(doubleLinkedList->cell);
  doubleLinkedList->cell = NULL;
  doubleLinkedList->size--; 
  
  return data;
}


Cell* DoubleLinkedList_search(DoubleLinkedList *doubleLinkedList, int i){
  doubleLinkedList->cell = doubleLinkedList->begin;
  while(i>0){
    doubleLinkedList->cell = doubleLinkedList->cell->left;
    i--;
  }
  return doubleLinkedList->cell;
}

void *doubleLinkedList_get(DoubleLinkedList *doubleLinkedList, int i){
  return DoubleLinkedList_search(doubleLinkedList, i)->data;
}

void DoubleLinkedList_set(DoubleLinkedList *doubleLinkedList, int i, void *data){
  DoubleLinkedList_search(doubleLinkedList, i)->data = data;
}


void DoubleLinkedList_destroy(DoubleLinkedList* doubleLinkedList){
  while(doubleLinkedList->size){
    doubleLinkedList->cell = doubleLinkedList->begin;
    doubleLinkedList->begin = doubleLinkedList->cell->left;
    doubleLinkedList->begin->right = doubleLinkedList->cell->right;
    free(doubleLinkedList->cell);
    doubleLinkedList->size--;
  }
  free(doubleLinkedList);
}

void DoubleLinkedList_echo(DoubleLinkedList* doubleLinkedList){ 
  int i;
  
  i =0;
  doubleLinkedList->cell = doubleLinkedList->begin;
  printf("["); 
  while(i<doubleLinkedList->size){
    if(i>0){
      printf(", "); 
    }
    
    printf("%s", (char*)doubleLinkedList->cell->data); 
    doubleLinkedList->cell = doubleLinkedList->cell->left;
    i++;
  }
  printf("]\n"); 
}
