#include "minunit.h"

#include "linkedlist_test.hpp"

int main(int argc, char *argv[]) {

    //test
    MU_RUN_SUITE(linkedlist_suite);
    MU_REPORT();
    return 0;
}