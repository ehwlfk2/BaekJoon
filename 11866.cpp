// 11866. 요세푸스 문제 0
#include<cstdio>
#pragma warning(disable:4996)

// int buf[2 << 10], bufIdx;
typedef struct chair {
	int num;
	struct chair* link;
} chair;

chair* q;

chair* makeCircle(int n) {
	chair* circle = new chair[n];

	for (int i = 0; i < n; i++) {
		circle[i].num = i + 1;
		circle[i].link = &circle[i + 1];
	}

	circle[n - 1].num = n;
	circle[n - 1].link = &circle[0];

	return &circle[n - 1];
}

int pop() {
	chair* tmp = q->link;
	q->link = tmp->link;
	return tmp->num;
}

int main(void) {
	int k, n;

	scanf("%d %d", &n, &k);
	printf("<");

	q = makeCircle(n);
	while (q != q->link) {
		n = k - 1;
		while (n--) { 
			q = q->link;
		}
		printf("%d, ", pop());
	}
	printf("%d>", pop());
	return 0;
}