#include "unity.h"
#include "custom/c_unordered_map.h"


// Setup ==========================


DEFINE_DEFAULT_TYPE_PUBLIC_MEMBERS(unsigned int, myuint_t)
DEFINE_DEFAULT_TYPE_PUBLIC_MEMBERS(int, myint_t)

_DEFINE_GENERIC_HASH_TABLE(
    HashTable,
    myuint_t,
    myint_t
)


void foo()
{
}
