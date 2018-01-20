#include "minunit.h"

#include "linkedlist_test.hpp"

int main(int argc, char *argv) {

    MU_RUN_SUITE(linkedlist_suite);

    MU_REPORT();
    return 0;
}