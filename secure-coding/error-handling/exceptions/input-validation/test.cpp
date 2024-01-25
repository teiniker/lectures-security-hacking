#include <CppUTest/TestHarness.h>
#include <CppUTest/CommandLineTestRunner.h>

#include <iostream>
#include "user.h"

using namespace std;

User* user = NULL;

TEST_GROUP(UserTestGroup)
{
    void setup()
    {
        user = new User(7, "homer", "c3R1ZGVudA");
    }

    void teardown()
    {
        delete user;
    }
};


TEST(UserTestGroup, ConstructorTest)
{
    // Verify
    CHECK_EQUAL(7, user->id());
    CHECK_EQUAL("homer", user->username());
    CHECK_EQUAL("c3R1ZGVudA", user->password());    
}


TEST(UserTestGroup, InvalidIdTest)
{
    // Verify
    try
    {
        User(-1, "homer", "c3R1ZGVudA");
        FAIL("Expected exception not thrown");
    }
    catch(const std::invalid_argument& e)
    {
        printf("Exception: %s\n", e.what());
    }
}

TEST(UserTestGroup, InvalidUsernameTooShortTest)
{
    // Verify
    string username = "1234567890123456789012345678901234567890X";
    CHECK_THROWS(std::invalid_argument, User(1, username, "c3R1ZGVudA"));
}

TEST(UserTestGroup, InvalidPasswordTest)
{
    // Verify
    CHECK_THROWS(std::invalid_argument, User(1, "homer", "c3R1ZGVud"));
}


int main(int ac, char** av)
{
    return CommandLineTestRunner::RunAllTests(ac, av);
}
