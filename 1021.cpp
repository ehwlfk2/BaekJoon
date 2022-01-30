// 1021. 회전하는 큐
#include<iostream>

typedef struct node {
	int value;
	struct node* left;
	struct node* right;
};

int n, m;
node* q, * p, * t;

node* initQueue() {
	q[0].left = &q[n - 1];
	q[0].value = 1;
	q[0].right = &q[1];
	for (int i = 1; i < n - 1; i++) {
		q[i].left = &q[i - 1];
		q[i].value = i + 1;
		q[i].right = &q[i + 1];
	}
	q[n - 1].left = &q[n - 2];
	q[n - 1].value = n;
	q[n - 1].right = &q[0];
	return q;
}

int right(int val) {
	int cnt = 0;
	node* tmp = p;
	while (tmp->value != val) {
		cnt++;
		tmp = tmp->left;
	}
	t = tmp;
	return cnt;
}

int left(int val) {
	int cnt = 0;
	node* tmp = p;
	while (tmp->value != val) {
		cnt++;
		tmp = tmp->right;
	}
	t = tmp;
	return cnt;
}

node* pop() {
	t->left->right = t->right;
	t->right->left = t->left;
	return t->right;
}

int main(void) {
	std::cin >> n >> m;

	// make queue
	q = new node[n];

	// init queue
	p = initQueue();

	// process : p가 해당 값이면 pop, 아니면 left, right 거리 측정 후 가까운 값 더하고 해당 값 pop
	int val, sum = 0, lef, rig;
	while (m--) {
		std::cin >> val;
		lef = left(val), rig = right(val);
		sum += lef < rig ? lef : rig;
		p = pop();
	}
	printf("%d", sum);

	// delete(q);
	return 0;
}