#ifndef DIRECT_ACCESS_H
#define DIRECT_ACCESS_H

#include <stdlib.h>

// Slot k points to an element in the set with key k. If the set
// contains no element with key k, then T[k] = NULL.
struct DA_Table
{
    void ** T; //direct_access_table 
    size_t capacity;
};


struct DA_Table*
DA_tableCreate(size_t capacity);

void *
DA_search(struct DA_Table *table, size_t key);

void
DA_insert(struct DA_Table *table, size_t key, void *item);

void *
DA_delete(struct DA_Table *table, size_t key);

void 
DA_deleteAndFree(struct DA_Table *table, size_t key);

void
DA_setCapacity(struct DA_Table * table,size_t new_capacity);
#endif

void
DA_tableDestroy(struct DA_Table *table);

void
DA_tableDestroyAndFreeItems(struct DA_Table *table);
