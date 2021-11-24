#include <iostream>
#define min(a, b, c) ((a) < (b) ? (a) < (c) ? (a) : (c) : (b) < (c) ? (b) : (c))

int m[1000000];

int main(void) {
	int n;

	// input
	std::cin >> n;

	// initial
	m[2] = m[3] = 1;

	// process
	for (int i = 4; i <= n; i++) {
		int a, b, c;

		// initial
		a = b = c = i;

		// condition 1, 2, 3
		if (i % 3 == 0) a = m[i / 3] + 1;
		if (i % 2 == 0) b = m[i / 2] + 1;
		c = m[i - 1] + 1;

		// update
		m[i] = min(a, b, c);
	}

	printf("%d", m[n]);

	return 0;
}