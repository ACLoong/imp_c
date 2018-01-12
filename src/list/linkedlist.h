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
} llist_node_t;

typedef struct {
    struct llist_node_t *head;
    struct llist_node_t *tail;
    size_t len;
} llist_t;

typedef struct {
    struct llist_t *list;
    struct llist_node_t *curr_node;
}llist_iter_t;

struct llist_t *llist_create();
int llist_insert(struct llist_t *list, size_t pos, void *data);
void llist_remove(struct llist_t *list, size_t pos);
int llist_lpush(struct llist_t *list, void *data);
int llist_rpush(struct llist_t *list, void *data);
void *llist_lpop(struct llist_t *list);
void *llist_rpop(struct llist_t *list);
void* llist_get(llist_t *list, size_t pos);
ssize_t llist_find(struct llist_t *list, void *data);
int llist_modify(struct llist_t *list, size_t pos, void *data);
void llist_clear(struct llist_t *list);
void llist_destroy(struct llist_t *list);

llist_iter_t *llist_iter_create(struct llist_t *list);
void llist_iter_destroy(struct llist_iter_t *iter);
void llist_iter_attach(struct llist_iter_t *iter, struct llist_t *list);
void llist_iter_detach(struct llist_iter_t *iter);
void llist_iter_seek_head(struct llist_iter_t *iter);
void llist_iter_seek_tail(struct llist_iter_t *iter);
void llist_iter_next(struct llist_iter_t *iter);
void llist_iter_prev(struct llist_iter_t *iter);
void llist_iter_head(struct llist_iter_t *iter);
void llist_iter_tail(struct llist_iter_t *iter);

llist_node_t *llist_node_create();
void llist_node_destroy(llist_node_t *node);

#if defined(__cplusplus)
}
#endif

#endif //IMP_C_LINKEDLIST_H