# C_VECTOR


## Macros

**GENERIC_VECTOR_DEFAULT_CAPACITY**
- `@brief` Default capacity used in vector `_create` function


**DEFINE_GENERIC_VECTOR**
- `@brief` Define a generic vector for a given type with all required dependencies.
- `@param` `VECTOR_NAME_PUBLIC_PREFIX`  The public name prefix for generated vector. (e.g., `MyVec` -> `MyVec_create`, etc.).
- `@param` `TYPE`                       Type stored in the vector.

<!-- ================================================================================================================== -->
<!-- END Macros -->
<!-- ================================================================================================================== -->


## Types

**VECTOR** - Vector data struct. Name provided by user via `VECTOR_NAME_PUBLIC_PREFIX` macro parameter. ALL other types and functions have this prefix.

**_ConstIterator** - Struct used to iterate over a vector. `_dereference` function returns a `const` pointer to element.

**_Iterator** - Struct used to iterate over a vector. `_dereference` function returns a pointer to element.

<!-- ================================================================================================================== -->
<!-- END Types -->
<!-- ================================================================================================================== -->


## Vector Functions

<details>
<summary><b>Core Operations</b></summary>

**_create**
- `@brief` Creates a vector struct and allocates dynamic array with default capacity.
- `@return` A new vector instance.

**_create_capacity**
- `@brief` Creates a vector struct and allocates dynamic array.
- `@param` `capacity` Initial capacity of the vector.
- `@return` A new vector instance.

**_destroy**
- `@brief` Destroys a vector and releases allocated memory.
- `@param` `target` Pointer to the vector.

**_copy**
- `@brief` Copies contents of one vector to another.
- `@param` `dest` Destination vector pointer.
- `@param` `source` Source vector pointer.

**_move**
- `@brief` Moves contents from one vector to another.
- `@param` `dest` Destination vector pointer.
- `@param` `source` Source vector pointer.

**_equals**
- `@brief` Checks whether two vectors are equal by comparing each element.
- `@param` `left` Left-hand side pointer to a vector.
- `@param` `right` Right-hand side pointer to a vector.
- `@return` `true` if equal, `false` otherwise.

</details>
<!-- ================================================================================================================== -->
<!-- END Core Operations -->
<!-- ================================================================================================================== -->

<details>
<summary><b>Element Access</b></summary>

**_data**
- `@brief` Returns the internal data array.
- `@param` `target` Pointer to vector.
- `@return` Pointer to the data array.

**_data_const**
- `@brief` Returns the internal data array.
- `@param` `target` Pointer to vector.
- `@return` Pointer to the data array.

**_element_front**
- `@brief` Returns a pointer to the first element.
- `@param` `target` Pointer to vector.
- `@return` Pointer to the first element.

**_element_front_const**
- `@brief` Returns a pointer to the first element.
- `@param` `target` Pointer to vector.
- `@return` Pointer to the first element.

**_element_back**
- `@brief` Returns a pointer to the last element.
- `@param` `target` Pointer to vector.
- `@return` Pointer to the last element.

**_element_back_const**
- `@brief` Returns a pointer to the last element.
- `@param` `target` Pointer to vector.
- `@return` Pointer to the last element.

**_element_at**
- `@brief` Returns a pointer to the element at index.
- `@param` `target` Pointer to vector.
- `@param` `index` Position of the element to get.
- `@return` Pointer to the element at index.

**_element_at_const**
- `@brief` Returns a pointer to the element at index.
- `@param` `target` Pointer to vector.
- `@param` `index` Position of the element to get.
- `@return` Pointer to the element at index.

</details>
<!-- ================================================================================================================== -->
<!-- END Element Access -->
<!-- ================================================================================================================== -->

<details>
<summary><b>Capacity</b></summary>

**_size**
- `@brief` Returns the number of elements in the vector.
- `@param` `target` Pointer to vector.
- `@return` Number of elements.

**_capacity**
- `@brief` Returns the current capacity of the vector.
- `@param` `target` Pointer to vector.
- `@return` Current capacity.

**_empty**
- `@brief` Checks if the vector is empty.
- `@param` `target` Pointer to vector.
- `@return` `true` if empty, `false` otherwise.

</details>
<!-- ================================================================================================================== -->
<!-- END Capacity -->
<!-- ================================================================================================================== -->

<details>
<summary><b>Modifiers</b></summary>

**_clear**
- `@brief` Clears the vector contents but retains capacity.
- `@param` `target` Pointer to the vector.

**_push_back**
- `@brief` Adds a default element to the end of the vector.
- `@param` `target` Pointer to vector.

**_push_back_copy**
- `@brief` Adds an element to the end of the vector.
- `@param` `target` Pointer to vector.
- `@param` `item` Pointer to object to copy push.

**_push_back_move**
- `@brief` Adds an element to the end of the vector.
- `@param` `target` Pointer to vector.
- `@param` `item` Pointer to object to move push.

**_pop_back**
- `@brief` Removes the last element from the vector.
- `@param` `target` Pointer to vector.

