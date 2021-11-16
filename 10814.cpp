/* 10814 */

#include<iostream>
using namespace std;

typedef struct member {
	int num, order;
	string name;
}member;

member* m, * c;

void msortHeap(int st, int ed) {
	int n = (ed + st) / 2;
	if (n != st) {
		msortHeap(st, n);
		msortHeap(n + 1, ed);
	}
	
	int i = st, k = st, j = n + 1;
	while (1) {
		if (i > n || j > ed) break;
		if (m[i].num < m[j].num || (m[i].num == m[j].num && m[i].order < m[j].order)) {
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

void msort(int n) {
	c = new member[n];
	msortHeap(0, n - 1);
}

void print(member *m, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d %s\n", m[i].num, m[i].name.c_str());
	}
}

int main(void) {

	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int n; 
	cin >> n;
	
	m = new member[n];
	for (int i = 0; i < n; i++) {
		cin >> m[i].num >> m[i].name;
		m[i].order = i;
	}

	msort(n);
	print(m, n);

	return 0;
}