#include<iostream>
#define max(a,b) (((a)>(b))?(a):(b));
int n, m[501][501];

int bigNum() {
	for (int i = n-1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			m[i - 1][j] += max(m[i][j], m[i][j + 1]);
		}
	}
	return m[0][0];
}

int main(void) {
	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);


	std::cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			std::cin >> m[i][j];
		}
	}

	printf("%d\n", bigNum());

	return 0;
}