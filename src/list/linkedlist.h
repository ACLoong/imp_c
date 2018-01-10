//
// Created by WangQing on 11/01/2018.
//

#ifndef IMP_C_LINKEDLIST_H
#define IMP_C_LINKEDLIST_H


#include <cstdio>

typedef struct {
    struct llist_node_t *next;
    void *data;

}llist_node_t;

typedef struct {
    struct llist_node_t *head_node;
    struct llist_node_t *tail_node;
    size_t length;
}llist_t;

typedef struct {

}llist_hdr_t;

static void llist_create();
static void llist_init();
static void llist_insert();
static void llist_del();
static void llist_append();
static void llist_free();
static void llist_get();
static void llist_modify();

#endif //IMP_C_LINKEDLIST_H