# C_UNORDERED_MAP


## Macros

**DEFINE_GENERIC_UNORDERED_MAP**
- `@brief` Define a generic unordered map and iterators for given key and mapped types with all required dependencies.
- `@param` `UNORDERED_MAP_NAME_PUBLIC_PREFIX`   The public name prefix for generated unordered map (e.g., `MyUMap` -> `MyUMap_create`, etc.).
- `@param` `KEY_TYPE`                           Typedef for key stored in the unordered map.
- `@param` `MAP_TYPE`                           Typedef for mapped value stored in the unordered map.


**Notes**
- For default types and pointers: `KEY_TYPE` and `MAP_TYPE` must be created with `DEFINE_DEFAULT_TYPE_PUBLIC_MEMBERS`
- For custom structs: `KEY_TYPE` and `MAP_TYPE` must have all default function definitions:
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

**UNORDERED_MAP** - Unordered Map data struct. Name provided by user via `UNORDERED_MAP_NAME_PUBLIC_PREFIX` macro parameter. **All other types and functions have this prefix**.

**UNORDERED_MAP_KeyValuePair** - Element stored in the map. Used in `UNORDERED_MAP_emplace` function.

**UNORDERED_MAP_ConstIterator** - Struct used to iterate over a umap. Dereference function returns a `const` pointer to key-value element.

**UNORDERED_MAP_Iterator** - Struct used to iterate over a umap. Dereference function returns a pointer to key-value element.

<!-- ================================================================================================================== -->
<!-- END Types -->
<!-- ================================================================================================================== -->
---

## Unordered Map Functions

<details>
<summary><b>Core Operations</b></summary>

##### UNORDERED_MAP_create
- `@brief` Creates a umap struct and initializes it.
- `@return` A new umap instance.

##### UNORDERED_MAP_destroy
- `@brief` Destroys a umap and releases allocated memory.
- `@param` `target` Pointer to the umap.

##### UNORDERED_MAP_copy
- `@brief` Copies contents of one umap to another.
- `@param` `dest` Destination umap pointer.
- `@param` `source` Source umap pointer.

##### UNORDERED_MAP_move
- `@brief` Moves contents from one umap to another. Valid operations after move: `UNORDERED_MAP_copy` (as dest), `UNORDERED_MAP_destroy`, `UNORDERED_MAP_equals`
- `@param` `dest` Destination umap pointer.
- `@param` `source` Source umap pointer.

##### UNORDERED_MAP_equals
- `@brief` Checks whether two vectors are equal by comparing each element. No need to have the same hashtable to be equal.
- `@param` `left` Left-hand side pointer to a umap.
- `@param` `right` Right-hand side pointer to a umap.
- `@return` `true` if equal, `false` otherwise.

</details>
<!-- ================================================================================================================== -->
<!-- END Core Operations -->
<!-- ================================================================================================================== -->

<details>
<summary><b>Lookup</b></summary>

##### UNORDERED_MAP_element_at
- `@brief` Returns a pointer to the element at index.
- `@param` `target` Pointer to umap.
- `@param` `key` Pointer to key object.
- `@return` Pointer to the element at key or `NULL` if not found.

##### UNORDERED_MAP_element_at_const
- `@brief` Returns a pointer to the element at index.
- `@param` `target` Pointer to umap.
- `@param` `key` Pointer to key object.
- `@return` Pointer to the element at key or `NULL` if not found.

##### UNORDERED_MAP_contains
- `@brief` Checks if umap has an element with given key.
- `@param` `target` Pointer to umap.
- `@param` `key` Pointer to key object.
- `@return` `true` if found, `false` otherwise.

##### UNORDERED_MAP_find
- `@brief` Returns an iterator to the element at key. If not found, `end` iterator is returned.
- `@param` `target` Pointer to umap.
- `@param` `key` Pointer to key object.
- `@return` New instance of `UNORDERED_MAP_Iterator`.

##### UNORDERED_MAP_find_const
- `@brief` Returns an iterator to the element at key. If not found, `end` iterator is returned.
- `@param` `target` Pointer to umap.
- `@param` `key` Pointer to key object.
- `@return` New instance of `UNORDERED_MAP_ConstIterator`.

</details>
<!-- ================================================================================================================== -->
<!-- END Lookup -->
<!-- ================================================================================================================== -->

<details>
<summary><b>Capacity</b></summary>

