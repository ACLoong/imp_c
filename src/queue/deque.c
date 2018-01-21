//
// Created by WangQing on 2018/1/20.
//
#include"deque.h"

struct deque_t *dequeCreate() {
	struct deque_t *result = (struct deque_t *)malloc(sizeof(struct deque_t));
	
	if (!result) {
		return NULL;
	}

	result->head = NULL;
	result->tail = NULL;
	result->len = 0;
	return result;
}

int dequeInsert(struct deque_t *deque, size_t pos, void *data) {
	if (deque == NULL || data == NULL || pos < 0) {
		return -1;
	}
	
	if (pos == deque->len) {
		enQueue(deque, data);
	}

	struct deque_node_t *p = (struct deque_node_t *)malloc(sizeof(struct deque_node_t));

	if (!p) {
		return -1;
	}

	p->data = data;

	if (pos == 0) {
		p->next = deque->head;
		p->prev = NULL;
		deque->head->prev = p;
		deque->head = p;
	}
	else{
		struct deque_node_t *q = deque->head;
		while (pos--) {
			q = q->next;
		}
		p->next = q;
		p->prev = q->prev; 
		q->prev->next = p;
		q->prev = p;
	}
	
	deque->len++;
	return 0;
}

void *getHead(struct deque_t *deque) {
	if (!deque) {
		return NULL;
	}

	if (!deque->head) {
		return NULL;
	}

	return deque->head->data;
}

void *getTail(struct deque_t *deque) {
	if (!deque) {
		return NULL;
	}

	if (!deque->tail) {
		return NULL;
	}

	return deque->tail->data;
}

int enQueue(struct deque_t *deque, void *data) {
	if (deque == NULL || data == NULL) {
		return -1;
	}

	struct deque_node_t *p = (struct deque_node_t *)malloc(sizeof(struct deque_node_t));

	if (!p) {
		return -1;
	}
	
	p->data = data;
	p->prev = deque->tail;
	p->next = NULL;

	if (deque->len == 0) {
		deque->head = p;
		deque->tail = p;
	}
	else {
		deque->tail->next = p;
		deque->tail = p;
	}
	
	deque->len++;
	return 0;
}

int enQueueHead(struct deque_t *deque, void *data) {
	if (deque == NULL || data == NULL) {
		return -1;
	}

	struct deque_node_t *p = (struct deque_node_t *)malloc(sizeof(struct deque_node_t));

	if (!p) {
		return -1;
	}

	p->data = data;
	p->next = deque->head;
	p->prev = NULL;

	if (deque->len == 0) {
		deque->head = p;
		deque->tail = p;
	}
	else {
		deque->head->prev = p;
		deque->head = p;
	}

	deque->len++;
	return 0;
}

int enQueueTail(struct deque_t *deque, void *data) {
	return enQueue(deque, data);
}

void *deQueue(struct deque_t* deque) {
	if (!deque) {
		return NULL;
	}

	if (deque->len < 0) {
		return NULL;
	}

	struct deque_node_t *p = deque->head;
	void *result = p->data;

	if (deque->len == 1) {
		deque->head = NULL;
		deque->tail = NULL;
	}
	else {
		deque->head = p->next;
		deque->head->prev = NULL;
	}
	
	deque->len--;
	free(p);
	return result;
}

void *deQueueHead(struct deque_t* deque) {
	return deQueue(deque);
}

void *deQueueTail(struct deque_t* deque) {
	if (!deque) {
		return NULL;
	}

	if (!deque->head) {
		return NULL;
	}

	struct deque_node_t *p = deque->tail;
	void *result = p->data;

	if (deque->len == 1) {
		deque->head = NULL;
		deque->tail = NULL;
	}
	else {
		deque->tail = p->prev;
		deque->tail->next = NULL;
	}

	deque->len--;
	free(p);
	return result;
}

int getLength(struct deque_t* deque) {
	if (!deque) {
		return -1;
	}

	return deque->len;
}

int dequeModify(struct deque_t* deque, size_t pos, void *data) {
	if (deque == NULL || data == NULL || pos < 0) {
		return -1;
	}

	if (pos >= deque->len) {
		return -1;
	}

	struct deque_node_t *p = deque->head;
	while (pos--) {
		p = p->next;
	}
	p->data = data;
	return 0;
}

void dequeClear(struct deque_t* deque) {
	if (!deque) {
		return;
	}

	struct deque_node_t *p = deque->head;
	while (p) {
		struct deque_node_t *q = p;
		p = p->next;
		free(q);
	}
	deque->head = NULL;
	deque->tail = NULL;
	deque->len = 0;
}

void dequeDestroy(struct deque_t* deque) {
	if (!deque) {
		return;
	}

	struct deque_node_t *p = deque->head;
	while (p) {
		struct deque_node_t *q = p;
		p = p->next;
		free(q);
	}
	deque = NULL;
}
