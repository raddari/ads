/// Dynamic array with type safety.
/// Heavily inspired by https://github.com/travisvroman/kohi
#pragma once

#include "Types.h"


typedef void* Array;

typedef enum ArrayField {
  ARRAY_STRIDE,    //< Size of each item in bytes
  ARRAY_CAPACITY,  //< Allocated memory for the array
  ARRAY_LENGTH,    //< Amount of items present
  ARRAY_FIELD_SIZE,
} ArrayField;

Array _array_create(u64 capacity, u64 stride);
void _array_destroy(Array array);
Array _array_resize(Array array);

u64 _array_get_field(Array array, ArrayField field);
void _array_set_field(Array array, ArrayField field, u64 value);

Array _array_push(Array array, const void* value);
void _array_pop(Array array, void* dest);

Array _array_insert(Array array, u64 index, const void* value);
Array _array_pop_at(Array array, u64 index, void* dest);


#define ARRAY_DEFAULT_CAPACITY 8
#define ARRAY_GROWTH_FACTOR 2

#define array_create(type) \
    _array_create(ARRAY_DEFAULT_CAPACITY, sizeof (type))

#define array_reserve(type, capacity) \
    _array_create((capacity), sizeof (type))

#define array_destroy(array) \
    _array_destroy(array)

#define array_push(array, value)        \
    {                                   \
      typeof(value) temp = value;       \
      array = _array_push(array, &temp) \
    }

#define array_pop(array, dest) \
    _array_pop(array, dest)

#define array_insert(array, index, value)       \
    {                                           \
      typeof(value) temp = value;               \
      array = _array_insert(array, index, temp) \
    }

#define array_pop_at(array, index, dest) \
    _array_pop_at(array, index, dest)

#define array_clear(array) \
    _array_set_field(array, ARRAY_LENGTH, 0)

#define array_length(array) \
    _array_get_field(array, ARRAY_LENGTH)

#define array_stride(array) \
    _array_get_field(array, ARRAY_STRIDE)
