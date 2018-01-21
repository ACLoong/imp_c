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

struct deque_t *dequeCreate();
int dequeInsert(struct deque_t *deque, size_t pos, void *data);
void *getHead(struct deque_t *deque);
void *getTail(struct deque_t *deque);
int enQueue(struct deque_t *deque,void *data);
int enQueueHead(struct deque_t *deque, void *data);
int enQueueTail(struct deque_t *deque, void *data);
void *deQueue(struct deque_t* deque);
void *deQueueHead(struct deque_t* deque);
void *deQueueTail(struct deque_t* deque);
int getLength(struct deque_t* deque);
int dequeModify(struct deque_t* deque, size_t pos, void *data);
void dequeClear(struct deque_t* deque);//void llist_clear
void dequeDestroy(struct deque_t* deque);//void llist_destroy

struct deque_iter_t *dequeIterCreate(struct deque_t *deque);
void dequeIterDestory(struct deque_iter_t *iter);
void dequeIterAttach(struct deque_iter_t *iter, struct deque_t *deque);
void dequeIterNext(struct deque_iter_t *iter);
void dequeIterPrev(struct deque_iter_t *iter);
void dequeIterHead(struct deque_iter_t *iter);
void dequeIterTail(struct deque_iter_t *iter);

#endif //IMP_C_DEQUE_H
