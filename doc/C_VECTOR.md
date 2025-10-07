# C_VECTOR


## Macros

**GENERIC_VECTOR_DEFAULT_CAPACITY**
- `@brief` Default capacity used in vector create function.


**DEFINE_GENERIC_VECTOR**
- `@brief` Define a generic vector for a given type with all required dependencies.
- `@param` `VECTOR_NAME_PUBLIC_PREFIX`  The public name prefix for generated vector. (e.g., `MyVec` -> `MyVec_create`, etc.).
- `@param` `TYPE`                       Type stored in the vector.

**Notes**
- For default types and pointers: `TYPE` must be created with `DEFINE_DEFAULT_TYPE_PUBLIC_MEMBERS`
- For custom structs: `TYPE` must have all default function definitions:
    - `DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE`
    - `DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY`
    - `DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_COPY`
    - `DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_MOVE`
    - `DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_EQUALS`

<!-- ================================================================================================================== -->
<!-- END Macros -->
<!-- ================================================================================================================== -->
---

## Types

**VECTOR** - Vector data struct. Name provided by user via `VECTOR_NAME_PUBLIC_PREFIX` macro parameter. **All other types and functions have this prefix**.

**VECTOR_ConstIterator** - Struct used to iterate over a vector. Dereference function returns a `const` pointer to element.

**VECTOR_Iterator** - Struct used to iterate over a vector. Dereference function returns a pointer to element.

<!-- ================================================================================================================== -->
<!-- END Types -->
<!-- ================================================================================================================== -->
---

## Vector Functions

<details>
<summary><b>Core Operations</b></summary>

##### VECTOR_create
- `@brief` Creates a vector struct and allocates dynamic array with default capacity.
- `@return` A new vector instance.

##### VECTOR_create_capacity
- `@brief` Creates a vector struct and allocates dynamic array.
- `@param` `capacity` Initial capacity of the vector.
- `@return` A new vector instance.

##### VECTOR_destroy
- `@brief` Destroys a vector and releases allocated memory.
- `@param` `target` Pointer to the vector.

##### VECTOR_copy
- `@brief` Copies contents of one vector to another.
- `@param` `dest` Destination vector pointer.
- `@param` `source` Source vector pointer.

##### VECTOR_move
- `@brief` Moves contents from one vector to another. Valid operations after move: `VECTOR_copy` (as dest), `VECTOR_destroy`, `VECTOR_equals`
- `@param` `dest` Destination vector pointer.
- `@param` `source` Source vector pointer.

##### VECTOR_equals
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

##### VECTOR_data
- `@brief` Returns the internal data array.
- `@param` `target` Pointer to vector.
- `@return` Pointer to the data array.

##### VECTOR_data_const
- `@brief` Returns the internal data array.
- `@param` `target` Pointer to vector.
- `@return` Pointer to the data array.

##### VECTOR_element_front
- `@brief` Returns a pointer to the first element.
- `@param` `target` Pointer to vector.
- `@return` Pointer to the first element.

##### VECTOR_element_front_const
- `@brief` Returns a pointer to the first element.
- `@param` `target` Pointer to vector.
- `@return` Pointer to the first element.

##### VECTOR_element_back
- `@brief` Returns a pointer to the last element.
- `@param` `target` Pointer to vector.
- `@return` Pointer to the last element.

##### VECTOR_element_back_const
- `@brief` Returns a pointer to the last element.
- `@param` `target` Pointer to vector.
- `@return` Pointer to the last element.

##### VECTOR_element_at
- `@brief` Returns a pointer to the element at index.
- `@param` `target` Pointer to vector.
- `@param` `index` Position of the element to get.
- `@return` Pointer to the element at index.

##### VECTOR_element_at_const
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

##### VECTOR_size
- `@brief` Returns the number of elements in the vector.
- `@param` `target` Pointer to vector.
- `@return` Number of elements.

##### VECTOR_capacity
- `@brief` Returns the current capacity of the vector.
- `@param` `target` Pointer to vector.
- `@return` Current capacity.

##### VECTOR_empty
- `@brief` Checks if the vector is empty.
- `@param` `target` Pointer to vector.
- `@return` `true` if empty, `false` otherwise.

</details>
<!-- ================================================================================================================== -->
<!-- END Capacity -->
<!-- ================================================================================================================== -->

<details>
<summary><b>Modifiers</b></summary>

##### VECTOR_clear
- `@brief` Clears the vector contents but retains capacity.
- `@param` `target` Pointer to the vector.

##### VECTOR_push_back
- `@brief` Adds a default element to the end of the vector.
- `@param` `target` Pointer to vector.

##### VECTOR_push_back_copy
- `@brief` Adds an element to the end of the vector.
- `@param` `target` Pointer to vector.
- `@param` `item` Pointer to object to copy push.

##### VECTOR_push_back_move
- `@brief` Adds an element to the end of the vector.
- `@param` `target` Pointer to vector.
- `@param` `item` Pointer to object to move push.

##### VECTOR_pop_back
- `@brief` Removes the last element from the vector.
- `@param` `target` Pointer to vector.

##### VECTOR_realloc
- `@brief` Removes all elements, reallocates new capacity and populates it with default elements.
- `@param` `target` Pointer to vector.
- `@param` `capacity` New capacity.

##### VECTOR_realloc_copy
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

##### VECTOR_begin_const
- `@brief` Returns an iterator to the first element in vector.
- `@param` `target` Pointer to vector.
- `@return` A new instance of `VECTOR_ConstIterator`.

