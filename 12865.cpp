// 평범한 배낭
#include<iostream>
#define max(a,b) ((a) > (b) ? (a) : (b))

/**
* n : 물건의 갯수, 1 <= n <= 100
* k : 가방의 한계 무게, 1 <= k <= 100,000
* w : 물건의 무게, 1 <= w <= 100,000
* v : 물건의 가치, 0 <= v <= 1,000
*/
int n, k, w[100], v[100];
/**
* 현재 물건까지 넣었을 때 최고 효율!!
* index : 무게
* value : 가치
*/
int dp[2][100001];

void input() {
	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	std::cin >> n >> k;
	for (int i = 0; i < n; i++) {
		std::cin >> w[i] >> v[i];
	}
}

int process() {
	// 물건의 index
	for (int i = 0; i < n; i++) {
		int* before = dp[i % 2], * after = dp[(i + 1) % 2];

		// 가방의 무게
		int j = 0;
		while (j < w[i]) after[j] = before[j], j++;
		while (j <= k) after[j] = max(before[j], v[i] + before[j - w[i]]), j++;
	}

	return max(dp[0][k], dp[1][k]);
}

int main(void) {

	input();
	int value = process();

	printf("%d", value);

	return 0;
}