#include "minunit.h"
#include <lcthw/string_algos.h>
#include <lcthw/bstrlib.h>
#include <time.h>

struct tagbstring IN_STR = bsStatic("I have ALPHA beta ALPHA orages ALPHA");
struct tagbstring ALPHA = bsStatic("ALPHA");

const int TEST_TIME = 1;

char *test_find_and_scan() {
        StringScanner *scan = StringScanner_create(&IN_STR);
        mu_assert(scan != NULL, "Failed to make the scanner.");

        int find_i = String_find(&IN_STR, &ALPHA);
        mu_assert(find_i > 0, "Failed to find 'ALPHA' in test string.");

        int scan_i = StringScanner_scan(scan, &ALPHA);
        mu_assert(scan_i > 0, "Failed to find 'ALPHA' with scan.");
        mu_assert(scan_i == find_i, "find and scan don't match.");

        scan_i = StringScanner_scan(scan, &ALPHA);
        mu_assert(scan_i > find_i, "should find another ALPHA.");

        scan_i = StringScanner_scan(scan, &ALPHA);
        mu_assert(scan_i > find_i, "should find another ALPHA.");

        mu_assert(StringScanner_scan(scan, &ALPHA) == -1, "shouldn't find it.");

        StringScanner_destroy(scan);
}

char *test_binstr_performance() {
        return NULL;
}

char *all_tests() {
        mu_suite_start();
        mu_run_test(test_find_and_scan);

        return NULL;
}

RUN_TESTS(all_tests);
