#include<iostream>
#define size 10
#define div 1000000000

void initial(int m[][size]) {
	m[0][0] = m[1][0] = 0;
	for (int i = 1; i < size; i++)
		m[0][i] = m[1][i] = 1;
}

int main(void) {
	int n, m[2][10];
	std::cin >> n;

	//initial
	initial(m);

	int i = 1;
	while (i++ < n) {
		int bef = i % 2, now = (i + 1) % 2;

		// make 'now'
		m[now][0] = m[bef][1];
		m[now][9] = m[bef][8];
		for (int j = 1; j < (size - 1); j++) {
			m[now][j] = (m[bef][j - 1] + m[bef][j + 1]) % div;
		}
	}

	// output
	int out = 0, now = i % 2;
	for (int j = 0; j < size; j++) {
		out = (out + m[now][j]) % div;
	}
	printf("%d", out);

	return 0;
}