#include <gtest/gtest.h>

#include "sequence.h"

namespace {

TEST(SequenceTest, SuccessfulInsert) 
{
	Item item = 'c';
	Position position = 1;
	Sequence sequence = { .position = position, .item = item };

	ReturnCode returnCode = insertItemIntoSequenceAtPosition(item, &sequence, position);
	EXPECT_EQ(returnCode, 0);
}

} // end namespace
