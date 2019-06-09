#include "common.h"

typedef int ReturnCode;
typedef int Position;
typedef unsigned char Item;

/* This will be changed but for my first testing this is what I'll use */
typedef struct
{
	Position position;
	Item item;
} Sequence;

ReturnCode insertItemIntoSequenceAtPosition(
	Item item,
	Sequence* sequence,
	Position position)
{
	UNUSED_VARIABLE(item);
	UNUSED_VARIABLE(sequence);
	UNUSED_VARIABLE(position);
	return 0;
}
