// ����� �賶
#include<iostream>
#define max(a,b) ((a) > (b) ? (a) : (b))

/**
* n : ������ ����, 1 <= n <= 100
* k : ������ �Ѱ� ����, 1 <= k <= 100,000
* w : ������ ����, 1 <= w <= 100,000
* v : ������ ��ġ, 0 <= v <= 1,000
*/
int n, k, w[100], v[100];
/**
* ���� ���Ǳ��� �־��� �� �ְ� ȿ��!!
* index : ����
* value : ��ġ
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
	// ������ index
	for (int i = 0; i < n; i++) {
		int* before = dp[i % 2], * after = dp[(i + 1) % 2];

		// ������ ����
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