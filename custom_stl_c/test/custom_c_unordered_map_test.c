#include "unity.h"
#include "custom/c_unordered_map.h"


// Setup ==========================


DEFINE_DEFAULT_TYPE_PUBLIC_MEMBERS(unsigned int, myuint_t)
DEFINE_DEFAULT_TYPE_PUBLIC_MEMBERS(int, myint_t)
DEFINE_GENERIC_UNORDERED_MAP(UMap, myuint_t, myint_t)


static UMap g_customUMapInstance;


void setUp()
{
    g_customUMapInstance = UMap_create();
}

void tearDown()
{
    UMap_destroy(&g_customUMapInstance);
}


// Tests ==========================


void test_default_create()
{
    TEST_ASSERT_TRUE_MESSAGE(UMap_empty(&g_customUMapInstance), "UMap should be empty");
    TEST_ASSERT_EQUAL_MESSAGE(0, UMap_size(&g_customUMapInstance), "Initial size should be 0");
}

void test_copy()
{
    // UMap_push_back(&g_customUMapInstance);
    // UMap_push_back(&g_customUMapInstance);
    // UMap_push_back(&g_customUMapInstance);

    UMap other = UMap_create();
    TEST_ASSERT_FALSE_MESSAGE(UMap_equals(&other, &g_customUMapInstance), "Other umap should NOT be equal to original");

    UMap_copy(&other, &g_customUMapInstance);
    TEST_ASSERT_TRUE_MESSAGE(UMap_equals(&other, &g_customUMapInstance), "Other umap should be equal to original");

    UMap_destroy(&other);
}

void test_move()
{
    // UMap_push_back(&g_customUMapInstance);
    // UMap_push_back(&g_customUMapInstance);
    // UMap_push_back(&g_customUMapInstance);

    UMap original_copy = UMap_create();
    UMap_copy(&original_copy, &g_customUMapInstance);

    UMap other = UMap_create();
    TEST_ASSERT_FALSE_MESSAGE(UMap_equals(&other, &g_customUMapInstance), "Other umap should NOT be equal to original");

    UMap_move(&other, &g_customUMapInstance);
    TEST_ASSERT_FALSE_MESSAGE(UMap_equals(&other, &g_customUMapInstance), "Other umap should STILL NOT be equal to original");
    TEST_ASSERT_TRUE_MESSAGE(UMap_equals(&other, &original_copy), "Other umap should be equal to original copy");

    UMap_destroy(&other);
    UMap_destroy(&original_copy);
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
