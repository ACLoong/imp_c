//
// Created by WangQing on 11/01/2018.
//

#include "linkedlist.h"

#include <stdlib.h>

struct llist_t *llist_create() {
	struct llist_t *result = (struct llist_t *)malloc(sizeof(struct llist_t));
	if (!result) {
		return NULL;
	}

	result->head = NULL;
	result->tail = NULL;
	result->len = 0;
	return result;
}

int llist_insert(struct llist_t *list, size_t pos, void *data) {
	if (!list) {
        return -1;
    }

    if (list->len > pos) {
		struct llist_node_t *p = list->head;
		struct llist_node_t *q = (struct llist_node_t *)malloc(sizeof(struct llist_node_t));
		if (!q) {
			return -1;
		}
		q->data = data;
		while (pos--) {
			p = p->next;
		}
		q->next = p;
		q->prev = p->prev;
		q->prev->next = q;
		p->prev = q;
		return 0;
	}
	if (list->len == 0) {
		if (pos != 0) {
			return -1;
		}
		else {
			struct llist_node_t *p = (struct llist_node_t *)malloc(sizeof(struct llist_node_t));
			if (!p) {
				return -1;
			}
			p->data = data;
			p->next = NULL;
			p->prev = NULL;
			list->head = list->tail = p;
			list->len = 1;
			return 0;
		}
	}
	return -1;
}

void llist_remove(struct llist_t *list, size_t pos) {
	if (pos < list->len) {
		struct llist_node_t *p = list->head;
		while (pos--) {
			p = p->next;
		}
		p->next->prev = p->prev;
		p->prev->next = p->next;
		list->len -= 1;
		free(p);
	}
}

int llist_lpush(struct llist_t *list, void *data) {
	struct llist_node_t *p = (struct llist_node_t *)malloc(sizeof(struct llist_node_t));
	if (!p) {
		return -1;
	}
	p->data = data;
	p->next = list->head;
	list->head->prev = p;////
	p->prev = NULL;
	list->head = p;
	list->len += 1;
	return 0;
}

int llist_rpush(struct llist_t *list, void *data) {
	struct llist_node_t *p = (struct llist_node_t *)malloc(sizeof(struct llist_node_t));
	if (!p) {
		return -1;
	}

	p->data = data;
	p->prev = list->tail;
	list->tail->next = p;
	list->tail = p;
	list->tail->next = NULL;
	list->len++;
	return 0;
}

void *llist_lpop(struct llist_t *list) {
	if (0 == list->len) {
		return NULL;
	}

	struct llist_node_t *p = list->head;
	void * data = p->data;

	if (1 == list->len) {
		list->head = NULL;
		list->tail = NULL;
	}
	else {
		list->head = p->next;
		list->head->prev = NULL;
	}

	list->len -= 1;
	free(p);
	return data;
}

void *llist_rpop(struct llist_t *list) {
	if (0 == list->len) {
		return NULL;
	}

	struct llist_node_t *p = list->tail;
	void * data = p->data;
	if (1 == list->len) {
		list->head = NULL;
		list->tail = NULL;
	}
	else {
		list->tail = p->prev;
		list->tail->next = NULL;
	}
	free(p);
	list->len -= 1;
	return data;
}

void *llist_get(struct llist_t *list, size_t pos) {
	if (pos >= list->len) {
		return NULL;
	}
	struct llist_node_t *p = list->head;
	while (pos--) {
		p = p->next;
	}
	return p->data;
}

int llist_modify(struct llist_t *list, size_t pos, void *data) {
	if (pos >= list->len) {
		return -1;
	}
	struct llist_node_t *p = list->head;
	while (pos--) {
		p = p->next;
	}
	p->data=data;

	return 0;
}

void llist_clear(struct llist_t *list) {
	struct llist_node_t *p = list->head;
	while (p) {
		struct llist_node_t *q = p;
		p = p->next;
		free(q);
	}
	list->head = NULL;
	list->tail = NULL;
	list->len = 0;
}

void llist_destroy(struct llist_t *list) {
	struct llist_node_t *p = list->head;
	while (p) {
		struct llist_node_t *q = p;
		p = p->next;
		free(q);
	}
	list=NULL;
}

struct llist_iter_t *llist_iter_create(struct llist_t *list) {
	struct llist_iter_t *result = (struct llist_iter_t *)malloc(sizeof(struct llist_iter_t));
	if (!result) {
		return NULL;
	}
	result->list = list;
	result->curr_node = list->head;
	return result;
}

void llist_iter_attach(struct llist_iter_t *iter, struct llist_t *list) {
	if (list) {
		if (!iter) {
			iter = (struct llist_iter_t *)malloc(sizeof(struct llist_iter_t));
			if (!iter) {
				return;
			}
		}
		iter->list = list;
		iter->curr_node = list->head;
	}
}

void llist_iter_detach(struct llist_iter_t *iter) {
	if (iter) {
		iter->list = NULL;
		iter->curr_node = NULL;
	}
}

void llist_iter_next(struct llist_iter_t *iter) {
	if (iter) {
		if (iter->curr_node->next) {
			iter->curr_node = iter->curr_node->next;
		}
	}
}

void llist_iter_prev(struct llist_iter_t *iter) {
	if (iter) {
		if (iter->curr_node->prev) {
			iter->curr_node = iter->curr_node->prev;
		}
	}	
}

void llist_iter_head(struct llist_iter_t *iter) {
	if (iter) {
		iter->curr_node = iter->list->head;
	}

}

void llist_iter_tail(struct llist_iter_t *iter) {
	if (iter) {
		iter->curr_node = iter->list->tail;
	}
}

struct llist_node_t *llist_node_create()
{
    //TODO
}

void llist_node_destroy(struct llist_node_t *node)
{
    //TODO
}