##### UNORDERED_MAP_size
- `@brief` Returns the number of elements in the umap.
- `@param` `target` Pointer to umap.
- `@return` Number of elements.

##### UNORDERED_MAP_empty
- `@brief` Checks if the umap is empty.
- `@param` `target` Pointer to umap.
- `@return` `true` if empty, `false` otherwise.

</details>
<!-- ================================================================================================================== -->
<!-- END Capacity -->
<!-- ================================================================================================================== -->

<details>
<summary><b>Bucket Interface</b></summary>

##### UNORDERED_MAP_bucket_count
- `@brief` Returns the number of buckets in the umap.
- `@param` `target` Pointer to umap.
- `@return` Number of buckets.

##### UNORDERED_MAP_bucket_size
- `@brief` Returns the number of elements in bucket at index in the umap.
- `@param` `target` Pointer to umap.
- `@param` `index` Index of bucket.
- `@return` Number of elements in bucket.

##### UNORDERED_MAP_bucket
- `@brief` Returns the index of bucket with key in the umap.
- `@param` `target` Pointer to umap.
- `@param` `key` Pointer to key object.
- `@return` Index of bucket for key.

</details>
<!-- ================================================================================================================== -->
<!-- END Bucket Interface -->
<!-- ================================================================================================================== -->

<details>
<summary><b>Hash Policy</b></summary>

##### UNORDERED_MAP_load_factor
- `@brief` Returns the average number of elements per bucket, that is, size divided by bucket_count in umap.
- `@param` `target` Pointer to umap.
- `@return` Average number of elements per bucket.

##### UNORDERED_MAP_max_load_factor
- `@brief` Returns the maximum load factor admitted before rehasing.
- `@param` `target` Pointer to umap.
- `@return` Maximum load factor.

##### UNORDERED_MAP_rehash
- `@brief` Changes the number of buckets to a value `n` that is not less than `nobuckets` and satisfies `n >= size / max_load_factor`, then rehashes the container, i.e. puts the elements into appropriate buckets considering that total number of buckets has changed.
- `@param` `target` Pointer to umap.
- `@param` `nobuckets` Lower bound for the new number of buckets

</details>
<!-- ================================================================================================================== -->
<!-- END Hash Policy -->
<!-- ================================================================================================================== -->

<details>
<summary><b>Modifiers</b></summary>

##### UNORDERED_MAP_clear
- `@brief` Clears the umap contents but retains bucket_count.
- `@param` `target` Pointer to the umap.

##### UNORDERED_MAP_emplace
- `@brief` Adds an element to the umap and returns an iterator to it. If key already exists, return an iterator to existing element.
- `@param` `target` Pointer to umap.
- `@param` `item` Pointer to object to emplace.
- `@return` New instance of `UNORDERED_MAP_Iterator`.

##### UNORDERED_MAP_emplace_key_map
- `@brief` Adds an element to the umap and returns an iterator to it. If key already exists, return an iterator to existing element.
- `@param` `target` Pointer to umap.
- `@param` `key` Pointer to key object.
- `@param` `item` Pointer to mapped object.
- `@return` New instance of `UNORDERED_MAP_Iterator`.

##### UNORDERED_MAP_erase
- `@brief` Removes the element from the umap with given key and return an iterator to next element (`TODO`: implement). If not found, return `end` iterator.
- `@param` `target` Pointer to umap.
- `@param` `key` Pointer to key object.
- `@return` New instance of `UNORDERED_MAP_Iterator`.

##### UNORDERED_MAP_erase_iterator
- `@brief` Removes the element from the umap at iterator and return an iterator to next element (`TODO`: implement).
- `@param` `target` Pointer to umap.
- `@param` `where` Pointer to iterator object.
- `@return` New instance of `UNORDERED_MAP_Iterator`.

##### UNORDERED_MAP_erase_iterator_const
- `@brief` Removes the element from the umap at iterator and return an iterator to next element (`TODO`: implement).
- `@param` `target` Pointer to umap.
- `@param` `where` Pointer to iterator object.
- `@return` New instance of `UNORDERED_MAP_Iterator`.

</details>
<!-- ================================================================================================================== -->
<!-- END Modifiers -->
<!-- ================================================================================================================== -->

<details>
<summary><b>Iterators</b></summary>

##### UNORDERED_MAP_begin_const
- `@brief` Returns an iterator to the first element in umap.
- `@param` `target` Pointer to umap.
- `@return` A new instance of `UNORDERED_MAP_ConstIterator`.

