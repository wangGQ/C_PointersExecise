
#include <assert.h>
#include <stdio.h>

#define TREE_SIZE 100
#define TREE_TYPE int
#define ARRAY_SIZE (TREE_SIZE + 1)

static TREE_TYPE tree[ARRAY_SIZE];

static int left_child(int current)
{
	return current * 2;
}

static int right_child(int current)
{
	return current * 2 + 1;
}

void insert(TREE_TYPE value)
{
	int current = 1;
	assert(value != 0);
	while (tree[current] != 0) {
		if (value < tree[current])
			current = left_child(current);
		else {
			assert(value != tree[current]);
			current = right_child(current);
		}
	}	
	printf("insert %d in index: %d\n", value, current);
	tree[current] = value;
}

TREE_TYPE *find(TREE_TYPE value)
{
	int current = 1;	
	while (current < ARRAY_SIZE && tree[current] != value) {
		if (value < tree[current] )
			current = left_child(current);
		else
			current = right_child(current);
	}
	if (current < ARRAY_SIZE)
		return tree + current;
	else
		return 0;
}

void output(TREE_TYPE value)
{
	printf("%d ", value);
}

static void do_pre_order_traverse(int current, 
	void (*callback)(TREE_TYPE value))
{
	if (current < ARRAY_SIZE && tree[current] != 0) {
		callback(tree[current]);
		do_pre_order_traverse(left_child(current), callback);
		do_pre_order_traverse(right_child(current), callback);
	}	
}

void pre_order_traverse(void (*callback)(TREE_TYPE value))
{
	do_pre_order_traverse(1, callback);
}

int main()
{
	int n, m;
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &m);
		insert(m);
	}
	pre_order_traverse(output);
	return 0;
	
}


