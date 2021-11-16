#include<iostream>
using namespace std;

typedef struct num {
	int data, index;
}num;

int n;
num* m, * c;

void compact() {
	int before = m[0].data;
	m[0].data = 0;
	for (int i = 1, j = 0; i < n; i++) {
		if (m[i].data == before) {
			m[i].data = j;
		}
		else {
			before = m[i].data;
			m[i].data = ++j;
		}
	}
}

bool compare(int i, int j, bool flag) {
	if (flag) { // data
		if (m[i].data < m[j].data) return true;
	}
	else { // index 
		if (m[i].index < m[j].index) return true;
	}
	return false;
}

void msortHeap(int st, int ed, bool flag) {
	int n = (ed + st) / 2;
	if (n != st) {
		msortHeap(st, n, flag);
		msortHeap(n + 1, ed, flag);
	}

	int i = st, k = st, j = n + 1;
	while (1) {
		if (i > n || j > ed) break;
		if (compare(i, j, flag)) {
			c[k++] = m[i++];
		}
		else {
			c[k++] = m[j++];
		}
	}

	while (!(i > n)) c[k++] = m[i++];
	while (!(j > ed))c[k++] = m[j++];

	for (int i = st; i <= ed; i++) m[i] = c[i];
}

void print() {
	for (int i = 0; i < n; i++) {
		printf("%d ", m[i].data);
	}
}

int main(void) {

	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	cin >> n;

	m = new num[n];
	c = new num[n];

	for (int i = 0; i < n; i++) {
		cin >> m[i].data;
		m[i].index = i;
	}

	// 크기에 따른 정렬
	msortHeap(0, n - 1, true);
	// 압축
	compact();
	// 순서에 따른 정렬
	msortHeap(0, n - 1, false);
	// 출력
	print();

	return 0;
}