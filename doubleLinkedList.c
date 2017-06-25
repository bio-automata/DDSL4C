#include <stdio.h>
#include <stdlib.h>


typedef struct SCell{
	void *data;
	struct SCell *left;
	struct SCell *right;
} Cell;

typedef struct SDoubleLinkedList
{
	int size;
	Cell *begin;
	Cell *cell;
} DoubleLinkedList;

DoubleLinkedList* newDoubleLinkedList(){
  DoubleLinkedList* doubleLinkedList;
  
  doubleLinkedList = (DoubleLinkedList*)malloc(sizeof(DoubleLinkedList));
  doubleLinkedList->size = 0;
  doubleLinkedList->begin = NULL;
  doubleLinkedList->cell = NULL;
  
  return doubleLinkedList;
}

void insert(DoubleLinkedList *doubleLinkedList, void* object, int objectSize){
  Cell *cell = (Cell*)malloc(objectSize);
  
  cell->data = object;
  if(doubleLinkedList->size==0){
    doubleLinkedList->begin = cell;
    cell->left = doubleLinkedList->begin;
    cell->right = doubleLinkedList->begin;
  }
  else{
    cell->left = doubleLinkedList->begin;
    cell->right = doubleLinkedList->begin->right;
    doubleLinkedList->begin->right = cell;
    
    doubleLinkedList->begin = cell;
  }
  
  doubleLinkedList->size++;
}

void get(DoubleLinkedList *doubleLinkedList){
  doubleLinkedList->cell = doubleLinkedList->begin;
  doubleLinkedList->begin = doubleLinkedList->cell->left;
  doubleLinkedList->begin->right = doubleLinkedList->cell->right;
}


void destroy(DoubleLinkedList* doubleLinkedList){
  while(doubleLinkedList->size){
    doubleLinkedList->cell = doubleLinkedList->begin;
    doubleLinkedList->begin = doubleLinkedList->cell->left;
    doubleLinkedList->begin->right = doubleLinkedList->cell->right;
    free(doubleLinkedList->cell);
    doubleLinkedList->size--;
  }
  free(doubleLinkedList);
}



void print(DoubleLinkedList* doubleLinkedList){
  int i =doubleLinkedList->size;
  
  doubleLinkedList->cell = doubleLinkedList->begin;
  while(i){
    printf("%s\n", (char*)doubleLinkedList->cell->data); 
    doubleLinkedList->cell = doubleLinkedList->cell->left;
    i--;
  }
}

int main(){
  
  DoubleLinkedList* d = newDoubleLinkedList();
  
  
  insert(d, "teste1", sizeof(char)*6);
  insert(d, "teste2", sizeof(char)*6);
  insert(d, "teste3", sizeof(char)*6);
  insert(d, "teste4", sizeof(char)*6);
  insert(d, "teste5", sizeof(char)*6);
  
  
  print(d);
  destroy(d);
  
  return 0;
}
