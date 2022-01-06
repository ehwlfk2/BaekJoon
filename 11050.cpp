/*
* 11050 이항 계수 1
* (N, K) 이항 계수는?
* 1 <= N <= 10
* 0 <= K <= N
*/
#include<iostream>

int binaryCoefficient(int n, int k) {
	double sum = 1;
	if (k < 0 || k > n) return 0;
	for (int i = 0; i < k; i++) {
		sum = ((double)n - i) * sum / ((double)i + 1);
	}
	return (int)sum;
}

int main(void) {
	int n, k;
	std::cin >> n >> k;

	printf("%d", binaryCoefficient(n, k));
	return 0;
}