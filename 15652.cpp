#include<iostream>
using namespace std;

int m, n, field[9];

void print() {
	for (int i = 0; i < n; i++) {
		printf("%d ", field[i]);
	}
	printf("\n");
}

void permutation(int start, int deep) {
	for (int i = start; i < m; i++) {
		field[deep] = i + 1;
		if (deep < n - 1)
			permutation(i, deep + 1);
		else
			print();
	}
}

int main(void) {
	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	cin >> m >> n;

	permutation(0, 0);

	return 0;

}