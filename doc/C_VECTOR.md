# C_VECTOR


## API

/**
 * @brief Public macro to define a generic vector for a given type with all required dependencies.
 *
 * This macro instantiates:
 * 
 * - The vector API (   `_create`, `_create_capacity`, `_destroy`, `_clear`, `_copy`, `_move`, `_data`, `_size`, `_capacity`, `_empty`,
 *                      `_realloc`, `_realloc_copy`,
 *                      `_push_back`, `_push_back_copy`, `_push_back_move`, `_pop_back`, `_element_front`, `_element_back`, `_element_at`, `_equals`,
 *                      `_begin`, `_end`
 *                  )
 * 
 * @param VECTOR_NAME_PUBLIC_PREFIX     The public name prefix for generated vector (e.g., `MyVec` -> `MyVec_create`, etc.).
 * @param TYPE                          Type stored in the vector.
 */
#define DEFINE_GENERIC_VECTOR

`_create`, `_create_capacity`, `_destroy`, `_clear`, `_copy`, `_move`, `_data`, `_size`, `_capacity`, `_empty`,
`_realloc`, `_realloc_copy`,
`_push_back`, `_push_back_copy`, `_push_back_move`, `_pop_back`, `_element_front`, `_element_back`, `_element_at`, `_equals`,
`_begin`, `_end`


## Functions

**_create()**
- @brief Creates a vector struct and allocates dynamic array with default capacity.
- @return A new instance of VECTOR_NAME.

**_destroy()**
/**                                                                                                                                             \
 * @brief Destroys a vector and releases allocated memory.                                                                                      \
 * @param target Pointer to the vector.                                                                                                         \
 */                                                                                                                                             \

**_copy()**
 /**                                                                                                                                             \
 * @brief Copies contents of one vector to another.                                                                                             \
 * @param dest Destination vector pointer.                                                                                                      \
 * @param source Source vector pointer.                                                                                                         \
 */                                                                                                                                             \

**_move()**
 /**                                                                                                                                             \
 * @brief Moves contents from one vector to another.                                                                                            \
 * @param dest Destination vector pointer.                                                                                                      \
 * @param source Source vector pointer.                                                                                                         \
 */                                                                                                                                             \

**_equals()**
 /**                                                                                                                                             \
 * @brief Checks whether two vectors are equal by comparing each element.                                                                       \
 * @param left Left-hand side pointer to a vector.                                                                                              \
 * @param right Right-hand side pointer to a vector.                                                                                            \
 * @return `true` if equal, `false` otherwise.                                                                                                  \
 */                                                                                                                                             \

**_create_capacity()**
 /**                                                                                                                                             \
 * @brief Creates a vector struct and allocates dynamic array.                                                                                  \
 * @param capacity Initial capacity of the vector.                                                                                              \
 * @return A new instance of VECTOR_NAME.                                                                                                       \
 */                                                                                                                                             \

**_clear()**
 /**                                                                                                                                             \
 * @brief Clears the vector contents but retains capacity.                                                                                      \
 * @param target Pointer to the vector.                                                                                                         \
 */                                                                                                                                             \

**_data()**
/**                                                                                                                                             \
 * @brief Returns the internal data array.                                                                                                      \
 * @param target Pointer to vector.                                                                                                             \
 * @return Pointer to the data array.                                                                                                           \
 */                                                                                                                                             \

**_data_const()**
/**                                                                                                                                             \
 * @brief Returns the internal data array.                                                                                                      \
 * @param target Pointer to vector.                                                                                                             \
 * @return Pointer to the data array.                                                                                                           \
 */                                                                                                                                             \

**_size()**
/**                                                                                                                                             \
 * @brief Returns the number of elements in the vector.                                                                                         \
 * @param target Pointer to vector.                                                                                                             \
 * @return Number of elements.                                                                                                                  \
 */                                                                                                                                             \

**_capacity()**
/**                                                                                                                                             \
 * @brief Returns the current capacity of the vector.                                                                                           \
 * @param target Pointer to vector.                                                                                                             \
 * @return Current capacity.                                                                                                                    \
 */                                                                                                                                             \

**_empty()**
/**                                                                                                                                             \
 * @brief Checks if the vector is empty.                                                                                                        \
 * @param target Pointer to vector.                                                                                                             \
 * @return `true` if empty, `false` otherwise.                                                                                                  \
 */                                                                                                                                             \

**_push_back()**
/**                                                                                                                                             \
 * @brief Adds a default element to the end of the vector.                                                                                      \
 * @param target Pointer to vector.                                                                                                             \
 */                                                                                                                                             \

**_push_back_copy()**
/**                                                                                                                                             \
 * @brief Adds an element to the end of the vector.                                                                                             \
 * @param target Pointer to vector.                                                                                                             \
 * @param item Pointer to item to copy push.                                                                                                    \
 */                                                                                                                                             \

**_push_back_move()**
/**                                                                                                                                             \
 * @brief Adds an element to the end of the vector.                                                                                             \
 * @param target Pointer to vector.                                                                                                             \
 * @param item Pointer to item to move push.                                                                                                    \
 */                                                                                                                                             \

**_pop_back()**
/**                                                                                                                                             \
 * @brief Removes the last element from the vector.                                                                                             \
 * @param target Pointer to vector.                                                                                                             \
 */                                                                                                                                             \

**_element_front()**
/**                                                                                                                                             \
 * @brief Returns a pointer to the first element.                                                                                               \
 * @param target Pointer to vector.                                                                                                             \
 * @return Pointer to the first element.                                                                                                        \
 */                                                                                                                                             \

**_element_front_const()**
/**                                                                                                                                             \
 * @brief Returns a pointer to the first element.                                                                                               \
 * @param target Pointer to vector.                                                                                                             \
 * @return Pointer to the first element.                                                                                                        \
 */                                                                                                                                             \

**_element_back()**
/**                                                                                                                                             \
 * @brief Returns a pointer to the last element.                                                                                                \
 * @param target Pointer to vector.                                                                                                             \
 * @return Pointer to the last element.                                                                                                         \
 */                                                                                                                                             \

**_element_back_const()**
/**                                                                                                                                             \
 * @brief Returns a pointer to the last element.                                                                                                \
 * @param target Pointer to vector.                                                                                                             \
 * @return Pointer to the last element.                                                                                                         \
 */                                                                                                                                             \

**_element_at()**
/**                                                                                                                                             \
 * @brief Returns a pointer to the element at index.                                                                                            \
 * @param target Pointer to vector.                                                                                                             \
 * @param index Position of the element to get.                                                                                                 \
 * @return Pointer to the element at index.                                                                                                     \
 */                                                                                                                                             \

**_element_at_const()**
/**                                                                                                                                             \
 * @brief Returns a pointer to the element at index.                                                                                            \
 * @param target Pointer to vector.                                                                                                             \
 * @param index Position of the element to get.                                                                                                 \
 * @return Pointer to the element at index.                                                                                                     \
 */                                                                                                                                             \

**_begin()**
/**                                                                                                                                             \
 * @brief Returns an iterator to the first element in vector.                                                                                   \
 * @param target Pointer to vector.                                                                                                             \
 * @return A new instance of VECTOR_ITERATOR_NAME.                                                                                              \
 */                                                                                                                                             \

**_end()**
/**                                                                                                                                             \
 * @brief Returns an iterator to the last + 1 element in vector.                                                                                \
 * @param target Pointer to vector.                                                                                                             \
 * @return A new instance of VECTOR_ITERATOR_NAME.                                                                                              \
 */                                                                                                                                             \

