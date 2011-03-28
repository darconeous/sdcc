/* Check basic behaviour of designated initializers
 * Written by Robert Quattlebaum <darco@deepdarc.com>
 * PUBLIC DOMAIN
 */
#include <testfwk.h>

#define HAS_DESIGNATED_INITIALIZERS ((GCC_VERSION >= 2007) || (__STDC_VERSION__ >= 199901L) || SDCC)

#define SHOULD_TEST_UNIONS_TOO 1

#if !HAS_DESIGNATED_INITIALIZERS
#warning Skipping designated initializer tests due to missing compiler support.
#endif

#if HAS_DESIGNATED_INITIALIZERS
struct str1
{
	char a;
	int b;
	char x;
	long c;
};

struct str1 sl1 = {
	.a = 1,
	.b = 2,
	.c = 3,
	.x = 4,
};

struct str1 sl2 = {
	.a = 'A',
	.x = 'x',
	.c = 0xDEADBEEF,
	.b = 0xFACE,
};

struct str1 sl3 = {
	.a = 'a',
	.c = 0x31337,
	.b = 0x1337,
};

#if SHOULD_TEST_UNIONS_TOO
union unn1
{
	char a;
	short b;
	long c;
};

union unn1 ul1 = {
	.b = 0x1337,
};
#endif

#endif // #if HAS_DESIGNATED_INITIALIZERS

static void
testDesignatedInitializers1(void) {
#if HAS_DESIGNATED_INITIALIZERS
	ASSERT(sl1.a == 1);
	ASSERT(sl1.b == 2);
	ASSERT(sl1.c == 3);
	ASSERT(sl1.x == 4);

	ASSERT(sl2.a == 'A');
	ASSERT(sl2.b == 0xFACE);
	ASSERT(sl2.c == 0xDEADBEEF);
	ASSERT(sl2.x == 'x');

	ASSERT(sl3.a == 'a');
	ASSERT(sl3.b == 0x1337);
	ASSERT(sl3.c == 0x31337);
	ASSERT(sl3.x == 0);
	
#if SHOULD_TEST_UNIONS_TOO
	ASSERT(ul1.b == 0x1337);
#endif
#endif // #if HAS_DESIGNATED_INITIALIZERS
}

static void
testDesignatedInitializers2(void) {
#if HAS_DESIGNATED_INITIALIZERS
	struct str1 sl4 = {
		.a = 1,
		.b = 2,
		.c = 3,
		.x = 4,
	};

	struct str1 sl5 = {
		.a = 'A',
		.x = 'x',
		.c = 0xDEADBEEF,
		.b = 0xFACE,
	};

	struct str1 sl6 = {
		.a = 'a',
		.c = 0x31337,
		.b = 0x1337,
	};

#if SHOULD_TEST_UNIONS_TOO
	union unn1 ul2 = { .b = 0x1337, };
	ASSERT(ul2.b == 0x1337);	
#endif

	ASSERT(sl4.a == 1);
	ASSERT(sl4.b == 2);
	ASSERT(sl4.c == 3);
	ASSERT(sl4.x == 4);

	ASSERT(sl5.a == 'A');
	ASSERT(sl5.b == 0xFACE);
	ASSERT(sl5.c == 0xDEADBEEF);
	ASSERT(sl5.x == 'x');

	ASSERT(sl6.a == 'a');
	ASSERT(sl6.b == 0x1337);
	ASSERT(sl6.c == 0x31337);
	ASSERT(sl6.x == 0);
#endif // #if HAS_DESIGNATED_INITIALIZERS
}
