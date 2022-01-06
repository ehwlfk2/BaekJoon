/*
* 11051 ���� ��� 2
* (N, K) ���� �����?
* 1 <= N <= 1,000
* 0 <= K <= N
*
* ���� ��� �ι� ° ������ Ȱ���ؾ��Ѵ�. (�Ľ�Į�� ����)
* (n, k) = (n-1, k) + (n-1, k-1)
*/
#include<iostream>
#define div(a) (((a) % 10007))

int dp[1001][1001];

int binaryCoefficient(int n, int k) {
	if (dp[n][k] != 0) return dp[n][k];
	
	switch (k) {
	case 0:
		return dp[n][0] = 1;
	case 1:
		return dp[n][1] = n;
	default:
		if (k == n) return dp[n][k] = 1;
		return dp[n][k] = dp[n][n - k] = div(div(binaryCoefficient(n - 1, k)) + div(binaryCoefficient(n - 1, k - 1)));
	}
}

int main(void) {
	int n, k;
	std::cin >> n >> k;

	printf("%d", binaryCoefficient(n, k));
	return 0;
}