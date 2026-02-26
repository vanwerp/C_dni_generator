#include <stdio.h>
#include <assert.h>

#define TESTING
#include "dni_generator.c"

static int tests_run = 0;
static int tests_passed = 0;

static void test_get_letter_all_cases(void)
{
    /* Official DNI letter table: remainder -> letter */
    const char expected[] = "TRWAGMYFPDXBNJZSQVHLCKE";

    for (int i = 0; i < 23; i++)
    {
        char result = get_letter(i);
        tests_run++;
        if (result == expected[i])
        {
            tests_passed++;
        }
        else
        {
            printf("FAIL: get_letter(%d) = '%c', expected '%c'\n",
                   i, result, expected[i]);
        }
    }
}

static void test_get_letter_large_numbers(void)
{
    /* Verify modulo behavior with larger numbers */
    const char expected[] = "TRWAGMYFPDXBNJZSQVHLCKE";

    /* 12345678 % 23 == 19 -> 'L' */
    tests_run++;
    if (get_letter(12345678) == expected[12345678 % 23])
        tests_passed++;
    else
        printf("FAIL: get_letter(12345678)\n");

    /* 00000000 % 23 == 0 -> 'T' */
    tests_run++;
    if (get_letter(0) == 'T')
        tests_passed++;
    else
        printf("FAIL: get_letter(0)\n");

    /* 99999999 % 23 == 11 -> 'B' */
    tests_run++;
    if (get_letter(99999999) == expected[99999999 % 23])
        tests_passed++;
    else
        printf("FAIL: get_letter(99999999)\n");
}

int main(void)
{
    printf("Running DNI generator tests...\n");

    test_get_letter_all_cases();
    test_get_letter_large_numbers();

    printf("%d/%d tests passed\n", tests_passed, tests_run);

    if (tests_passed == tests_run)
    {
        printf("All tests passed!\n");
        return 0;
    }
    else
    {
        printf("Some tests FAILED!\n");
        return 1;
    }
}
