#include<iostream>
using namespace std;

int reverse_num(int n) {
	int m = 0;
	while (n > 0) {
		m *= 10;
		m += n % 10;
		n /= 10;
	}
	return m;
}

int reverse_max(int a, int b) {
	a = reverse_num(a);
	b = reverse_num(b);
	return a > b ? a : b;
}

int main(void) {
	int a, b;
	cin >> a >> b;
	printf("%d", reverse_max(a, b));

	return 0;
}