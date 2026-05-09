#ifndef ARRAY_H
#define ARRAY_H
#include <stddef.h>
#include <stdbool.h>


/* ok so what do we have in an array usually
  1. its a contiguous piece of memory that stores data in
  2. all must share the same memory size
  3. a key or an index is used to identify them

  Functions that can be used with an array:

  *create
  *push
  *pop
  *get
  *clear
  *get len
  *find index
  *sort
  *front - return the first element 
  *back -  return the last element
  *empty - check if its empty
  *destroy - return memory to system
  
*/

struct Array{
    size_t len;
    size_t capacity;
    size_t element_size;
    void* elements;
    };


struct Array*
arrayCreate(size_t element_size, size_t init_capacity);

size_t
arrayPush(void* element,struct Array* push_to);

int
arrayRemoveUO (size_t index, struct Array* pop_from);

void *
arrayGet(size_t index, struct Array *get_from);

void*
arrayGetFront (struct Array* get_from);

void*
arrayGetBack (struct Array* get_from);

void
arrayClear(struct Array* array);

size_t
arrayGetLength(struct Array* array);

size_t
arrayGetIndex(void* element, struct Array* get_from);

//void   arraySort

bool 
arrayEmpty   (struct Array* array);

void
arrayDestroy (struct Array* array);


#endif
