#include<iostream>
using namespace std;

// ���߿� Library�� ����� ���� Pair Class�� �������.
typedef struct dic {
	int x, y;
}dic;

void swap(dic* a, dic* b) {
	dic* c = a;
	a = b;
	b = a;
}

void sortDic(dic* m, int st, int ed) {
	if (st >= ed) return;

	int pivot = st;
	int s = st, e = ed + 1;

	while (s <= e) {
		do {
			s++;
		} while (s <= ed && 
			(m[s].x < m[pivot].x || (m[s].x == m[pivot].x && m[s].y < m[pivot].y)));
		do {
			e--;
		} while (e >= st && 
			(m[e].x > m[pivot].x || (m[e].x == m[pivot].x && m[e].y > m[pivot].y)));

		// ���� ������ ���¸� e�� pivot �� ��ü
		if (s > e) {
			swap(m[e], m[pivot]);
		}
		// �������� �ʾҴٸ� s�� pivot �� ��ü
		else {
			swap(m[s], m[e]);
		}
	}

	sortDic(m, st, e - 1);
	sortDic(m, e + 1, ed);
}

int main(void) {

	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int n;
	dic* m = new dic[100001];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m[i].x >> m[i].y;
	}
	sortDic(m, 0, n - 1);

	for (int i = 0; i < n; i++) printf("%d %d\n", m[i].x, m[i].y);
}