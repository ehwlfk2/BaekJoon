// 평범한 배낭
#include<iostream>
#define max(a,b) ((a) > (b) ? (a) : (b))

/**
* n : 물건의 갯수, 1 <= n <= 100
* k : 가방의 한계 무게, 1 <= k <= 100,000
* w : 물건의 무게, 1 <= w <= 100,000
* v : 물건의 가치, 0 <= v <= 1,000
*/

/**
* 현재 물건까지 넣었을 때 최고 효율!!
* index : 무게
* value : 가치
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