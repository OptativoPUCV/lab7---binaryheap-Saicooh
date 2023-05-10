#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;

Heap *createHeap()
{
  Heap *h = malloc(sizeof(Heap));

  if (!h)
  {
    free(h);
    return NULL;
  }
  
  h -> heapArray = malloc(3*sizeof(Heap));
  h -> size = 0;
  h -> capac = 3;

  return h;
}

void* heap_top(Heap* pq)
{
  if(!pq -> size || !pq -> heapArray[0].data) return NULL;

  return pq -> heapArray[0].data;
}

void heap_push(Heap *pq, void *data, int priority)
{
  if(!pq -> size) return NULL;
  
  int i = 0;
  
  while(pq -> heapArray != NULL)
  {
    if(pq -> heapArray[i] == NULL)
    {
      pq -> heapArray[i].data = data;
      pq -> heapArray[i].priority = priority;
      return;
    }
    i++;
  }
  
}


void heap_pop(Heap* pq){

}


