/**
  Created by Rodrigo Cezar Silveira
  july 30, 2017
 */
 
/* A simple test*/

#include <stdio.h>
#include <stdlib.h>
#include "doubleLinkedList.h"

int main(){  
  DoubleLinkedList* d = DoubleLinkedList_new();
  
  DoubleLinkedList_echo(d);
  DoubleLinkedList_addAtEnd(d, "teste1");
  DoubleLinkedList_echo(d);
  DoubleLinkedList_addAtEnd(d, "teste2");
  DoubleLinkedList_echo(d);
  DoubleLinkedList_addAtEnd(d, "teste3");
  DoubleLinkedList_echo(d);
  DoubleLinkedList_addAtEnd(d, "teste4");
  DoubleLinkedList_echo(d);
  DoubleLinkedList_addAtEnd(d, "teste5");
  
  DoubleLinkedList_echo(d);
  DoubleLinkedList_add(d, 3, "teste3.5");
  DoubleLinkedList_echo(d);
  DoubleLinkedList_add(d, 13, "teste3.5");
  DoubleLinkedList_echo(d);
  DoubleLinkedList_add(d, 13, "teste57");
  DoubleLinkedList_echo(d);
  DoubleLinkedList_add(d, 13, "teste44");
  
  DoubleLinkedList_echo(d);
  DoubleLinkedList_addAtBegin(d, "teste41");
  DoubleLinkedList_echo(d);
  DoubleLinkedList_addAtBegin(d, "teste60");
  DoubleLinkedList_echo(d);
  DoubleLinkedList_addAtBegin(d, "teste-2");
  DoubleLinkedList_echo(d);
  DoubleLinkedList_addAtBegin(d, "teste0.3");
  
  
  DoubleLinkedList_echo(d);
  printf("%s\n", (char*)DoubleLinkedList_unstack(d));
  DoubleLinkedList_echo(d);
  printf("%s\n", (char*)DoubleLinkedList_dequeue(d));   
  DoubleLinkedList_echo(d);
  printf("%s\n", (char*)DoubleLinkedList_unstack(d));   
  DoubleLinkedList_echo(d);
  printf("%s\n", (char*)DoubleLinkedList_dequeue(d));   
  
  DoubleLinkedList_echo(d);
  printf("%s\n", (char*)DoubleLinkedList_dequeue(d));   
  DoubleLinkedList_echo(d);
  printf("%s\n", (char*)DoubleLinkedList_dequeue(d));   
  
  DoubleLinkedList_echo(d);
  printf("%s\n", (char*)DoubleLinkedList_unstack(d));
  DoubleLinkedList_echo(d);
  printf("%s\n", (char*)DoubleLinkedList_unstack(d));
  
  DoubleLinkedList_echo(d);
  printf("e %s\n", (char*)DoubleLinkedList_extract(d,3));   
  DoubleLinkedList_echo(d);
  printf("%s\n", (char*)DoubleLinkedList_extract(d,0)); 
  DoubleLinkedList_echo(d);
  printf("%s\n", (char*)DoubleLinkedList_extract(d,1));   
  DoubleLinkedList_echo(d);
    
  DoubleLinkedList_destroy(d);
  
  return 0;
}
