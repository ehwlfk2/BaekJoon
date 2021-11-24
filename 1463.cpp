#include<iostream>

//memorization
int m[1000001];

void make(int n, int dep) {
	// update
	if (++dep < m[n] || m[n] == 0) {
		m[n] = dep;
	}
	else {
		return;
	}

	if (n > 1) {
		// 3으로 나누기
		if (n % 3 == 0) {
			make(n / 3, dep);
		}
		// 2으로 나누기
		if (n % 2 == 0) {
			make(n / 2, dep);
		}
		// -1 하기
		make(n - 1, dep);
	}
}

int main(void) {
	int n;

	// input 
	std::cin >> n;

	// initial -> update 조건에 추가.

	// process
	make(n, -1);

	// output
	printf("%d", m[1]);

	return 0;
}