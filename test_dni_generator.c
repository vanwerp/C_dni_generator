#include <assert.h>
#include <stdio.h>
#include <string.h>

/* Include the source file, renaming its main to avoid conflict */
#define main dni_main
#include "dni_generator.c"
#undef main

static void test_get_letter_all_remainders(void)
{
    const char expected[] = "TRWAGMYFPDXBNJZSQVHLCKE";

    for (int i = 0; i < 23; i++)
    {
        char result = get_letter(i);
        assert(result == expected[i]);
    }
    printf("PASS: test_get_letter_all_remainders\n");
}

static void test_get_letter_large_numbers(void)
{
    assert(get_letter(23) == 'T');  /* 23 % 23 == 0 */
    assert(get_letter(46) == 'T');  /* 46 % 23 == 0 */
    assert(get_letter(24) == 'R');  /* 24 % 23 == 1 */
    assert(get_letter(12345678) == 'Z');  /* 12345678 % 23 == 14 -> Z */
    printf("PASS: test_get_letter_large_numbers\n");
}

static void test_get_letter_known_dnis(void)
{
    /* 00000000 % 23 == 0 -> T */
    assert(get_letter(0) == 'T');
    /* 12345678 % 23 == 14 -> Z */
    assert(get_letter(12345678) == 'Z');
    /* 99999999 % 23 == 1 -> R */
    assert(get_letter(99999999) == 'R');
    printf("PASS: test_get_letter_known_dnis\n");
}

int main(void)
{
    test_get_letter_all_remainders();
    test_get_letter_large_numbers();
    test_get_letter_known_dnis();

    printf("All tests passed!\n");
    return 0;
}
