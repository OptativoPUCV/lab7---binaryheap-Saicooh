#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo
{
  void* data;
  int priority;
} heapElem;

typedef struct Heap
{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;

Heap *createHeap()
{
  Heap *h = malloc(sizeof(Heap));

  h -> heapArray = malloc(3*sizeof(Heap));
  h -> size = 0;
  h -> capac = 3;

  return h;
}

void* heap_top(Heap* pq)
{
  if(!pq) return NULL;

  return pq -> heapArray[0].data;
}

void heap_push(Heap *pq, void *data, int priority)
{
  heapElem auxiliar;
  
  if(pq -> size == pq -> capac)
  {
    pq -> capac = pq -> capac * 2 + 1;
    pq -> heapArray = realloc(pq -> heapArray, pq -> capac * sizeof(heapElem));
  }

  pq -> heapArray[pq -> size].data = data;
  pq -> heapArray[pq -> size].priority = priority;
  pq -> size++;

  while (pq -> heapArray[pq -> size].priority > (pq -> heapArray[(pq -> size - 1) / 2].priority)
  {
    auxiliar = pq -> heapArray[(pq -> size - 1) / 2];
    heapArray[(pq -> size - 1) / 2] = pq -> heapArray[pq -> size];

    
    
  }

  
  

  
  
}


void heap_pop(Heap* pq){

}


