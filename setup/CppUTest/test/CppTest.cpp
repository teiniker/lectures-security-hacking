#include <CppUTest/TestHarness.h>
#include <CppUTest/CommandLineTestRunner.h>

#include <cstring>

using namespace std;

char buffer[81];

TEST_GROUP(TestGroup)
{
    void setup()
    {
        memset(buffer, 0x00, sizeof buffer);
    }

    void teardown()
    {
    }    
};


TEST(TestGroup, NoFormatStringTest)
{
    // Exercise
	int len = sprintf(buffer,"Hello");
	
	// Verify
	STRCMP_EQUAL("Hello", buffer);
	CHECK_EQUAL(5, len);
	CHECK_EQUAL('\0', buffer[5]);
}

TEST(TestGroup, StringParameterTest)
{
	// Setup
	const char* str = "Graz"; 
	
	// Exercise
	int len = sprintf(buffer, "Hello %s!", str);
	
	// Verify
	STRCMP_EQUAL("Hello Graz!", buffer);
	CHECK_EQUAL(11, len);

}

TEST(TestGroup, IntegerParameterTest)
{
	// Setup
	int a = 3;
	int b = 7;
	
	// Exercise
	int len = sprintf(buffer, "%d + %d = %d", a, b, a+b);
	
	// Verify
	STRCMP_EQUAL("3 + 7 = 10", buffer);
	CHECK_EQUAL(10, len);

}

TEST(TestGroup, HexParameterTest)
{
	// Setup
	int a = 0xffd2;
	
	// Exercise
	int len = sprintf(buffer, "Hex: %08x", a);
	
	// Verify
	STRCMP_EQUAL("Hex: 0000ffd2", buffer);
	CHECK_EQUAL(13, len);
}

TEST(TestGroup, DoubleParameterTest)
{
	// Setup
	double d = 3.1415;
	
	// Exercise
	int len = sprintf(buffer, "PI = %3.2f", d);
	
	// Verify
	STRCMP_EQUAL("PI = 3.14", buffer);
	CHECK_EQUAL(9, len);
}


TEST(TestGroup, MemoryLeakTest)
{
	// Setup
	int *array = new int[7];
	
	// Note: If you remove the delete statement, the test runner will
	// report a memory leak and marks the test as failed!!
	 
	// Tear down
	delete[] array;
}


int main(int ac, char** av)
{
    return CommandLineTestRunner::RunAllTests(ac, av);
}
