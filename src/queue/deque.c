//
// Created by WangQing on 2018/1/20.
//
#include"deque.h"

struct deque_t *deque_create() {
	struct deque_t *result = (struct deque_t *)malloc(sizeof(struct deque_t));
	
	if (!result) {
		return NULL;
	}

	result->head = NULL;
	result->tail = NULL;
	result->len = 0;
	return result;
}

int deque_insert(struct deque_t *deque, size_t pos, void *data) {
	if (deque == NULL || data == NULL || pos < 0) {
		return -1;
	}
	
	if (pos == deque->len) {
		deque_push(deque, data);
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

void *deque_getHead(struct deque_t *deque) {
	if (!deque) {
		return NULL;
	}

	if (!deque->head) {
		return NULL;
	}

	return deque->head->data;
}

void *deque_getTail(struct deque_t *deque) {
	if (!deque) {
		return NULL;
	}

	if (!deque->tail) {
		return NULL;
	}

	return deque->tail->data;
}

int deque_push(struct deque_t *deque, void *data) {
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

int deque_headPush(struct deque_t *deque, void *data) {
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

int deque_tailPush(struct deque_t *deque, void *data) {
	return deque_push(deque, data);
}

void *deque_pop(struct deque_t* deque) {
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

void *deque_headPop(struct deque_t* deque) {
	return deque_pop(deque);
}

void *deque_tailPop(struct deque_t* deque) {
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

int deque_getLen(struct deque_t* deque) {
	if (!deque) {
		return -1;
	}

	return deque->len;
}

int deque_modify(struct deque_t* deque, size_t pos, void *data) {
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

void deque_clear(struct deque_t* deque) {
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

void deque_destroy(struct deque_t* deque) {
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

struct deque_iter_t *deque_iter_create(struct deque_t *deque) {
	if (!deque) {
		return NULL;
	}

	struct deque_iter_t *result = (struct deque_iter_t *)malloc(sizeof(struct deque_iter_t));

	if (!result) {
		return NULL;
	}

	result->deque = deque;
	result->curr_node = deque->head;
	return result;
}

void deque_iter_destory(struct deque_iter_t *iter) {
	if (!iter) {
		return;
	}

	iter = NULL;
}

void deque_iter_attach(struct deque_iter_t *iter, struct deque_t *deque) {
	if (!deque) {
		return;
	}

	if (!iter) {
		iter = (struct deque_iter_t *)malloc(sizeof(struct deque_iter_t));

		if (!iter) {
			return;
		}
	}

	iter->deque = deque;
	iter->curr_node = deque->head;
}

int deque_iter_next(struct deque_iter_t *iter) {
	if (!iter) {
		return -1;
	}

	if (iter->curr_node == iter->deque->tail) {
		return -1;
	}

	iter->curr_node = iter->curr_node->next;
	return 0;
}

int deque_iter_prev(struct deque_iter_t *iter) {
	if (!iter) {
		return -1;
	}

	if (iter->curr_node == iter->deque->head) {
		return -1;
	}

	iter->curr_node->prev = iter->curr_node->prev;
	return 0;
}

void deque_iter_head(struct deque_iter_t *iter) {
	if (!iter) {
		return;
	}
	
	if (!iter->deque) {
		return;
	}

	iter->curr_node = iter->deque->head;
}
void deque_iter_tail(struct deque_iter_t *iter) {
	if (!iter) {
		return;
	}

	if (!iter->deque) {
		return;
	}

	iter->curr_node = iter->deque->tail;
}

void deque_iter_release(struct deque_iter_t *iter) {
	free(iter);
}
