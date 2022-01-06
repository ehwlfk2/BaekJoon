/*
* 11051 ���� ��� 2 : (N, K) ���� �����?
* (1 <= N <= 1,000) : (0 <= K <= N)
* �Ľ�Į�� �ﰢ���� ������.
*/
#include<cstdio>
#pragma warning(disable:4996)

int tmp, n, k, dp[1001] = { 1 };

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		tmp = 1;
		for (int j = 1; j <= i; j++) {
			dp[j] = (dp[j] + tmp);
			tmp = dp[j] - tmp;
			dp[j] %= 10007;
		}
	}
	printf("%d", dp[k]);
	return 0;
}