/* Check basic behaviour of designated initializers
 */
#include <testfwk.h>

struct str1
{
	char a;
	int b;
	char x;
	long c;
};

struct str1 sl1 = {
	.a = 'a',
	.c = 0x31337,
	.b = 0x1337,
};

struct str1 sl2 = {
	.x = 'x',
	.a = 'A',
	.c = 0xDEADBEEF,
	.b = 0xFACE,
};

static void
testDesignatedInitializers1(void)
{
	ASSERT(sl1.a == 'a');
	ASSERT(sl1.b == 0x1337);
	ASSERT(sl1.c == 0x31337);
	ASSERT(sl1.x == 0);

	ASSERT(sl2.a == 'A');
	ASSERT(sl2.b == 0xFACE);
	ASSERT(sl2.c == 0xDEADBEEF);
	ASSERT(sl2.x == 'x');
}

