#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#define TREE_TYPE int

typedef struct TREE_NODE {
	TREE_TYPE value;
	struct TREE_NODE* left;
	struct TREE_NODE* right;
}TREE_NODE;

static TREE_NODE *tree;

void insert(TREE_TYPE value)
{
	TREE_NODE *current;
	TREE_NODE **link;
	link = &tree;
	while ((current = *link) != NULL) {
		if (value < current->value)
			link = &current->left;
		else {
			assert(current->value != value);
			link = &current->right;
		}
	}
	current = malloc(sizeof(TREE_NODE));
	assert(current != NULL);
	current->value = value;
	current->left = current->right = NULL;
	*link = current;
}

TREE_TYPE *find(TREE_TYPE value)
{
	TREE_NODE *current = tree;	
	while (current != NULL && current->value != value) {
		if (current->value < value)	
			current = current->right;
		else
			current = current->left;
	}
	if (current != NULL)
		return &current->value;
	else
		return NULL;
	
}


static void do_pre_traverse(TREE_NODE *current, void (*callback)(TREE_TYPE value))
{
	if (current != NULL) {
		callback(current->value);	
		do_pre_traverse(current->left, callback);
		do_pre_traverse(current->right, callback);
	}
}

void pre_traverse(TREE_NODE *current, void (*callback)(TREE_TYPE value))
{
	do_pre_traverse(tree, callback);
}

void destory_tree( TREE_NODE *current) //后缀遍历
{
	if (current == NULL)
		return;	
	destory_tree(current->left);
	destory_tree(current->right);
	printf("free %d\n", current->value);
	free(current);
	if (current == tree) {
		printf("set tree pointer to NULL\n");
		tree = NULL;
	}
}

void destory_tree2(TREE_NODE **current)
{
	TREE_NODE *tmp = *current;
	if (tmp == NULL)
		return;
	destory_tree2(&(tmp->left));
	destory_tree2(&(tmp->right));
	printf("free %d\n", tmp->value);
	free(tmp);
	*current = NULL;
}

int main()
{
	int n, m;
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &m);
		insert(m);
	}
	assert(tree != NULL);
	//destory_tree2(&tree);
	//assert(tree == NULL);
	destory_tree2(&(tree->right));
	return 0;
}
