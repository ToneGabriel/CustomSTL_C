# C_LIST


## Macros

**DEFINE_GENERIC_LIST**
- `@brief` Define a generic list for a given type with all required dependencies.
- `@param` `LIST_NAME_PUBLIC_PREFIX`    The public name prefix for generated list. (e.g., `MyList` -> `MyList_create`, etc.).
- `@param` `TYPE`                       Type stored in the list.

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

**LIST** - List data struct. Name provided by user via `LIST_NAME_PUBLIC_PREFIX` macro parameter. **All other types and functions have this prefix**.

**LIST_ConstIterator** - Struct used to iterate over a list. Dereference function returns a `const` pointer to element.

**LIST_Iterator** - Struct used to iterate over a list. Dereference function returns a pointer to element.

<!-- ================================================================================================================== -->
<!-- END Types -->
<!-- ================================================================================================================== -->
---

## List Functions

<details>
<summary><b>Core Operations</b></summary>

##### LIST_create
- `@brief` Creates a list struct. Head node is linked to itself and the value is uninitialized (never used).
- `@return` A new list instance.

##### LIST_destroy
- `@brief` Destroys a list and releases head node memory.
- `@param` `target` Pointer to the list.

##### LIST_copy
- `@brief` Copies contents of one list to another.
- `@param` `dest` Destination list pointer.
- `@param` `source` Source list pointer.

##### LIST_move
- `@brief` Moves contents from one list to another. Valid operations after move: `LIST_copy` (as dest), `LIST_destroy`, `LIST_equals`
- `@param` `dest` Destination list pointer.
- `@param` `source` Source list pointer.

##### LIST_equals
- `@brief` Checks whether two lists are equal by comparing each element.
- `@param` `left` Left-hand side pointer to a list.
- `@param` `right` Right-hand side pointer to a list.
- `@return` `true` if equal, `false` otherwise.

</details>
<!-- ================================================================================================================== -->
<!-- END Core Operations -->
<!-- ================================================================================================================== -->

<details>
<summary><b>Element Access</b></summary>

##### LIST_element_front
- `@brief` Returns a pointer to the first element.
- `@param` `target` Pointer to list.
- `@return` Pointer to the first element.

##### LIST_element_front_const
- `@brief` Returns a pointer to the first element.
- `@param` `target` Pointer to list.
- `@return` Pointer to the first element.

##### LIST_element_back
- `@brief` Returns a pointer to the last element.
- `@param` `target` Pointer to list.
- `@return` Pointer to the last element.

##### LIST_element_back_const
- `@brief` Returns a pointer to the last element.
- `@param` `target` Pointer to list.
- `@return` Pointer to the last element.

</details>
<!-- ================================================================================================================== -->
<!-- END Element Access -->
<!-- ================================================================================================================== -->

<details>
<summary><b>Capacity</b></summary>

##### LIST_size
- `@brief` Returns the number of elements in the list.
- `@param` `target` Pointer to list.
- `@return` Number of elements.

##### LIST_empty
- `@brief` Checks if the list is empty.
- `@param` `target` Pointer to list.
- `@return` `true` if empty, `false` otherwise.

</details>
<!-- ================================================================================================================== -->
<!-- END Capacity -->
<!-- ================================================================================================================== -->

<details>
<summary><b>Modifiers</b></summary>

##### LIST_clear
- `@brief` Clears the list contents but not the head.
- `@param` `target` Pointer to the list.

##### LIST_push_back
- `@brief` Adds a default element to the end of the list.
- `@param` `target` Pointer to list.

##### LIST_push_back_copy
- `@brief` Adds an element to the end of the list.
- `@param` `target` Pointer to list.
- `@param` `item` Pointer to object to copy push.

##### LIST_push_back_move
- `@brief` Adds an element to the end of the list.
- `@param` `target` Pointer to list.
- `@param` `item` Pointer to object to move push.

##### LIST_pop_back
- `@brief` Removes the last element from the list.
- `@param` `target` Pointer to list.

##### LIST_push_front
- `@brief` Adds a default element to the start of the list.
- `@param` `target` Pointer to list.

##### LIST_push_front_copy
- `@brief` Adds an element to the start of the list.
- `@param` `target` Pointer to list.
- `@param` `item` Pointer to object to copy push.

##### LIST_push_front_move
- `@brief` Adds an element to the start of the list.
- `@param` `target` Pointer to list.
- `@param` `item` Pointer to object to move push.

##### LIST_pop_front
- `@brief` Removes the first element from the list.
- `@param` `target` Pointer to list.

