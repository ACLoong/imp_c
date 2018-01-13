//
// Created by WangQing on 11/01/2018.
//

#include "linkedlist.h"

#include <stdlib.h>

struct llist_t *llist_create()
{
    struct llist_t *list = malloc(sizeof(struct llist_t));
    if (NULL != list) {
        list->head = NULL;
        list->tail = NULL;
        list->len = 0;
    }

    return list;
}

int llist_insert(struct llist_t *list, size_t pos, void *data)
{
    //TODO
}

void llist_remove(struct llist_t *list, size_t pos)
{
    //TODO
}

int llist_lpush(struct llist_t *list, void *data)
{
    //TODO
}

int llist_rpush(struct llist_t *list, void *data)
{
    //TODO
}

void *llist_lpop(struct llist_t *list)
{
    //TODO
}

void *llist_rpop(struct llist_t *list)
{
    //TODO
}

void *llist_get(struct llist_t *list, size_t pos)
{
    //TODO
}

ssize_t llist_find(struct llist_t *list, void *data)
{
    //TODO
}

int llist_modify(struct llist_t *list, size_t pos, void *data)
{
    //TODO
}

void llist_clear(struct llist_t *list)
{
    //TODO
}

void llist_destroy(struct llist_t *list)
{
    if (NULL != list) {
        llist_clear(list);
        free(list);
        list = NULL;
    }
}

struct llist_iter_t *llist_iter_create(struct llist_t *list)
{
    //TODO
}

void llist_iter_destroy(struct llist_iter_t *iter)
{
    //TODO
}

void llist_iter_attach(struct llist_iter_t *iter, struct llist_t *list)
{
    //TODO
}

void llist_iter_detach(struct llist_iter_t *iter)
{
    //TODO
}

void llist_iter_next(struct llist_iter_t *iter)
{
    //TODO
}

void llist_iter_prev(struct llist_iter_t *iter)
{
    //TODO
}

void llist_iter_head(struct llist_iter_t *iter)
{
    //TODO
}

void llist_iter_tail(struct llist_iter_t *iter)
{
    //TODO
}

void llist_iter_seek_head(struct llist_iter_t *iter)
{
    //TODO
}

void llist_iter_seek_tail(struct llist_iter_t *iter)
{
    //TODO
}

struct llist_node_t *llist_node_create()
{
    //TODO
}

void llist_node_destroy(struct llist_node_t *node)
{
    //TODO
}
