//
// Created by WangQing on 25/01/2018.
//

#ifndef IMP_C_LINKEDBINARYTREE_H
#define IMP_C_LINKEDBINARYTREE_H

#include <stdio.h>

struct lbtree_node_t {
    struct lbtree_node_t *left;
    struct lbtree_node_t *right;
    void *data;
};

struct lbtree_t {
    struct lbtree_node_t *root;
    size_t depth;
    size_t size;
};

struct lbtree_t *create_lbtree();


#endif //IMP_C_LINKEDBINARYTREE_H
