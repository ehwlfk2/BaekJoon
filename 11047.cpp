#include<iostream>
#define MAX 100000001
#define min(a, b) ((a) > (b) ? (b) : (a))

// coin은 오름차순으로 주어진다.
int n, k, coin[10];

void input() {
	std::cin >> n >> k;
	for (int i = 0; i < n; i++) {
		std::cin >> coin[i];
	}
}

int minCoinCount() {
	int ret = MAX, tmp, cnt;
	// 현재 코인의 가치가 지불해야되는 가치보다 작은 경우까지만 반복.
	for (int i = 0; i < n && k >= coin[i]; i++) {
		// cnt : 동전 갯수, tmp : 잔액
		cnt = 0, tmp = k;
		// 현재 코인으로 계산 후 잔액이 있으면 더 작은 가치를 가진 코인으로 잔돈 계산.
		for (int j = i; j >= 0 && tmp > 0; j--) {
			cnt += tmp / coin[j];
			tmp = tmp% coin[j];
		}
		ret = min(ret, cnt);
	}
	return ret;
}

int main(void) {
	input();

	printf("%d", minCoinCount());

	return 0;
}