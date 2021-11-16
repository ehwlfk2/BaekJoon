#include<iostream>
using namespace std;

int *fibonacci(int n) { // n>2
	int* m = new int[3]{ 0, 1, 1 };
	for (int i = 3; i <= n; i++) {
		m[i % 3] = m[(i + 1) % 3] + m[(i + 2) % 3];
	}
	return m;
}

int main() {
	int how_many_repeat, n;
	cin >> how_many_repeat;

	for (int i = 0; i < how_many_repeat; i++) {
		//cin >> n;
		n = i;
		int* m = fibonacci(n);
		printf("%d %d\n", m[(n + 2) % 3], m[n % 3]);
	}
}
