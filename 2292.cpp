#include<iostream>
using namespace std;

int main(void) {
	int d = 1, n = 1, x;

	cin >> x;
	while (n < x) {
		n += d * 6;
		d++;
	}
	printf("%d\n", d);

	return 0;
}