#include "Array.h"

#include <stdlib.h>
#include <string.h>

#define array_header(array) \
    (u64*) array - ARRAY_FIELD_SIZE

#define array_capacity(array) \
    _array_get_field(array, ARRAY_CAPACITY)


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

Array _array_resize(Array array) {
  u64 length = array_length(array);
  u64 stride = array_stride(array);

  Array new_array = _array_create(ARRAY_GROWTH_FACTOR * array_capacity(array),
                                  stride);
  memcpy(new_array, array, length * stride);
  _array_set_field(new_array, ARRAY_LENGTH, length);

  array_destroy(array);
  return new_array;
}

u64 _array_get_field(Array array, ArrayField field) {
  u64* header = array_header(array);
  return header[field];
}

void _array_set_field(Array array, ArrayField field, u64 value) {
  u64* header = array_header(array);
  header[field] = value;
}

Array _array_push(Array array, const void* value) {
  u64 stride = array_stride(array);
  u64 capacity = array_capacity(array);
  u64 length = array_length(array);

  if (length >= capacity) {
    array = _array_resize(array);
  }

  u64 offset = length * stride;
  memcpy(array + offset, value, stride);
  _array_set_field(array, ARRAY_LENGTH, length + 1);
  return array;
}
