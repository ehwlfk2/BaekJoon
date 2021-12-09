#include<iostream>
#define max(a, b) ((a) > (b) ? (a) : (b))

char a[1001], b[1001];
int dp[1000];
int g_max;

int main(void) {
	std::cin >> a >> b;
	int tmp;
	for (int i = 0; a[i]; i++) {
		tmp = 0; // 현재의 부분 수열 길이.
		for (int j = 0; b[j]; j++) {
			if (a[i] == b[j] && tmp + 1 > dp[j]) {
				dp[j] = tmp + 1;
				tmp = max(tmp, dp[j] - 1);
			}
			else {
				tmp = max(dp[j], tmp);
			}
			g_max = max(dp[j], g_max);
		}
	}

	printf("%d\n", g_max);
	return 0;
}