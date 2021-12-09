// ����� �賶
#include<iostream>
#define max(a,b) ((a) > (b) ? (a) : (b))

/**
* n : ������ ����, 1 <= n <= 100
* k : ������ �Ѱ� ����, 1 <= k <= 100,000
* w : ������ ����, 1 <= w <= 100,000
* v : ������ ��ġ, 0 <= v <= 1,000
*/

/**
* ���� ���Ǳ��� �־��� �� �ְ� ȿ��!!
* index : ����
* value : ��ġ
*/
int dp[100001];

int inputProcess() {
	int n, k, w, v;
	std::cin >> n >> k;
	for (int i = 0; i < n; i++) {
		std::cin >> w >> v;

		for (int j = k; j >= w; j--) {
			dp[j] = max(dp[j], v + dp[j - w]);
		}
	}

	return dp[k];
}

int main(void) {
	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	printf("%d", inputProcess());
	return 0;
}