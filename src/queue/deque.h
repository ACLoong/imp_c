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

struct deque_t *deque_create();
int deque_insert(struct deque_t *deque, size_t pos, void *data);
void *getHead(struct deque_t *deque);
void *getTail(struct deque_t *deque);
int enQueue(struct deque_t *deque,void *data);
int enQueueHead(struct deque_t *deque, void *data);
int enQueueTail(struct deque_t *deque, void *data);
void *deQueue(struct deque_t* deque);
void *deQueueHead(struct deque_t* deque);
void *deQueueTail(struct deque_t* deque);
int getLength(struct deque_t* deque);
int deque_modify(struct deque_t* deque, size_t pos, void *data);
void deque_clear(struct deque_t* deque);
void deque_destroy(struct deque_t* deque);

#endif //IMP_C_DEQUE_H
