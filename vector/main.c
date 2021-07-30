#include "vector.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

int int_comparator(int a, int b);

int main(void) {
  Vector* vector = vector_create();
  assert(true == vector_is_empty(vector));

  vector_append(vector, (Item) 1);
  vector_append(vector, (Item) 2);
  vector_insert(vector, (Item) 3, 0);
  assert((Item) 3 == vector_at(vector, 0));
  assert((Item) 2 == vector_at(vector, 1));

  vector_append(vector, (Item) 4);
  vector_append(vector, (Item) 4);
  assert(2 == vector_find(vector, (Item) 4, int_comparator));

  assert(4 == vector_size(vector));

  vector_prepend(vector, (Item) -1);
  assert((Item) -1 == vector_at(vector, 0));

  vector_destroy(&vector);
  assert(NULL == vector);
  return 0;
}

int int_comparator(int a, int b) {
  if (a < b) {
    return -1;
  }
  if (a > b) {
    return 1;
  }
  return 0;
}
