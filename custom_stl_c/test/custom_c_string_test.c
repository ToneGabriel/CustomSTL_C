#include "unity.h"
#include "custom/c_string.h"


// Setup ==========================


DEFINE_STRING()


static String g_customStringInstance;


void setUp()
{
    g_customStringInstance = String_create();
}

void tearDown()
{
    String_destroy(&g_customStringInstance);
}


// Tests ==========================


void test_default_create()
{
    TEST_ASSERT_TRUE_MESSAGE(String_empty(&g_customStringInstance), "Queue should be empty");
    TEST_ASSERT_EQUAL_MESSAGE(0, String_size(&g_customStringInstance), "Initial size should be 0");
}

void test_copy()
{
    String_insert(&g_customStringInstance);
    String_insert(&g_customStringInstance);
    String_insert(&g_customStringInstance);

    String other = String_create();
    TEST_ASSERT_FALSE_MESSAGE(String_equals(&other, &g_customStringInstance), "Other queue should NOT be equal to original");

    String_copy(&other, &g_customStringInstance);
    TEST_ASSERT_TRUE_MESSAGE(String_equals(&other, &g_customStringInstance), "Other queue should be equal to original");

    String_destroy(&other);
}

void test_move()
{
    String_insert(&g_customStringInstance);
    String_insert(&g_customStringInstance);
    String_insert(&g_customStringInstance);

    String original_copy = String_create();
    String_copy(&original_copy, &g_customStringInstance);

    String other = String_create();
    TEST_ASSERT_FALSE_MESSAGE(String_equals(&other, &g_customStringInstance), "Other queue should NOT be equal to original");

    String_move(&other, &g_customStringInstance);
    TEST_ASSERT_FALSE_MESSAGE(String_equals(&other, &g_customStringInstance), "Other queue should STILL NOT be equal to original");
    TEST_ASSERT_TRUE_MESSAGE(String_equals(&other, &original_copy),"Other queue should be equal to original copy");

    String_destroy(&other);
    String_destroy(&original_copy);
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
