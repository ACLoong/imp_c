//
// Created by WangQing on 2018/1/20.
//



#include "linkedlist.h"

#include "minunit.h"

MU_TEST(llist_create_test_1) {
    struct llist_t * list = llist_create();
    mu_check(list != NULL);
}

MU_TEST(llist_insert_test_1) {
    struct llist_t *list = llist_create();

    if (list != NULL) {
        int data = 3;
        int ret;

        ret = llist_insert(list, 0, &data);
        mu_check(ret == 0);
        mu_check(list->len == 1);

        ret = llist_insert(NULL, 0, &data);
        mu_check(ret == -1);
        mu_check(list->len == 1);

        ret = llist_insert(list, -1, &data);
        mu_check(ret == -1);
        mu_check(list->len == 1);

        //ret = llist_insert(list, 0, NULL);
        mu_check(ret == -1);
        mu_check(list->len == 1);
    }
}

MU_TEST(llist_insert_test_2) {
    mu_check(1 == 1);
}

MU_TEST(llist_insert_test_3) {
    mu_check(1 == 1);
}


MU_TEST_SUITE(linkedlist_suite) {
    MU_RUN_TEST(llist_create_test_1);

    MU_RUN_TEST(llist_insert_test_1);
    MU_RUN_TEST(llist_insert_test_2);
    MU_RUN_TEST(llist_insert_test_3);
}
