# C_STACK


## Macros

**DEFINE_GENERIC_STACK**
- `@brief` Define a generic stack for a given type with all required dependencies.
- `@param` `STACK_NAME_PUBLIC_PREFIX`   The public name prefix for generated stack. (e.g., `MyStack` -> `MyStack_create`, etc.).
- `@param` `TYPE`                       Type stored in the stack.

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

**STACK** - Stack data struct. Name provided by user via `STACK_NAME_PUBLIC_PREFIX` macro parameter. **All other types and functions have this prefix**.

**Notes**
- No iterators provided.

<!-- ================================================================================================================== -->
<!-- END Types -->
<!-- ================================================================================================================== -->
---

## Stack Functions

<details>
<summary><b>Core Operations</b></summary>

##### STACK_create
- `@brief` Creates new stack. Initialize internal vector.
- `@return` A new stack instance.

##### STACK_destroy
- `@brief` Destroys the stack and its internal data.
- `@param` `target` Pointer to the stack.

##### STACK_copy
- `@brief` Copies contents of one stack to another.
- `@param` `dest` Destination stack pointer.
- `@param` `source` Source stack pointer.

##### STACK_move
- `@brief` Moves contents from one stack to another. Valid operations after move: `STACK_copy` (as dest), `STACK_destroy`, `STACK_equals`
- `@param` `dest` Destination stack pointer.
- `@param` `source` Source stack pointer.

##### STACK_equals
- `@brief` Checks whether two stacks are equal by comparing each element.
- `@param` `left` Left-hand side pointer to a stack.
- `@param` `right` Right-hand side pointer to a stack.
- `@return` `true` if equal, `false` otherwise.

</details>
<!-- ================================================================================================================== -->
<!-- END Core Operations -->
<!-- ================================================================================================================== -->

<details>
<summary><b>Element Access</b></summary>

##### STACK_peek
- `@brief` Returns a pointer to the top (last inserted) element of the stack.
- `@param` `target` Pointer to stack.
- `@return` Pointer to the first element.

##### STACK_peek_const
- `@brief` Returns a pointer to the top (last inserted) element of the stack.
- `@param` `target` Pointer to stack.
- `@return` Pointer to the first element.

</details>
<!-- ================================================================================================================== -->
<!-- END Element Access -->
<!-- ================================================================================================================== -->

<details>
<summary><b>Capacity</b></summary>

##### STACK_size
- `@brief` Returns the number of elements in the stack.
- `@param` `target` Pointer to stack.
- `@return` Number of elements.

##### STACK_empty
- `@brief` Checks if the stack is empty.
- `@param` `target` Pointer to stack.
- `@return` `true` if empty, `false` otherwise.

</details>
<!-- ================================================================================================================== -->
<!-- END Capacity -->
<!-- ================================================================================================================== -->

<details>
<summary><b>Modifiers</b></summary>

##### STACK_clear
- `@brief` Clears all elements from the stack without destroying it.
- `@param` `target` Pointer to the stack.

##### STACK_insert
- `@brief` Inserts a new default element into the stack.
- `@param` `target` Pointer to stack.

##### STACK_insert_copy
- `@brief` Inserts a new element into the stack.
- `@param` `target` Pointer to stack.
- `@param` `item` Pointer to object to copy push.

##### STACK_insert_move
- `@brief` Inserts a new element into the stack.
- `@param` `target` Pointer to stack.
- `@param` `item` Pointer to object to move push.

##### STACK_pop
- `@brief` Removes the top (last inserted) element from the stack.
- `@param` `target` Pointer to stack.

</details>
<!-- ================================================================================================================== -->
<!-- END Modifiers -->
<!-- ================================================================================================================== -->

<!-- ================================================================================================================== -->
<!-- END Stack Functions -->
<!-- ================================================================================================================== -->
---

## Usage

```C
#include "custom/c_stack.h"

DEFINE_DEFAULT_TYPE_PUBLIC_MEMBERS(unsigned int, myuint_t)      // myuint_t is the typedef alias for desired type (use it in container definition)
DEFINE_GENERIC_STACK(StackUINT, myuint_t)

int main()
{
    StackUINT myStackUINTInstance = StackUINT_create();

    myuint_t val;

    val = 3;
    StackUINT_insert_copy(&myStackUINTInstance, &val);

    val = 2;
    StackUINT_insert_copy(&myStackUINTInstance, &val);

    val = 1;
    StackUINT_insert_copy(&myStackUINTInstance, &val);

    while (!StackUINT_empty(&myStackUINTInstance))
    {
      printf("Value: %d\n", *StackUINT_peek(&myStackUINTInstance));
      StackUINT_pop(&myStackUINTInstance);
    }

    StackUINT_destroy(&myStackUINTInstance);

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