</details>
<!-- ================================================================================================================== -->
<!-- END Modifiers -->
<!-- ================================================================================================================== -->

<details>
<summary><b>Iterators</b></summary>

##### LIST_begin_const
- `@brief` Returns an iterator to the first element in list.
- `@param` `target` Pointer to list.
- `@return` A new instance of `LIST_ConstIterator`.

##### LIST_begin
- `@brief` Returns an iterator to the first element in list.
- `@param` `target` Pointer to list.
- `@return` A new instance of `LIST_Iterator`.

##### LIST_end_const
- `@brief` Returns an iterator past the last element in list.
- `@param` `target` Pointer to list.
- `@return` A new instance of `LIST_ConstIterator`.

##### LIST_end
- `@brief` Returns an iterator past the last element in list.
- `@param` `target` Pointer to list.
- `@return` A new instance of `LIST_Iterator`.

</details>
<!-- ================================================================================================================== -->
<!-- END Iterators -->
<!-- ================================================================================================================== -->

<!-- ================================================================================================================== -->
<!-- END List Functions -->
<!-- ================================================================================================================== -->
---

## ConstIterator and Iterator Functions

<details>
<summary><b>Core Operations</b></summary>

##### LIST_ConstIterator_create / LIST_Iterator_create
- `@brief` Creates an iterator struct
- `@return` A new `LIST_ConstIterator` / `LIST_Iterator` instance.

##### LIST_ConstIterator_destroy / LIST_Iterator_destroy
- `@brief` Destroys an iterator.
- `@param` `target` Pointer to the iterator.

##### LIST_ConstIterator_copy / LIST_Iterator_copy
- `@brief` Copies contents of one iterator to another.
- `@param` `dest` Destination iterator pointer.
- `@param` `source` Source iterator pointer.

##### LIST_ConstIterator_move / LIST_Iterator_move
- `@brief` Moves contents from one iterator to another.
- `@param` `dest` Destination iterator pointer.
- `@param` `source` Source iterator pointer.

##### LIST_ConstIterator_equals / LIST_Iterator_equals
- `@brief` Checks whether two iterators are equal by comparing current node element.
- `@param` `left` Left-hand side pointer to an iterator.
- `@param` `right` Right-hand side pointer to an iterator.
- `@return` `true` if equal, `false` otherwise.

</details>
<!-- ================================================================================================================== -->
<!-- END Core Operations -->
<!-- ================================================================================================================== -->

<details>
<summary><b>Element Access</b></summary>

##### LIST_ConstIterator_dereference / LIST_Iterator_dereference
- `@brief` Return a pointer to current element.
- `@param` `target` Pointer to the iterator.
- `@return` Pointer to element.

</details>
<!-- ================================================================================================================== -->
<!-- END Element Access -->
<!-- ================================================================================================================== -->

<details>
<summary><b>Iteration</b></summary>

##### LIST_ConstIterator_pre_increment / LIST_Iterator_pre_increment
- `@brief` Increment by 1 (next node in list).
- `@param` `target` Pointer to the iterator.

##### LIST_ConstIterator_post_increment / LIST_Iterator_post_increment
- `@brief` Increment by 1 and return non-incremented iterator.
- `@param` `target` Pointer to the iterator.
- `@return` Non-incremented iterator.

##### LIST_ConstIterator_pre_decrement / LIST_Iterator_pre_decrement
- `@brief` Decrement by 1 (previous node in list).
- `@param` `target` Pointer to the iterator.

##### LIST_ConstIterator_post_decrement / LIST_Iterator_post_decrement
- `@brief` Decrement by 1 and return non-decremented iterator.
- `@param` `target` Pointer to the iterator.
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
#include "custom/c_list.h"

DEFINE_DEFAULT_TYPE_PUBLIC_MEMBERS(unsigned int, myuint_t)      // myuint_t is the typedef alias for desired type (use it in container definition)
DEFINE_GENERIC_LIST(UIntList, myuint_t)

int main()
{
    UIntList myUIntListInstance = UIntList_create();

    myuint_t val;

    val = 2;
    UIntList_push_back_copy(&myUIntListInstance, &val);

    val = 1;
    UIntList_push_front_copy(&myUIntListInstance, &val);

    val = 3;
    UIntList_push_back_copy(&myUIntListInstance, &val);

    while (!UIntList_empty(&myUIntListInstance))
    {
      printf("Value: %d\n", *element_front(&myUIntListInstance));
      UIntList_pop_front(&myUIntListInstance);
    }

    UIntList_destroy(&myUIntListInstance);

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