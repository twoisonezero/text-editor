#include <gtest/gtest.h>

#include "sequence.h"

namespace {

TEST(SequenceTest, Truth) 
{
	EXPECT_EQ(true, true);
}

TEST(SequenceTest, OneEqualsOne) 
{
	EXPECT_EQ(1, 1);
}

TEST(SequenceTest, CheckNegative)
{
	EXPECT_FALSE(false == true);
	EXPECT_FALSE(1 != 1);
}

TEST(SequenceTest, CheckPositive)
{
	EXPECT_TRUE(false == false);
	EXPECT_TRUE(true == true);

	EXPECT_TRUE(1 == 1);
}

} // end namespace
