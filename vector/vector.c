#include "vector.h"

#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY 8
#define GROWTH_FACTOR 2

static bool out_of_range(Vector* vector, int index);
static void ensure_capacity(Vector* vector);

struct Vector {
  Item* items;
  int capacity;
  int size;
};

Vector* vector_create(void) {
  Vector* vector = malloc(sizeof *vector);
  vector->items = malloc(INITIAL_CAPACITY * sizeof *vector->items);
  vector->capacity = INITIAL_CAPACITY;
  vector->size = 0;
  return vector;
}

void vector_destroy(Vector** vector) {
  free((*vector)->items);
  free(*vector);
  *vector = NULL;
}

void vector_append(Vector* vector, Item item) {
  ensure_capacity(vector);
  vector->items[vector->size++] = item;
}

void vector_prepend(Vector* vector, Item item) {
  ensure_capacity(vector);
  memmove(vector->items[1], vector->items[0], vector->size++);
  vector->items[0] = item;
}

static void ensure_capacity(Vector* vector) {
  if (vector->size == vector->capacity) {
    vector->capacity *= GROWTH_FACTOR;
    vector->items = realloc(vector->items, vector->capacity);
  }
}

void vector_insert(Vector* vector, Item item, int index) {
  if (out_of_range(vector, index)) {
    return;
  }
  vector->items[index] = item;
}

void vector_remove(Vector* vector, int index) {
  if (out_of_range(vector, index)) {
    return;
  }
  if (index < vector->size) {
    memmove(vector->items[index + 1], vector->items[index],
            vector->size - index - 1);
  }
  vector->size--;
}

static bool out_of_range(Vector* vector, int index) {
  return index < 0 || index >= vector->size;
}

Item vector_at(Vector* vector, int index) {
  if (index < 0 || index >= vector->size) {
    return NULL;
  }
  return vector->items[index];
}

int vector_find(Vector* vector, Item item, Comparator comparator) {
  for (int i = 0; i < vector->size; i++) {
    if (comparator(item, vector->items[i]) == 0) {
      return i;
    }
  }
  return -1;
}

int vector_size(Vector* vector) { return vector->size; }

bool vector_is_empty(Vector* vector) { return vector->size == 0; }
