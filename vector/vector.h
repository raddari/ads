#ifndef ADS_VECTOR_H
#define ADS_VECTOR_H

#include <stdbool.h>

typedef struct Vector Vector;
typedef void* Item;
typedef int (*Comparator)(Item, Item);

Vector* vector_create(void);
void vector_destroy(Vector** vector);
void vector_append(Vector* vector, Item item);
void vector_prepend(Vector* vector, Item item);
void vector_insert(Vector* vector, Item item, int index);
Item vector_at(Vector* vector, int index);
int vector_find(Vector* vector, Item item, Comparator comparator);
int vector_size(Vector* vector);
bool vector_is_empty(Vector* vector);

#endif  // ADS_VECTOR_H