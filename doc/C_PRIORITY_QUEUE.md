# C_PRIORITY_QUEUE


## Macros

**DEFINE_GENERIC_PRIORITY_QUEUE**
- `@brief` Define a generic priority queue for a given type with all required dependencies. This macro generates a full implementation of a min/max heap-based priority queue using a vector as the backing store.
- `@param` `PRIORITY_QUEUE_NAME_PUBLIC_PREFIX`  The public name prefix for generated pq. (e.g., `MyPQ` -> `MyPQ_create`, etc.).
- `@param` `TYPE`                               Type stored in the pq.
- `@param` `TYPE_REF_COMPARE_FUNC`              Comparison function for priority (signature: `bool comp(const TYPE *, const TYPE *)`)

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

**PRIORITY_QUEUE** - PQ data struct. Name provided by user via `PRIORITY_QUEUE_NAME_PUBLIC_PREFIX` macro parameter. **All other types and functions have this prefix**.

**Notes**
- No iterators provided.

<!-- ================================================================================================================== -->
<!-- END Types -->
<!-- ================================================================================================================== -->
---

## Priority Queue Functions

<details>
<summary><b>Core Operations</b></summary>

##### PRIORITY_QUEUE_create
- `@brief` Creates new pq. Initialize internal vector.
- `@return` A new pq instance.

##### PRIORITY_QUEUE_destroy
- `@brief` Destroys the pq and its internal data.
- `@param` `target` Pointer to the pq.

##### PRIORITY_QUEUE_copy
- `@brief` Copies contents of one pq to another.
- `@param` `dest` Destination pq pointer.
- `@param` `source` Source pq pointer.

##### PRIORITY_QUEUE_move
- `@brief` Moves contents from one pq to another. Valid operations after move: `PRIORITY_QUEUE_copy` (as dest), `PRIORITY_QUEUE_destroy`, `PRIORITY_QUEUE_equals`
- `@param` `dest` Destination pq pointer.
- `@param` `source` Source pq pointer.

##### PRIORITY_QUEUE_equals
- `@brief` Checks whether two pqs are equal by comparing each element.
- `@param` `left` Left-hand side pointer to a pq.
- `@param` `right` Right-hand side pointer to a pq.
- `@return` `true` if equal, `false` otherwise.

</details>
<!-- ================================================================================================================== -->
<!-- END Core Operations -->
<!-- ================================================================================================================== -->

<details>
<summary><b>Element Access</b></summary>

##### PRIORITY_QUEUE_peek
- `@brief` Returns a pointer to the top element (highest priority) of the queue.
- `@param` `target` Pointer to pq.
- `@return` Pointer to the first element.

##### PRIORITY_QUEUE_peek_const
- `@brief` Returns a pointer to the top element (highest priority) of the queue.
- `@param` `target` Pointer to pq.
- `@return` Pointer to the first element.

</details>
<!-- ================================================================================================================== -->
<!-- END Element Access -->
<!-- ================================================================================================================== -->

<details>
<summary><b>Capacity</b></summary>

##### PRIORITY_QUEUE_size
- `@brief` Returns the number of elements in the pq.
- `@param` `target` Pointer to pq.
- `@return` Number of elements.

##### PRIORITY_QUEUE_empty
- `@brief` Checks if the pq is empty.
- `@param` `target` Pointer to pq.
- `@return` `true` if empty, `false` otherwise.

</details>
<!-- ================================================================================================================== -->
<!-- END Capacity -->
<!-- ================================================================================================================== -->

<details>
<summary><b>Modifiers</b></summary>

##### PRIORITY_QUEUE_clear
- `@brief` Clears all elements from the pq without destroying it.
- `@param` `target` Pointer to the pq.

##### PRIORITY_QUEUE_insert
- `@brief` Inserts a new default element into the pq. Performs a `heapify-up` after insertion to maintain heap order.
- `@param` `target` Pointer to pq.

##### PRIORITY_QUEUE_insert_copy
- `@brief` Inserts a new element into the pq. Performs a `heapify-up` after insertion to maintain heap order.
- `@param` `target` Pointer to pq.
- `@param` `item` Pointer to object to copy push.

##### PRIORITY_QUEUE_insert_move
- `@brief` Inserts a new element into the pq. Performs a `heapify-up` after insertion to maintain heap order.
- `@param` `target` Pointer to pq.
- `@param` `item` Pointer to object to move push.

##### PRIORITY_QUEUE_pop
- `@brief` Removes the top element (highest priority) from the pq. Performs a `heapify-down` after removal to maintain heap order.
- `@param` `target` Pointer to pq.

</details>
<!-- ================================================================================================================== -->
<!-- END Modifiers -->
<!-- ================================================================================================================== -->

<!-- ================================================================================================================== -->
<!-- END Priority Queue Functions -->
<!-- ================================================================================================================== -->
---

## Usage

```C
#include "custom/c_priority_queue.h"

DEFINE_DEFAULT_TYPE_PUBLIC_MEMBERS(unsigned int, myuint_t)      // myuint_t is the typedef alias for desired type (use it in container definition)
DEFINE_GENERIC_PRIORITY_QUEUE(UIntPQ, myuint_t, myuint_t_less)  // myuint_t_less was generated by previous macro

int main()
{
    UIntPQ myUIntPQInstance = UIntPQ_create();

    myuint_t val;

    val = 3;
    UIntPQ_insert_copy(&myUIntPQInstance, &val);

    val = 1;
    UIntPQ_insert_copy(&myUIntPQInstance, &val);

    val = 2;
    UIntPQ_insert_copy(&myUIntPQInstance, &val);

    while (!UIntPQ_empty(&myUIntPQInstance))
    {
      printf("Value: %d\n", *UIntPQ_peek(&myUIntPQInstance));
      UIntPQ_pop(&myUIntPQInstance);
    }

    UIntPQ_destroy(&myUIntPQInstance);

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