##### UNORDERED_MAP_begin
- `@brief` Returns an iterator to the first element in umap.
- `@param` `target` Pointer to umap.
- `@return` A new instance of `UNORDERED_MAP_Iterator`.

##### UNORDERED_MAP_end_const
- `@brief` Returns an iterator past the last element in umap.
- `@param` `target` Pointer to umap.
- `@return` A new instance of `UNORDERED_MAP_ConstIterator`.

##### UNORDERED_MAP_end
- `@brief` Returns an iterator past the last element in umap.
- `@param` `target` Pointer to umap.
- `@return` A new instance of `UNORDERED_MAP_Iterator`.

</details>
<!-- ================================================================================================================== -->
<!-- END Iterators -->
<!-- ================================================================================================================== -->

<!-- ================================================================================================================== -->
<!-- END Unordered Map Functions -->
<!-- ================================================================================================================== -->
---

## ConstIterator and Iterator Functions

<details>
<summary><b>Core Operations</b></summary>

##### UNORDERED_MAP_ConstIterator_create / UNORDERED_MAP_Iterator_create
- `@brief` Creates an iterator struct
- `@return` A new iterator instance.

##### UNORDERED_MAP_ConstIterator_destroy / UNORDERED_MAP_Iterator_destroy
- `@brief` Destroys an iterator.
- `@param` `target` Pointer to the iterator.

##### UNORDERED_MAP_ConstIterator_copy / UNORDERED_MAP_Iterator_copy
- `@brief` Copies contents of one iterator to another.
- `@param` `dest` Destination iterator pointer.
- `@param` `source` Source iterator pointer.

##### UNORDERED_MAP_ConstIterator_move / UNORDERED_MAP_Iterator_move
- `@brief` Moves contents from one iterator to another.
- `@param` `dest` Destination iterator pointer.
- `@param` `source` Source iterator pointer.

##### UNORDERED_MAP_ConstIterator_equals / UNORDERED_MAP_Iterator_equals
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

##### UNORDERED_MAP_ConstIterator_dereference / UNORDERED_MAP_Iterator_dereference
- `@brief` Return a pointer to current element.
- `@param` `target` Pointer to the iterator.
- `@return` Pointer to element.

</details>
<!-- ================================================================================================================== -->
<!-- END Element Access -->
<!-- ================================================================================================================== -->

<details>
<summary><b>Iteration</b></summary>

##### UNORDERED_MAP_ConstIterator_pre_increment / UNORDERED_MAP_Iterator_pre_increment
- `@brief` Increment by 1.
- `@param` `target` Pointer to the iterator.

##### UNORDERED_MAP_ConstIterator_post_increment / UNORDERED_MAP_Iterator_post_increment
- `@brief` Increment by 1 and return non-incremented iterator.
- `@param` `target` Pointer to the iterator.
- `@return` Non-incremented iterator.

##### UNORDERED_MAP_ConstIterator_pre_decrement / UNORDERED_MAP_Iterator_pre_decrement
- `@brief` Decrement by 1.
- `@param` `target` Pointer to the iterator.

##### UNORDERED_MAP_ConstIterator_post_decrement / UNORDERED_MAP_Iterator_post_decrement
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
#include "custom/c_unordered_map.h"

DEFINE_DEFAULT_TYPE_PUBLIC_MEMBERS(unsigned int, myuint_t)
DEFINE_DEFAULT_TYPE_PUBLIC_MEMBERS(int, myint_t)
DEFINE_GENERIC_UNORDERED_MAP(UMap, myuint_t, myint_t)

int main()
{
    UMap map = UMap_create();

    myuint_t key = 1;
    myint_t val = 1;
    (void)UMap_emplace_key_map(&map, &key, &val);

    key = 2;
    val = 2;
    (void)UMap_emplace_key_map(&map, &key, &val);

    key = 3;
    val = 3;
    (void)UMap_emplace_key_map(&map, &key, &val);

    C_FOR_EACH(UMap, UMap_KeyValuePair, map, pair)
        printf("Key: %d, Val: %d\n", pair->first, pair->second);

    UMap_destroy(&map);

    return 0;
}

// Prints:
// Key: 1, Value: 1
// Key: 2, Value: 2
// Key: 2, Value: 3

```

<!-- ================================================================================================================== -->
<!-- END Usage -->
<!-- ================================================================================================================== -->
---