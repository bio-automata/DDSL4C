/**
  Created by Rodrigo Cezar Silveira
  july 30, 2017
 */

/*Double linked list example*/

/*
    Exemplo de lista duplamente encadeada
    para maiores informações consulte a documentação, disponível em:
 */

#include <stdio.h>
#include <stdlib.h>
#include "doubleLinkedList.h"

typedef struct SCell{
	void *data;
	struct SCell *next;
	struct SCell *previous;
} Cell;

typedef struct SDoubleLinkedList
{
	int size;
	Cell *begin;
  Cell *end;
	Cell *aux;
} DoubleLinkedList;


DoubleLinkedList* DoubleLinkedList_new(){
  DoubleLinkedList* doubleLinkedList;
  
  doubleLinkedList = (DoubleLinkedList*)malloc(sizeof(DoubleLinkedList));
  doubleLinkedList->size = 0;
  doubleLinkedList->begin = NULL;
  doubleLinkedList->end = NULL;
  doubleLinkedList->aux = NULL;
  
  return doubleLinkedList;
}

void DoubleLinkedList_add(DoubleLinkedList *doubleLinkedList, int i, void* object){
  if(doubleLinkedList->size==0){
    DoubleLinkedList_addOrigin(doubleLinkedList, object);
  }
  else{
    if(i==0){
      DoubleLinkedList_addAtBegin(doubleLinkedList, object);
    }
    else if(i>=doubleLinkedList->size){
      DoubleLinkedList_addAtEnd(doubleLinkedList, object);
    }
    else{
      Cell* aux = (Cell*)malloc(sizeof(Cell));
  
      aux->data = object;
      doubleLinkedList->aux = DoubleLinkedList_search(doubleLinkedList, i);
      
      aux->next = doubleLinkedList->aux;
      aux->previous = doubleLinkedList->aux->previous;
      
      doubleLinkedList->aux->previous->next = aux;
      doubleLinkedList->aux->previous = aux;
      
      doubleLinkedList->size++;
    }
  }
}

void DoubleLinkedList_addOrigin(DoubleLinkedList *doubleLinkedList, void* object){
  doubleLinkedList-> aux = (Cell*)malloc(sizeof(Cell));
  
  doubleLinkedList->aux->data = object;
  doubleLinkedList->aux->next = doubleLinkedList->aux;
  doubleLinkedList->aux->previous = doubleLinkedList->aux;
  
  doubleLinkedList->begin = doubleLinkedList->aux;
  doubleLinkedList->end = doubleLinkedList->aux;
  
  doubleLinkedList->size++;
}

void DoubleLinkedList_addAtBegin(DoubleLinkedList *doubleLinkedList, void* object){
  if(doubleLinkedList->size==0){
    DoubleLinkedList_addOrigin(doubleLinkedList, object);
  }
  else{
    doubleLinkedList-> aux = (Cell*)malloc(sizeof(Cell));
  
    doubleLinkedList->aux->data = object;
    doubleLinkedList->aux->next = doubleLinkedList->begin;
    doubleLinkedList->aux->previous = doubleLinkedList->end;    

    doubleLinkedList->end->next = doubleLinkedList->aux;
    doubleLinkedList->begin->previous = doubleLinkedList->aux;
    
    doubleLinkedList->begin = doubleLinkedList->aux;
    
    doubleLinkedList->size++;
  }
}

void DoubleLinkedList_addAtEnd(DoubleLinkedList *doubleLinkedList, void* object){
  if(doubleLinkedList->size==0){
    DoubleLinkedList_addOrigin(doubleLinkedList, object);
  }
  else{
    doubleLinkedList-> aux = (Cell*)malloc(sizeof(Cell));
  
    doubleLinkedList->aux->data = object;
    doubleLinkedList->aux->previous = doubleLinkedList->end;
    doubleLinkedList->aux->next = doubleLinkedList->begin;

    doubleLinkedList->begin->previous = doubleLinkedList->aux;
    doubleLinkedList->end->next = doubleLinkedList->aux;
    doubleLinkedList->end = doubleLinkedList->aux;
    
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
      doubleLinkedList->aux = DoubleLinkedList_search(doubleLinkedList, i);
      data = doubleLinkedList->aux->data;
      
      doubleLinkedList->aux->previous->next = doubleLinkedList->aux->next;
      doubleLinkedList->aux->next->previous = doubleLinkedList->aux->previous;
      
      free(doubleLinkedList->aux);
      doubleLinkedList->aux = NULL;
      doubleLinkedList->size--; 
      return data;
    }
  }
}

void* DoubleLinkedList_dequeue(DoubleLinkedList *doubleLinkedList){
  void* data;
  
  data = doubleLinkedList->begin->data;
  doubleLinkedList->aux = doubleLinkedList->begin;
  
  doubleLinkedList->begin->previous->next = doubleLinkedList->aux->next;
  doubleLinkedList->begin->next->previous = doubleLinkedList->aux->previous;
  
  doubleLinkedList->begin = doubleLinkedList->aux->next;  
  free(doubleLinkedList->aux);
  doubleLinkedList->aux = NULL;
  doubleLinkedList->size--; 
  
  return data;
}

void* DoubleLinkedList_unstack(DoubleLinkedList *doubleLinkedList){
  void* data;
  
  data = doubleLinkedList->end->data;
  doubleLinkedList->aux = doubleLinkedList->end;
  
  doubleLinkedList->end->next->previous = doubleLinkedList->aux->previous;
  doubleLinkedList->end->previous->next = doubleLinkedList->aux->next;
  
  doubleLinkedList->end = doubleLinkedList->aux->previous;
  free(doubleLinkedList->aux);
  doubleLinkedList->aux = NULL;
  doubleLinkedList->size--; 
  
  return data;
}


Cell* DoubleLinkedList_search(DoubleLinkedList *doubleLinkedList, int i){
  doubleLinkedList->aux = doubleLinkedList->begin;
  while(i>0){
    doubleLinkedList->aux = doubleLinkedList->aux->next;
    i--;
  }
  return doubleLinkedList->aux;
}

void *doubleLinkedList_get(DoubleLinkedList *doubleLinkedList, int i){
  return DoubleLinkedList_search(doubleLinkedList, i)->data;
}

void DoubleLinkedList_set(DoubleLinkedList *doubleLinkedList, int i, void *data){
  DoubleLinkedList_search(doubleLinkedList, i)->data = data;
}


void DoubleLinkedList_destroy(DoubleLinkedList* doubleLinkedList){
  while(doubleLinkedList->size){
    doubleLinkedList->aux = doubleLinkedList->begin;
    doubleLinkedList->begin = doubleLinkedList->aux->next;
    doubleLinkedList->begin->previous = doubleLinkedList->aux->previous;
    free(doubleLinkedList->aux);
    doubleLinkedList->size--;
  }
  free(doubleLinkedList);
}

int DoubleLinkedList_size(DoubleLinkedList* doubleLinkedList){
  return doubleLinkedList->size;
}

void DoubleLinkedList_echo(DoubleLinkedList* doubleLinkedList){  //this method doesn't work for all data types!!!
  int i;
  
  i =0;
  doubleLinkedList->aux = doubleLinkedList->begin;

  printf("[");
  while(i<doubleLinkedList->size){
    if(i>0){
      printf(", "); 
    }
    
    printf("%s", (char*)doubleLinkedList->aux->data); 
    doubleLinkedList->aux = doubleLinkedList->aux->next;
    i++;
  }
  printf("]\n"); 
}
