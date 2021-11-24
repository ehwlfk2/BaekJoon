#include<iostream>

// 0 < n, m < 1001, ÀÚ¿¬¼ö
int n, m[1001];
int size, l[1000];

void input() {
	// initial
	l[0] = m[0] = 0;
	size = 1;

	// input
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> m[i];
	}
}

int main(void) {

	// input
	input();

	// processing
	for (int i = 1; i <= n; i++) {
		// search & condition
		for (int j = size; j > 0; j--) {
			if (l[j - 1] < m[i]) {
				// update
				if (l[j] == 0) {
					size++;
					l[j] = m[i];
				}
				else if (l[j] > m[i]) {
					l[j] = m[i];
				}

				break;
			}
		}

	}

	// output
	printf("%d", size - 1);

	return 0;
}