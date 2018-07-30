#include <gtest/gtest.h>
#include "neonlab.h"

struct neonlab_test : ::testing::Test
{
};

TEST_F(neonlab_test, hello_world)
{
    EXPECT_STREQ("hello world", hello());
}

