//
// Created by WangQing on 2018/1/20.
//

#ifndef IMP_C_DEQUE_H
#define IMP_C_DEQUE_H
#include <stdio.h>
#include<stdlib.h>

struct deque_node_t {
	struct deque_node_t *prev;
	struct deque_node_t *next;
	void *data;
};

struct deque_t {
	struct deque_node_t *head;
	struct deque_node_t *tail;
	size_t len;
};

struct deque_iter_t {
	struct deque_t *deque;
	struct deque_node_t *curr_node;
};

struct deque_t *deque_create();
int deque_insert(struct deque_t *deque, size_t pos, void *data);
void *deque_getHead(struct deque_t *deque);
void *deque_getTail(struct deque_t *deque);
int deque_push(struct deque_t *deque,void *data);
int deque_headPush(struct deque_t *deque, void *data);
int deque_tailPush(struct deque_t *deque, void *data);
void *deque_pop(struct deque_t *deque);
void *deque_headPop(struct deque_t *deque);
void *deque_tailPop(struct deque_t *deque);
int deque_getLen(struct deque_t *deque);
int deque_modify(struct deque_t *deque, size_t pos, void *data);
void deque_clear(struct deque_t *deque);
void deque_destroy(struct deque_t *deque);

struct deque_iter_t *deque_iter_create(struct deque_t *deque);
void deque_iter_destory(struct deque_iter_t *iter);
void deque_iter_attach(struct deque_iter_t *iter, struct deque_t *deque);
int deque_iter_next(struct deque_iter_t *iter);
int deque_iter_prev(struct deque_iter_t *iter);
void deque_iter_head(struct deque_iter_t *iter);
void deque_iter_tail(struct deque_iter_t *iter);
void deque_iter_release(struct deque_iter_t *iter);

#endif //IMP_C_DEQUE_H
