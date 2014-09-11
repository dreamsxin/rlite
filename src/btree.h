#ifndef _BTREE_H
#define _BTREE_H

typedef struct {
	int score_size;
	int value_size;
	int (*cmp)(void *v1, void *v2);
	void (*formatter)(void *v, char **str, int *size);
} rl_tree_type;

rl_tree_type long_set;
rl_tree_type long_hash;

void init_long_set();
void init_long_hash();

typedef struct rl_tree_node {
	void **scores;
	// children is null when the node is a leaf
	// when created, allocs size+1.
	long *children;
	void **values;
	// size is the number of children used; allocs the maximum on creation
	long size;
} rl_tree_node;

typedef struct rl_accessor {
	void *(*getter)(void *tree, long number);
	long (*setter)(void *tree, void *node);
} rl_accessor;

typedef struct {
	long max_size; // maximum number of scores in a node
	long height;
	rl_tree_type *type;
	rl_tree_node *root;
	rl_accessor *accessor;
} rl_tree;

rl_tree *rl_tree_create(rl_tree_type *type, long max_size, rl_accessor *accessor);
int rl_tree_add_child(rl_tree *tree, void *score, void *value);
long rl_tree_find_score(rl_tree *tree, void *score, rl_tree_node *** nodes, long **positions);
void rl_print_tree(rl_tree *tree);
void rl_flatten_tree(rl_tree *tree, void *** scores, long *size);

#endif