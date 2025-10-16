# C_PAIR


## Macros

**DEFINE_GENERIC_PAIR**
- `@brief` Define a generic pair for given types with all required dependencies.
- `@param` `PAIR_NAME`  The public name prefix for generated pair (e.g., `MyPair` -> `MyPair_create`, etc.).
- `@param` `TYPE_1`     Typedef stored in the pair `first` member;
- `@param` `TYPE_2`     Typedef stored in the pair `second` member.

**Notes**
- For default types and pointers: `TYPE_1` and `TYPE_2` must be created with `DEFINE_DEFAULT_TYPE_PUBLIC_MEMBERS`
- For custom structs: `TYPE_1` and `TYPE_2` must have all default function definitions:
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

**PAIR** - Pair data struct. Name provided by user via `PAIR_NAME` macro parameter. **All other types and functions have this prefix**.

<!-- ================================================================================================================== -->
<!-- END Types -->
<!-- ================================================================================================================== -->
---

## Pair Functions

<details>
<summary><b>Core Operations</b></summary>

##### PAIR_create
- `@brief` Creates a pair struct and initializes the members with default values.
- `@return` A new pair instance.

##### PAIR_destroy
- `@brief` Destroys a pair. Call each member `destroy` function
- `@param` `target` Pointer to the pair.

##### PAIR_copy
- `@brief` Copies contents of one pair to another.
- `@param` `dest` Destination pair pointer.
- `@param` `source` Source pair pointer.

##### PAIR_move
- `@brief` Moves contents from one pair to another. Valid operations after move: `PAIR_copy` (as dest), `PAIR_destroy`, `PAIR_equals`
- `@param` `dest` Destination pair pointer.
- `@param` `source` Source pair pointer.

##### PAIR_equals
- `@brief` Checks whether two pairs are equal by comparing each element.
- `@param` `left` Left-hand side pointer to a pair.
- `@param` `right` Right-hand side pointer to a pair.
- `@return` `true` if equal, `false` otherwise.

</details>
<!-- ================================================================================================================== -->
<!-- END Core Operations -->
<!-- ================================================================================================================== -->

<details>
<summary><b>Element Access</b></summary>

##### first / second
- Pair members `first` and `second` are free to be accessed and modified.

</details>
<!-- ================================================================================================================== -->
<!-- END Element Access -->
<!-- ================================================================================================================== -->

<!-- ================================================================================================================== -->
<!-- END Pair Functions -->
<!-- ================================================================================================================== -->
---

## Usage

```C
#include "custom/c_pair.h"

DEFINE_DEFAULT_TYPE_PUBLIC_MEMBERS(unsigned int, myuint_t)
DEFINE_DEFAULT_TYPE_PUBLIC_MEMBERS(double, mydouble_t)
DEFINE_GENERIC_PAIR(PairUINTAndDOUBLE, myuint_t, mydouble_t)

int main()
{
    PairUINTAndDOUBLE pair = PairUINTAndDOUBLE_create();

    pair.first = 3;
    pair.second = 9.7;

    printf("First: %d, Second: %.2f\n", pair.first, pair.second);

    PairUINTAndDOUBLE_destroy(&pair);

    return 0;
}

// Prints:
// First: 3, Second: 9.70

```

<!-- ================================================================================================================== -->
<!-- END Usage -->
<!-- ================================================================================================================== -->
---