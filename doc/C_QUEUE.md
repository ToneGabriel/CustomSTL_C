# C_QUEUE


## Macros

**DEFINE_GENERIC_QUEUE**
- `@brief` Define a generic queue for a given type with all required dependencies.
- `@param` `QUEUE_NAME_PUBLIC_PREFIX`   The public name prefix for generated queue. (e.g., `MyQueue` -> `MyQueue_create`, etc.).
- `@param` `TYPE`                       Type stored in the queue.

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

**QUEUE** - Queue data struct. Name provided by user via `QUEUE_NAME_PUBLIC_PREFIX` macro parameter. **All other types and functions have this prefix**.

**Notes**
- No iterators provided.

<!-- ================================================================================================================== -->
<!-- END Types -->
<!-- ================================================================================================================== -->
---

## Queue Functions

<details>
<summary><b>Core Operations</b></summary>

##### QUEUE_create
- `@brief` Creates new queue. Initialize internal list.
- `@return` A new queue instance.

##### QUEUE_destroy
- `@brief` Destroys the queue and its internal data.
- `@param` `target` Pointer to the queue.

##### QUEUE_copy
- `@brief` Copies contents of one queue to another.
- `@param` `dest` Destination queue pointer.
- `@param` `source` Source queue pointer.

##### QUEUE_move
- `@brief` Moves contents from one queue to another. Valid operations after move: `QUEUE_copy` (as dest), `QUEUE_destroy`, `QUEUE_equals`
- `@param` `dest` Destination queue pointer.
- `@param` `source` Source queue pointer.

##### QUEUE_equals
- `@brief` Checks whether two queues are equal by comparing each element.
- `@param` `left` Left-hand side pointer to a queue.
- `@param` `right` Right-hand side pointer to a queue.
- `@return` `true` if equal, `false` otherwise.

</details>
<!-- ================================================================================================================== -->
<!-- END Core Operations -->
<!-- ================================================================================================================== -->

<details>
<summary><b>Element Access</b></summary>

##### QUEUE_peek
- `@brief` Returns a pointer to the top element of the queue.
- `@param` `target` Pointer to queue.
- `@return` Pointer to the first element.

##### QUEUE_peek_const
- `@brief` Returns a pointer to the top element of the queue.
- `@param` `target` Pointer to queue.
- `@return` Pointer to the first element.

</details>
<!-- ================================================================================================================== -->
<!-- END Element Access -->
<!-- ================================================================================================================== -->

<details>
<summary><b>Capacity</b></summary>

##### QUEUE_size
- `@brief` Returns the number of elements in the queue.
- `@param` `target` Pointer to queue.
- `@return` Number of elements.

##### QUEUE_empty
- `@brief` Checks if the queue is empty.
- `@param` `target` Pointer to queue.
- `@return` `true` if empty, `false` otherwise.

</details>
<!-- ================================================================================================================== -->
<!-- END Capacity -->
<!-- ================================================================================================================== -->

<details>
<summary><b>Modifiers</b></summary>

##### QUEUE_clear
- `@brief` Clears all elements from the queue without destroying it.
- `@param` `target` Pointer to the queue.

##### QUEUE_insert
- `@brief` Inserts a new default element into the queue.
- `@param` `target` Pointer to queue.

##### QUEUE_insert_copy
- `@brief` Inserts a new element into the queue.
- `@param` `target` Pointer to queue.
- `@param` `item` Pointer to object to copy push.

##### QUEUE_insert_move
- `@brief` Inserts a new element into the queue.
- `@param` `target` Pointer to queue.
- `@param` `item` Pointer to object to move push.

##### QUEUE_pop
- `@brief` Removes the top element from the queue.
- `@param` `target` Pointer to queue.

</details>
<!-- ================================================================================================================== -->
<!-- END Modifiers -->
<!-- ================================================================================================================== -->

<!-- ================================================================================================================== -->
<!-- END Queue Functions -->
<!-- ================================================================================================================== -->
---

## Usage

```C
#include "custom/c_queue.h"

DEFINE_DEFAULT_TYPE_PUBLIC_MEMBERS(unsigned int, myuint_t)      // myuint_t is the typedef alias for desired type (use it in container definition)
DEFINE_GENERIC_QUEUE(QueueUINT, myuint_t)

int main()
{
    QueueUINT myQueueUINTInstance = QueueUINT_create();

    myuint_t val;

    val = 1;
    QueueUINT_insert_copy(&myQueueUINTInstance, &val);

    val = 2;
    QueueUINT_insert_copy(&myQueueUINTInstance, &val);

    val = 3;
    QueueUINT_insert_copy(&myQueueUINTInstance, &val);

    while (!QueueUINT_empty(&myQueueUINTInstance))
    {
      printf("Value: %d\n", *QueueUINT_peek(&myQueueUINTInstance));
      QueueUINT_pop(&myQueueUINTInstance);
    }

    QueueUINT_destroy(&myQueueUINTInstance);

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