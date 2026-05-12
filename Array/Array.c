#include "Array.h"
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

static inline bool resize(struct Array *array)
{

    
  if (array->len <= array->capacity / 2 && array->capacity > 4)
    {
        size_t new_capacity = array->capacity / 2;
        size_t new_size = new_capacity * array->element_size;
        void *new_block = realloc(array->elements, new_size);
        if (new_block) {
            array->elements = new_block;
            array->capacity = new_capacity;
        }
     
    }
  
    if(array->len < array->capacity)
	return true;
    
    size_t new_capacity = (array->capacity == 0 ? 1 : array->capacity * 2);

    if (SIZE_MAX - array->len < new_capacity)
	return false;
    
    void* new_block = realloc(array->elements, new_capacity * array->element_size);

    if(!new_block)
	return false;
    
    array->elements = new_block;
    array->capacity = new_capacity;

    return true;
}

struct Array
*arrayCreate(size_t element_size, size_t init_capacity)
{
    struct Array* array = (struct Array*)calloc(1,sizeof(struct Array));
    if(!array)
	return NULL;
    
    array->len = 0;
    array->element_size = element_size;
    array->capacity = init_capacity;
    
    if (init_capacity > 0)
    {
        array->elements = malloc(element_size * init_capacity);
	
        if (!array->elements)
        {
            free(array);
            return NULL;
        }
    }
    else
	array->elements = NULL;
    
    return array;
}

size_t 
arrayPush(void* element,struct Array* push_to)
{
    if (!resize(push_to))
        return SIZE_MAX;
    
    
    size_t index = push_to->len++;
    memcpy((uint8_t*)push_to->elements + index * push_to->element_size, element ,push_to->element_size);

    return index;
}

int
arrayRemoveUO (size_t index, struct Array* remove_from)
{
    if(arrayEmpty(remove_from) || index >=remove_from->len)
	return 1;

    if(remove_from->len == 1)
    {
	arrayClear(remove_from);
	return 0;
    }

    --remove_from->len;

    uint8_t* item_ptr = (uint8_t*)remove_from->elements +index *remove_from->element_size;
    uint8_t* end_ptr = (uint8_t*)remove_from->elements +remove_from->len *remove_from->element_size;
    memcpy(item_ptr,end_ptr,remove_from->element_size);

    return 0;
}

void*
arrayGet (size_t index, struct Array* get_from)
{
  if(index >= get_from->len)
      return NULL;
  return (uint8_t*)get_from->elements + index * get_from->element_size;   
}

void*
arrayGetFront (struct Array* get_from)
{
    if (arrayEmpty(get_from))
	return NULL;
    return get_from->elements;
}

void*
arrayGetBack (struct Array* get_from)
{
    if (arrayEmpty(get_from))
	return NULL;
    return (uint8_t*)get_from->elements + (get_from->len - 1) * get_from->element_size;
}

void
arrayClear(struct Array *array)
{
    array-> len = 0;    
}

size_t
arrayGetIndex(void *element, struct Array *arr)
{
    if (!arr || !element)
        return SIZE_MAX;

    for (size_t i = 0; i < arr->len; ++i)
    {
        if (arrayGet(i, arr) == element)
            return i;
    }

    return SIZE_MAX; //return max size if not found
}

//void   arraySort

bool 
arrayEmpty   (struct Array* array)
{
    return (array->len == 0);    
}

void arrayDestroy(struct Array *array)
{
    if(!array) return;
    free(array->elements);
    free(array);
}


