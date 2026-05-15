#include "DirectAcessTable.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    struct DA_Table *table = DA_tableCreate(10);

    int *a = malloc(sizeof(int));
    int *b = malloc(sizeof(int));
    int *c = malloc(sizeof(int));
    int *d = malloc(sizeof(int));
    int *e = malloc(sizeof(int));
    int *f = malloc(sizeof(int));

    *a = 100;
    *b = 200;
    *c = 300;
    *d = 400;
    *e = 500;
    *f = 600;

    DA_insert(table, 0, a);
    DA_insert(table, 1, b);
    DA_insert(table, 2, c);
    DA_insert(table, 3, d);
    DA_insert(table, 4, e);
    DA_insert(table, 5, f);

    int *v = DA_search(table, 0);
    int *w = DA_search(table, 1);
    int *x = DA_search(table, 2);
    int *y = DA_search(table, 3);
    int *z = DA_search(table, 4);
    int *zz = DA_search(table, 5);
    
    printf("%d\n", *v);
    printf("%d\n", *w);
    printf("%d\n", *x);
    printf("%d\n", *y);
    printf("%d\n", *z);
    printf("%d\n", *zz);

    printf("\n\n---------dataSetSizeTest-----------\n\n\n");

    DA_setCapacity(table, 4);
    for (int i= 0 ; i < 6; i++)
	if (DA_search(table, i) == NULL)
	    printf("slot empty\n");
	else
	    printf( "%d \n", *(int* )DA_search(table, i));

    free(table->T);
    free(table);
    
    printf("all tests passed\n");
     
    return 0;
}
