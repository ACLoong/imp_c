#include "minunit.h"


MU_TEST(test1) {
    mu_check(1 == 1);
}

MU_TEST_SUITE(linkedlist_suite) {
    MU_RUN_TEST(test1);
}

int main(int argc, char *argv) {

    MU_RUN_SUITE(linkedlist_suite);
    MU_REPORT();
    return 0;
}