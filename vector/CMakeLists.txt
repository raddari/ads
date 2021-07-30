project(vector)

set(VECTOR_LIB ${PROJECT_NAME})
set(VECTOR_TEST ${PROJECT_NAME}_test)

add_library(${VECTOR_LIB} vector.c vector.h)
add_executable(${VECTOR_TEST} main.c)

target_link_libraries(${VECTOR_TEST} PRIVATE ${VECTOR_LIB})
