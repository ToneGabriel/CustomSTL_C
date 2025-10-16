# C_UNORDERED_SET


## Macros

**DEFINE_GENERIC_UNORDERED_SET**
- `@brief` Define a generic unordered set and iterators for given key type with all required dependencies.
- `@param` `UNORDERED_SET_NAME_PUBLIC_PREFIX`   The public name prefix for generated unordered set (e.g., `MyUSet` -> `MyUSet_create`, etc.).
- `@param` `KEY_TYPE`                           Typedef for key stored in the unordered set. (also the mapped value type)


**Notes**
- For default types and pointers: `KEY_TYPE` must be created with `DEFINE_DEFAULT_TYPE_PUBLIC_MEMBERS`
- For custom structs: `KEY_TYPE` must have all default function definitions:
    - `DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE`
    - `DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY`
    - `DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_COPY`
    - `DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_MOVE`
    - `DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_EQUALS`
- Aditionaly: `KEY_TYPE` must have the hash function:
    - `DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_HASH`

<!-- ================================================================================================================== -->
<!-- END Macros -->
<!-- ================================================================================================================== -->
---

## Types

**UNORDERED_SET** - Unordered Set data struct. Name provided by user via `UNORDERED_SET_NAME_PUBLIC_PREFIX` macro parameter. **All other types and functions have this prefix**.

**UNORDERED_SET_ConstIterator** - Struct used to iterate over a uset. Dereference function returns a `const` pointer to key-value element.

**UNORDERED_SET_Iterator** - Struct used to iterate over a uset. Dereference function returns a pointer to key-value element.

<!-- ================================================================================================================== -->
<!-- END Types -->
<!-- ================================================================================================================== -->
---

## Unordered Set Functions

<details>
<summary><b>Core Operations</b></summary>

##### UNORDERED_SET_create
- `@brief` Creates a uset struct and initializes it.
- `@return` A new uset instance.

##### UNORDERED_SET_destroy
- `@brief` Destroys a uset and releases allocated memory.
- `@param` `target` Pointer to the uset.

##### UNORDERED_SET_copy
- `@brief` Copies contents of one uset to another.
- `@param` `dest` Destination uset pointer.
- `@param` `source` Source uset pointer.

##### UNORDERED_SET_move
- `@brief` Moves contents from one uset to another. Valid operations after move: `UNORDERED_SET_copy` (as dest), `UNORDERED_SET_destroy`, `UNORDERED_SET_equals`
- `@param` `dest` Destination uset pointer.
- `@param` `source` Source uset pointer.

##### UNORDERED_SET_equals
- `@brief` Checks whether two vectors are equal by comparing each element. No need to have the same hashtable to be equal.
- `@param` `left` Left-hand side pointer to a uset.
- `@param` `right` Right-hand side pointer to a uset.
- `@return` `true` if equal, `false` otherwise.

</details>
<!-- ================================================================================================================== -->
<!-- END Core Operations -->
<!-- ================================================================================================================== -->

<details>
<summary><b>Lookup</b></summary>

##### UNORDERED_SET_element_at
- `@brief` Returns a pointer to the element at key.
- `@param` `target` Pointer to uset.
- `@param` `key` Pointer to key object.
- `@return` Pointer to the element at key or `NULL` if not found.
- `@note` Recommended only for `UNORDERED_MAP`

##### UNORDERED_SET_element_at_const
- `@brief` Returns a pointer to the element at key.
- `@param` `target` Pointer to uset.
- `@param` `key` Pointer to key object.
- `@return` Pointer to the element at key or `NULL` if not found.
- `@note` Recommended only for `UNORDERED_MAP`

##### UNORDERED_SET_contains
- `@brief` Checks if uset has an element with given key.
- `@param` `target` Pointer to uset.
- `@param` `key` Pointer to key object.
- `@return` `true` if found, `false` otherwise.

##### UNORDERED_SET_find
- `@brief` Returns an iterator to the element at key. If not found, `end` iterator is returned.
- `@param` `target` Pointer to uset.
- `@param` `key` Pointer to key object.
- `@return` New instance of `UNORDERED_SET_Iterator`.

##### UNORDERED_SET_find_const
- `@brief` Returns an iterator to the element at key. If not found, `end` iterator is returned.
- `@param` `target` Pointer to uset.
- `@param` `key` Pointer to key object.
- `@return` New instance of `UNORDERED_SET_ConstIterator`.