##### VECTOR_begin
- `@brief` Returns an iterator to the first element in vector.
- `@param` `target` Pointer to vector.
- `@return` A new instance of `VECTOR_Iterator`.

##### VECTOR_end_const
- `@brief` Returns an iterator past the last element in vector.
- `@param` `target` Pointer to vector.
- `@return` A new instance of `VECTOR_ConstIterator`.

##### VECTOR_end
- `@brief` Returns an iterator past the last element in vector.
- `@param` `target` Pointer to vector.
- `@return` A new instance of `VECTOR_Iterator`.

</details>
<!-- ================================================================================================================== -->
<!-- END Iterators -->
<!-- ================================================================================================================== -->

<!-- ================================================================================================================== -->
<!-- END Vector Functions -->
<!-- ================================================================================================================== -->
---

## ConstIterator and Iterator Functions

<details>
<summary><b>Core Operations</b></summary>

##### VECTOR_ConstIterator_create / VECTOR_Iterator_create
- `@brief` Creates an iterator struct
- `@return` A new iterator instance.

##### VECTOR_ConstIterator_destroy / VECTOR_Iterator_destroy
- `@brief` Destroys an iterator.
- `@param` `target` Pointer to the iterator.

##### VECTOR_ConstIterator_copy / VECTOR_Iterator_copy
- `@brief` Copies contents of one iterator to another.
- `@param` `dest` Destination iterator pointer.
- `@param` `source` Source iterator pointer.

##### VECTOR_ConstIterator_move / VECTOR_Iterator_move
- `@brief` Moves contents from one iterator to another.
- `@param` `dest` Destination iterator pointer.
- `@param` `source` Source iterator pointer.

##### VECTOR_ConstIterator_equals / VECTOR_Iterator_equals
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

##### VECTOR_ConstIterator_dereference / VECTOR_Iterator_dereference
- `@brief` Return a pointer to current element.
- `@param` `target` Pointer to the iterator.
- `@return` Pointer to element.

</details>
<!-- ================================================================================================================== -->
<!-- END Element Access -->
<!-- ================================================================================================================== -->

<details>
<summary><b>Iteration</b></summary>

##### VECTOR_ConstIterator_pre_increment / VECTOR_Iterator_pre_increment
- `@brief` Increment by 1.
- `@param` `target` Pointer to the iterator.

##### VECTOR_ConstIterator_post_increment / VECTOR_Iterator_post_increment
- `@brief` Increment by 1 and return non-incremented iterator.
- `@param` `target` Pointer to the iterator.
- `@return` Non-incremented iterator.

##### VECTOR_ConstIterator_increment_by / VECTOR_Iterator_increment_by
- `@brief` Increment by given number.
- `@param` `target` Pointer to the iterator.
- `@param` `diff` Number to apply increment.

##### VECTOR_ConstIterator_increment / VECTOR_Iterator_increment
- `@brief` Increment by given number and return non-incremented iterator.
- `@param` `target` Pointer to the iterator.
- `@param` `diff` Number to apply increment.
- `@return` Non-incremented iterator.

##### VECTOR_ConstIterator_pre_decrement / VECTOR_Iterator_pre_decrement
- `@brief` Decrement by 1.
- `@param` `target` Pointer to the iterator.

##### VECTOR_ConstIterator_post_decrement / VECTOR_Iterator_post_decrement
- `@brief` Decrement by 1 and return non-decremented iterator.
- `@param` `target` Pointer to the iterator.
- `@return` Non-decremented iterator.

##### VECTOR_ConstIterator_decrement_by / VECTOR_Iterator_decrement_by
- `@brief` Decrement by given number.
- `@param` `target` Pointer to the iterator.
- `@param` `diff` Number to apply decrement.

##### VECTOR_ConstIterator_decrement / VECTOR_Iterator_decrement
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
---

## Usage

```C
#include "custom/c_vector.h"

// define custom struct
typedef struct
{
    int a;
    int* b;
} MyStruct;

// define custom memory management behavior

// custom create
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(MyStruct)
{
    return (MyStruct){
        .a = 0,
        .b = NULL
    };
}

// custom destroy
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(MyStruct)
{
    if (target->b)
        free(target->b);
}

// custom copy
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_COPY(MyStruct)
{
    if (dest == source) return;

    dest->a = source->a;

    if (dest->b)
        free(dest->b);

    if (source->b)
    {
        dest->b = (int*)malloc(sizeof(int));
        *dest->b = *source->b;
    }
    else
        dest->b = NULL;
}

// custom move
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_MOVE(MyStruct)
{
    if (dest == source) return;

    *dest = *source;
    source->a = 0;
    source->b = NULL;
}

// custom equals
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_EQUALS(MyStruct)
{
    return left->a == right->a && left->b == right->b;
}

// define the vector for the struct
DEFINE_GENERIC_VECTOR(MyStructVector, MyStruct)

int main()
{
    MyStructVector vec = MyStructVector_create();
    MyStruct s = MyStruct_create();

    s.a = 1;
    MyStructVector_push_back_copy(&vec, &s);

    s.a = 2;
    MyStructVector_push_back_copy(&vec, &s);

    s.a = 3;
    MyStructVector_push_back_copy(&vec, &s);

    size_t size = MyStructVector_size(&vec);
    for (size_t i = 0; i < size; ++i)
        printf("Value: %d\n", MyStructVector_element_at(&vec, i)->a);

    MyStructVector_destroy(&vec);
    MyStruct_destroy(&s);

    return 0;
}

// Prints:
// Value: 1
// Value: 2
// Value: 3

```

<!-- ================================================================================================================== -->
<!-- END Usage -->
<!-- ================================================================================================================== -->
---