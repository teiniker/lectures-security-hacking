#include <unity.h>

void setUp(void) 
{
    // set stuff up here
}

void tearDown(void) 
{
    // clean stuff up here
}

void test_size_bool(void)
{
    uint8_t size = sizeof(bool);
    TEST_ASSERT_EQUAL(1, size);
}

void test_size_short(void)
{
    uint8_t size = sizeof(short);
    TEST_ASSERT_EQUAL(2, size);
}

void test_size_int(void)
{
    uint8_t size = sizeof(int);
    TEST_ASSERT_EQUAL(4, size);
}

void test_size_long(void)
{
    uint8_t size = sizeof(long);
    TEST_ASSERT_EQUAL(4, size);
}

void test_size_longlong(void)
{
    uint8_t size = sizeof(long long);
    TEST_ASSERT_EQUAL(8, size);
}

void test_size_float(void)
{
    uint8_t size = sizeof(float);
    TEST_ASSERT_EQUAL(4, size);
}

void test_size_double(void)
{
    uint8_t size = sizeof(double);
    TEST_ASSERT_EQUAL(8, size);
}

void test_size_longdouble(void)
{
    uint8_t size = sizeof(long double);
    TEST_ASSERT_EQUAL(12, size);
}

int main(int argc, char **argv) 
{
    UNITY_BEGIN();
    RUN_TEST(test_size_bool);
    RUN_TEST(test_size_short);
    RUN_TEST(test_size_int);
    RUN_TEST(test_size_long);
    RUN_TEST(test_size_longlong);

    RUN_TEST(test_size_float);
    RUN_TEST(test_size_double);
    RUN_TEST(test_size_longdouble);

    UNITY_END();
}