**_realloc**
- `@brief` Removes all elements, reallocates new capacity and populates it with default elements.
- `@param` `target` Pointer to vector.
- `@param` `capacity` New capacity.

**realloc_copy**
- `@brief` Removes all elements, reallocates new capacity and populates it with copy constructed elements.
- `@param` `target` Pointer to vector.
- `@param` `capacity` New capacity.
- `@param` `item` Pointer to object to copy push.

</details>
<!-- ================================================================================================================== -->
<!-- END Modifiers -->
<!-- ================================================================================================================== -->

<details>
<summary><b>Iterators</b></summary>

**_begin_const**
- `@brief` Returns a const_iterator to the first element in vector.
- `@param` `target` Pointer to vector.
- `@return` A new instance of `_ConstIterator`.

**_begin**
- `@brief` Returns an iterator to the first element in vector.
- `@param` `target` Pointer to vector.
- `@return` A new instance of `_Iterator`.

**_end_const**
- `@brief` Returns a const_iterator to the last + 1 element in vector.
- `@param` `target` Pointer to vector.
- `@return` A new instance of `_ConstIterator`.

**_end**
- `@brief` Returns an iterator to the last + 1 element in vector.
- `@param` `target` Pointer to vector.
- `@return` A new instance of `_Iterator`.

</details>
<!-- ================================================================================================================== -->
<!-- END Iterators -->
<!-- ================================================================================================================== -->

<!-- ================================================================================================================== -->
<!-- END Vector Functions -->
<!-- ================================================================================================================== -->

## ConstIterator and Iterator Functions

<details>
<summary><b>Core Operations</b></summary>

**_ConstIterator_create / _Iterator_create**
- `@brief` Creates an iterator struct
- `@return` A new iterator instance.

**_ConstIterator_destroy / _Iterator_destroy**
- `@brief` Destroys an iterator.
- `@param` `target` Pointer to the iterator.

**_ConstIterator_copy / _Iterator_copy**
- `@brief` Copies contents of one iterator to another.
- `@param` `dest` Destination iterator pointer.
- `@param` `source` Source iterator pointer.

**_ConstIterator_move / _Iterator_move**
- `@brief` Moves contents from one iterator to another.
- `@param` `dest` Destination iterator pointer.
- `@param` `source` Source iterator pointer.

**_ConstIterator_equals / _Iterator_equals**
- `@brief` Checks whether two iterators are equal by comparing current position element.
- `@param` `left` Left-hand side pointer to an iterator.
- `@param` `right` Right-hand side pointer to an iterator.
- `@return` `true` if equal, `false` otherwise.

</details>
<!-- ================================================================================================================== -->
<!-- END Core Operations -->
<!-- ================================================================================================================== -->

<details>
<summary><b>Element Access</b></summary>

**_ConstIterator_dereference / _Iterator_dereference**
- `@brief` Return a pointer to current element.
- `@param` `target` Pointer to the iterator.
- `@return` Pointer to element.

</details>
<!-- ================================================================================================================== -->
<!-- END Element Access -->
<!-- ================================================================================================================== -->

<details>
<summary><b>Iteration</b></summary>

**_ConstIterator_pre_increment / _Iterator_pre_increment**
- `@brief` Increment by 1.
- `@param` `target` Pointer to the iterator.

**_ConstIterator_post_increment / _Iterator_post_increment**
- `@brief` Increment by 1 and return non-incremented iterator.
- `@param` `target` Pointer to the iterator.
- `@return` Non-incremented iterator.

**_ConstIterator_increment_by / _Iterator_increment_by**
- `@brief` Increment by given number.
- `@param` `target` Pointer to the iterator.
- `@param` `diff` Number to apply increment.

**_ConstIterator_increment / _Iterator_increment**
- `@brief` Increment by given number and return non-incremented iterator.
- `@param` `target` Pointer to the iterator.
- `@param` `diff` Number to apply increment.
- `@return` Non-incremented iterator.

**_ConstIterator_pre_decrement / _Iterator_pre_decrement**
- `@brief` Decrement by 1.
- `@param` `target` Pointer to the iterator.

**_ConstIterator_post_decrement / _Iterator_post_decrement**
- `@brief` Decrement by 1 and return non-decremented iterator.
- `@param` `target` Pointer to the iterator.
- `@return` Non-decremented iterator.

**_ConstIterator_decrement_by / _Iterator_decrement_by**
- `@brief` Decrement by given number.
- `@param` `target` Pointer to the iterator.
- `@param` `diff` Number to apply decrement.

**_ConstIterator_decrement / _Iterator_decrement**
- `@brief` Decrement by given number and return non-decremented iterator.
- `@param` `target` Pointer to the iterator.
- `@param` `diff` Number to apply decrement.
- `@return` Non-decremented iterator.

</details>
<!-- ================================================================================================================== -->
<!-- END Iteration -->
<!-- ================================================================================================================== -->

<!-- ================================================================================================================== -->
<!-- END ConstIterator and Iterator Functions -->
<!-- ================================================================================================================== -->