</details>
<!-- ================================================================================================================== -->
<!-- END Lookup -->
<!-- ================================================================================================================== -->

<details>
<summary><b>Capacity</b></summary>

##### UNORDERED_SET_size
- `@brief` Returns the number of elements in the uset.
- `@param` `target` Pointer to uset.
- `@return` Number of elements.

##### UNORDERED_SET_empty
- `@brief` Checks if the uset is empty.
- `@param` `target` Pointer to uset.
- `@return` `true` if empty, `false` otherwise.

</details>
<!-- ================================================================================================================== -->
<!-- END Capacity -->
<!-- ================================================================================================================== -->

<details>
<summary><b>Bucket Interface</b></summary>

##### UNORDERED_SET_bucket_count
- `@brief` Returns the number of buckets in the uset.
- `@param` `target` Pointer to uset.
- `@return` Number of buckets.

##### UNORDERED_SET_bucket_size
- `@brief` Returns the number of elements in bucket at index in the uset.
- `@param` `target` Pointer to uset.
- `@param` `index` Index of bucket.
- `@return` Number of elements in bucket.

##### UNORDERED_SET_bucket
- `@brief` Returns the index of bucket with key in the uset.
- `@param` `target` Pointer to uset.
- `@param` `key` Pointer to key object.
- `@return` Index of bucket for key.

</details>
<!-- ================================================================================================================== -->
<!-- END Bucket Interface -->
<!-- ================================================================================================================== -->

<details>
<summary><b>Hash Policy</b></summary>

##### UNORDERED_SET_load_factor
- `@brief` Returns the average number of elements per bucket: `size / bucket_count`.
- `@param` `target` Pointer to uset.
- `@return` Average number of elements per bucket.

##### UNORDERED_SET_max_load_factor
- `@brief` Returns the maximum load factor admitted before rehasing.
- `@param` `target` Pointer to uset.
- `@return` Maximum load factor.

##### UNORDERED_SET_rehash
- `@brief` Changes the number of buckets to a value `n` that is not less than `nobuckets` and satisfies `n >= size / max_load_factor`, then rehashes the container, i.e. puts the elements into appropriate buckets considering that total number of buckets has changed.
- `@param` `target` Pointer to uset.
- `@param` `nobuckets` Lower bound for the new number of buckets

</details>
<!-- ================================================================================================================== -->
<!-- END Hash Policy -->
<!-- ================================================================================================================== -->

<details>
<summary><b>Modifiers</b></summary>

##### UNORDERED_SET_clear
- `@brief` Clears the uset contents but retains bucket_count.
- `@param` `target` Pointer to the uset.

##### UNORDERED_SET_emplace
- `@brief` Adds an element to the uset and returns an iterator to it. If key already exists, return an iterator to existing element.
- `@param` `target` Pointer to uset.
- `@param` `item` Pointer to object to emplace.
- `@return` New instance of `UNORDERED_SET_Iterator`.

##### UNORDERED_SET_emplace_key_map
- `@brief` Adds an element to the uset and returns an iterator to it. If key already exists, return an iterator to existing element.
- `@param` `target` Pointer to uset.
- `@param` `key` Pointer to key object.
- `@param` `item` Pointer to mapped object.
- `@return` New instance of `UNORDERED_SET_Iterator`.
- `@note` Recommended only for `UNORDERED_MAP`

##### UNORDERED_SET_erase
- `@brief` Removes the element from the uset with given key and return an iterator to next element (`TODO`: implement). If not found, return `end` iterator.
- `@param` `target` Pointer to uset.
- `@param` `key` Pointer to key object.
- `@return` New instance of `UNORDERED_SET_Iterator`.

##### UNORDERED_SET_erase_iterator
- `@brief` Removes the element from the uset at iterator and return an iterator to next element (`TODO`: implement).
- `@param` `target` Pointer to uset.
- `@param` `where` Pointer to iterator object.
- `@return` New instance of `UNORDERED_SET_Iterator`.

##### UNORDERED_SET_erase_iterator_const
- `@brief` Removes the element from the uset at iterator and return an iterator to next element (`TODO`: implement).
- `@param` `target` Pointer to uset.
- `@param` `where` Pointer to iterator object.
- `@return` New instance of `UNORDERED_SET_Iterator`.

