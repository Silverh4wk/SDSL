#include "DirectAcessTable.h"
#include <stdlib.h>


struct DA_Table*
DA_tableCreate( size_t init_capacity )
{
    struct DA_Table* table = calloc( 1,sizeof( struct DA_Table ) );

    if( !table )
	return NULL;
    
    table->T = calloc(init_capacity, sizeof( void* ) );
    table->capacity = init_capacity;
    return table;
};


void *
DA_search( struct DA_Table *table, size_t key ) {
    if( key >= table->capacity )
	return NULL;
    return table->T[ key ];
}

void
DA_insert( struct DA_Table *table, size_t key,void *item )
{
    if ( key >= table->capacity )
	 return;
    
    table->T[ key ] = item;
};

void *
DA_delete( struct DA_Table *table, size_t key )
{
    if ( key >= table->capacity )
	return NULL;

    void *item = table->T[key];
    table->T[ key ] = NULL;

    return item;
}


void 
DA_deleteAndFree( struct DA_Table *table, size_t key )
{
    if ( key >= table->capacity )
	return;

    free( table->T[key] );
    table->T[key] = NULL;
}
void
DA_setCapacity(struct DA_Table *table, size_t new_capacity)
{
   if ( !table )
	return;

   size_t old_capacity = table->capacity;
    
    // !!!destructive operation!!! , any item thats outside of the new range will be free'd
    if (new_capacity < old_capacity)
    {
        for (size_t i = new_capacity; i < old_capacity; i++)
            DA_deleteAndFree(table, i);
    }

    void **new_T = realloc(table->T,
                           new_capacity * sizeof(void*));

    if (!new_T)
        return;

    if (new_capacity > old_capacity)
    {
        for (size_t i = old_capacity;
             i < new_capacity;
             i++)
        {
            new_T[i] = NULL;
        }
    }

    table->T = new_T;
    table->capacity = new_capacity;
}


void
DA_tableDestroy(struct DA_Table *table)
{
    if (!table)
        return;

    free(table->T);
    free(table);
}

void
DA_tableDestroyAndFreeItems(struct DA_Table *table)
{
    if (!table)
        return;

    for (size_t i = 0; i < table->capacity; i++)
        free(table->T[i]);

    free(table->T);
    free(table);
}
