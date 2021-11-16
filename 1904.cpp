#include<iostream>
using namespace std;

int n;

int fibonacci() {
	int m[3] = { 1, 1, 2 };
	for (int i = 3; i <= n; i++) {
		m[i % 3] = (m[(i + 1) % 3] + m[(i + 2) % 3]) % 15746;
	}
	return m[n%3];
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	printf("%d", fibonacci());

	return 0;
}