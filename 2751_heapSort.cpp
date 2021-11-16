/* 2751 */
#include<iostream>
using namespace std;

class heapSort {
private:
	int begin, end;
	int* m, * c;

	void sort(int st, int ed) {
		int n = (ed + st) / 2;
		if (n != st) {
			sort(st, n);
			sort(n + 1, ed);
		}

		int i = st, k = st, j = n + 1;
		while (1) {
			if (i > n || j > ed) break;
			if (m[i] < m[j]) {
				c[k++] = m[i++];
			}
			else { // i > j
				c[k++] = m[j++];
			}
		}
		while (!(i > n)) c[k++] = m[i++];
		while (!(j > ed)) c[k++] = m[j++];

		for (int i = st; i <= ed; i++) m[i] = c[i];
	}

public:
	heapSort(int* mArray, int st, int ed) {
		begin = st, end = ed, this->m = mArray;
		c = new int[sizeof(int) * ed];

		sort(st, ed - 1);
	}

	int* getSortArray() {
		return m;
	}

	void showArray() {
		for (int i = begin; i < end; i++) printf("%d\n", m[i]);
	}
};

int main(void) {

	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	int* m = new int[n];
	for (int i = 0; i < n; i++) cin >> m[i];

	heapSort* p = new heapSort(m, 0, n);

	p->showArray();

	delete(p);

	return 0;
}