</details>
<!-- ================================================================================================================== -->
<!-- END Modifiers -->
<!-- ================================================================================================================== -->

<details>
<summary><b>Iterators</b></summary>

##### UNORDERED_SET_begin_const
- `@brief` Returns an iterator to the first element in uset.
- `@param` `target` Pointer to uset.
- `@return` A new instance of `UNORDERED_SET_ConstIterator`.

##### UNORDERED_SET_begin
- `@brief` Returns an iterator to the first element in uset.
- `@param` `target` Pointer to uset.
- `@return` A new instance of `UNORDERED_SET_Iterator`.

##### UNORDERED_SET_end_const
- `@brief` Returns an iterator past the last element in uset.
- `@param` `target` Pointer to uset.
- `@return` A new instance of `UNORDERED_SET_ConstIterator`.

##### UNORDERED_SET_end
- `@brief` Returns an iterator past the last element in uset.
- `@param` `target` Pointer to uset.
- `@return` A new instance of `UNORDERED_SET_Iterator`.

</details>
<!-- ================================================================================================================== -->
<!-- END Iterators -->
<!-- ================================================================================================================== -->

<!-- ================================================================================================================== -->
<!-- END Unordered Set Functions -->
<!-- ================================================================================================================== -->
---

## ConstIterator and Iterator Functions

<details>
<summary><b>Core Operations</b></summary>

##### UNORDERED_SET_ConstIterator_create / UNORDERED_SET_Iterator_create
- `@brief` Creates an iterator struct
- `@return` A new iterator instance.

##### UNORDERED_SET_ConstIterator_destroy / UNORDERED_SET_Iterator_destroy
- `@brief` Destroys an iterator.
- `@param` `target` Pointer to the iterator.

##### UNORDERED_SET_ConstIterator_copy / UNORDERED_SET_Iterator_copy
- `@brief` Copies contents of one iterator to another.
- `@param` `dest` Destination iterator pointer.
- `@param` `source` Source iterator pointer.

##### UNORDERED_SET_ConstIterator_move / UNORDERED_SET_Iterator_move
- `@brief` Moves contents from one iterator to another.
- `@param` `dest` Destination iterator pointer.
- `@param` `source` Source iterator pointer.

##### UNORDERED_SET_ConstIterator_equals / UNORDERED_SET_Iterator_equals
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

##### UNORDERED_SET_ConstIterator_dereference / UNORDERED_SET_Iterator_dereference
- `@brief` Return a pointer to current element.
- `@param` `target` Pointer to the iterator.
- `@return` Pointer to element.

</details>
<!-- ================================================================================================================== -->
<!-- END Element Access -->
<!-- ================================================================================================================== -->

<details>
<summary><b>Iteration</b></summary>

##### UNORDERED_SET_ConstIterator_pre_increment / UNORDERED_SET_Iterator_pre_increment
- `@brief` Increment by 1.
- `@param` `target` Pointer to the iterator.

##### UNORDERED_SET_ConstIterator_post_increment / UNORDERED_SET_Iterator_post_increment
- `@brief` Increment by 1 and return non-incremented iterator.
- `@param` `target` Pointer to the iterator.
- `@return` Non-incremented iterator.

##### UNORDERED_SET_ConstIterator_pre_decrement / UNORDERED_SET_Iterator_pre_decrement
- `@brief` Decrement by 1.
- `@param` `target` Pointer to the iterator.

##### UNORDERED_SET_ConstIterator_post_decrement / UNORDERED_SET_Iterator_post_decrement
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
#include "custom/c_unordered_set.h"

DEFINE_DEFAULT_TYPE_PUBLIC_MEMBERS(unsigned int, myuint_t)  // this also includes hashing
DEFINE_GENERIC_UNORDERED_SET(USet, myuint_t)

int main()
{
    USet set = USet_create();

    myuint_t key = 1;
    (void)USet_emplace(&set, &key);

    key = 2;
    (void)USet_emplace(&set, &key);

    key = 3;
    (void)USet_emplace(&set, &key);

    C_FOR_EACH(USet, myuint_t, set, val)
        printf("Value: %d\n", *val);

    USet_destroy(&set);

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