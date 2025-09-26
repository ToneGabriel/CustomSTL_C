#include "unity.h"
#include "custom/c_unordered_set.h"


// Setup ==========================


DEFINE_DEFAULT_TYPE_PUBLIC_MEMBERS(unsigned int, myuint_t)
DEFINE_GENERIC_UNORDERED_SET(USet, myuint_t)


static USet g_customUSetInstance;


void setUp()
{
    g_customUSetInstance = USet_create();
}

void tearDown()
{
    USet_destroy(&g_customUSetInstance);
}


// Tests ==========================


void test_default_create()
{
    TEST_ASSERT_TRUE_MESSAGE(USet_empty(&g_customUSetInstance), "USet should be empty");
    TEST_ASSERT_EQUAL_MESSAGE(0, USet_size(&g_customUSetInstance), "Initial size should be 0");
}

void test_copy()
{
    // USet_push_back(&g_customUSetInstance);
    // USet_push_back(&g_customUSetInstance);
    // USet_push_back(&g_customUSetInstance);

    USet other = USet_create();
    TEST_ASSERT_FALSE_MESSAGE(USet_equals(&other, &g_customUSetInstance), "Other uset should NOT be equal to original");

    USet_copy(&other, &g_customUSetInstance);
    TEST_ASSERT_TRUE_MESSAGE(USet_equals(&other, &g_customUSetInstance), "Other uset should be equal to original");

    USet_destroy(&other);
}

void test_move()
{
    // USet_push_back(&g_customUSetInstance);
    // USet_push_back(&g_customUSetInstance);
    // USet_push_back(&g_customUSetInstance);

    USet original_copy = USet_create();
    USet_copy(&original_copy, &g_customUSetInstance);

    USet other = USet_create();
    TEST_ASSERT_FALSE_MESSAGE(USet_equals(&other, &g_customUSetInstance), "Other uset should NOT be equal to original");

    USet_move(&other, &g_customUSetInstance);
    TEST_ASSERT_FALSE_MESSAGE(USet_equals(&other, &g_customUSetInstance), "Other uset should STILL NOT be equal to original");
    TEST_ASSERT_TRUE_MESSAGE(USet_equals(&other, &original_copy), "Other uset should be equal to original copy");

    USet_destroy(&other);
    USet_destroy(&original_copy);
}


// RUN ==========================


int main()
{
    UNITY_BEGIN();
    
    RUN_TEST(test_default_create);
    RUN_TEST(test_copy);
    RUN_TEST(test_move);

    return UNITY_END();
}
