#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo
{
  void *data;
  int priority;
} heapElem;

typedef struct Heap
{
  heapElem *heapArray;
  int size;
  int capac;
} Heap;

Heap *createHeap()
{
  Heap *h = malloc(sizeof(Heap));

  h -> heapArray = malloc(3 * sizeof(Heap));
  h -> size = 0;
  h -> capac = 3;

  return h;
}

void* heap_top(Heap* pq)
{
  if(!pq -> size) return NULL;

  return pq -> heapArray[0].data;
}

void heap_push(Heap *pq, void *data, int priority)
{
  int i = pq -> size;
  
  if(pq -> size == pq -> capac)
  {
    pq -> capac = pq -> capac * 2 + 1;
    pq -> heapArray = realloc(pq -> heapArray, pq -> capac * sizeof(heapElem));
  }

  while (priority > (pq -> heapArray[(i - 1) / 2].priority) && i)
  {
    pq -> heapArray[i] = pq -> heapArray[(i - 1) / 2];
    i = (i - 1) / 2;
  }

  pq -> heapArray[i].data = data;
  pq -> heapArray[i].priority = priority;
  pq -> size++;
}


void heap_pop(Heap *pq)
{
  int indicePadre = 0, indiceHijoMayorPrioridad;
  heapElem aux;
  pq -> heapArray[0] = pq -> heapArray[(pq -> size - 3) / 2];
  
  while (pq -> size > 2 * indicePadre + 1)
  {
    indiceHijoMayorPrioridad = 2 * indicePadre + 1;
    if(indiceHijoMayorPrioridad + 1 < pq -> size)
    {
      if(pq -> heapArray[indicePadre + 1].priority > pq -> heapArray[indiceHijoMayorPrioridad].priority)
      {
        indiceHijoMayorPrioridad++;
      }
    }
      
    if(pq -> heapArray[indicePadre].priority < pq -> heapArray[indiceHijoMayorPrioridad].priority)
    {
      aux = pq -> heapArray[indicePadre];
      pq -> heapArray[indicePadre] = pq -> heapArray[indiceHijoMayorPrioridad];
      pq -> heapArray[indiceHijoMayorPrioridad] = aux;
      indicePadre = indiceHijoMayorPrioridad;
    }
    else break;
  }

  pq -> size--;
}


