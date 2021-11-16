#include<iostream>
using namespace std;

int main(void) {
	//std::cin.tie(NULL);
	//std::ios_base::sync_with_stdio(false);

	int x, y = 0;
	cin >> x;
	x *= 2;
	int n = 1;
	while (1) {
		if (n * (n + 1) >= x) break;
		n++;
	}

	int a, b;
	x = x / 2 - n * (n - 1) / 2; // Â÷ÀÌ
	a = x, b = n - x + 1;

	if (n % 2) {
		printf("%d/%d\n", b, a);
	}
	else {
		printf("%d/%d\n", a, b);
	}

	return 0;
}