//
// Created by WangQing on 11/01/2018.
//

#ifndef IMP_C_LINKEDLIST_H
#define IMP_C_LINKEDLIST_H

#include <stdio.h>

#if defined(__cplusplus)
extern "c" {
#endif

typedef struct {
    struct llist_node_t *prev;
    struct llist_node_t *next;
    void *data;
    int len;
} llist_node_t;

typedef struct {
    struct llist_node_t *head;
    struct llist_node_t *tail;
    size_t len;
} llist_t;

struct llist_t *llist_create();

int llist_insert(struct llist_t *list, size_t pos, void *data, size_t len);

int llist_remove(struct llist_t *list, size_t pos);

int llist_append(struct llist_t *list, void *data, size_t len);

ssize_t llist_find(struct llist_t *list, void *data, size_t len);

void llist_modify(struct llist_t *list, size_t pos, void *data, size_t len);

int llist_get(llist_t *list, size_t pos, void *data, size_t *len);

void llist_destroy(struct llist_t *list);

#if defined(__cplusplus)
}
#endif

#endif //IMP_C_LINKEDLIST_H