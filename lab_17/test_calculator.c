#include <stdarg.h>
#include <stdio.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "math.h"

static void test_sum(void **state) {
    assert_int_equal(sum(1, 2), 3);
}

static void test_difference(void **state) {
    assert_int_equal(difference(1, 2), 2);

}

static void test_multiplication(void **state) {
    assert_int_equal(multiplication(1, 2), 2);
}

static void test_real_division(void **state) {
    assert_float_equal(real_division(1, 2), 0.5f, 0.001f);

}

static void test_remainder_of_division(void **state) {
    assert_int_equal(remainder_of_division(1, 2), 1);
}

int main() {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_sum),
        cmocka_unit_test(test_difference),
        cmocka_unit_test(test_multiplication),
        cmocka_unit_test(test_real_division),
        cmocka_unit_test(test_remainder_of_division),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}