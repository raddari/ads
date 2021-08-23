#include "Array.h"

#include <stdlib.h>

#define array_header(array) \
    (u64*) array - ARRAY_FIELD_SIZE


Array _array_create(u64 capacity, u64 stride) {
  u64 header_size = 3 * ARRAY_FIELD_SIZE * sizeof (u64);
  u64* array = malloc(capacity * stride + header_size);
  array[ARRAY_STRIDE] = stride;
  array[ARRAY_CAPACITY] = capacity;
  array[ARRAY_LENGTH] = 0;
  return (void*) (array + ARRAY_FIELD_SIZE);
}

void _array_destroy(Array array) {
  free(array_header(array));
}

u64 _array_get_field(Array array, ArrayField field) {
  u64* header = array_header(array);
  return header[field];
}

void _array_set_field(Array array, ArrayField field, u64 value) {
  u64* header = array_header(array);
  header[field] = value;
}
