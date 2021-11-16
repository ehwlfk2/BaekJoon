#include<iostream>


int main(void) {
	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int n, k = 9;
	std::cin >> n;

	for (int i = 1; i < n; i++) {
		k = (k * 2 - i) % 1000000000;
	}
	printf("%d", k);
	
	return 0;
}