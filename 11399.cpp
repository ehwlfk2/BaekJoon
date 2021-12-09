#include<iostream>
#include<algorithm>

/**
* 1 <= n <= 1000 : 자연수
* m : 걸리는 시간.
*/
int n, m[1000];

// 입력과 정렬(오름차순)
void input() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> m[i];
	}
	std::sort(m, m + n);
}

// 누적 합 계산
int accumulateSum() {
	int ret, sum;

	sum = ret = 0;
	for (int i = 0; i < n; i++) {
		sum += m[i];
		ret += sum;
	}

	return ret;
}

int main(void) {
	input();
	printf("%d", accumulateSum());

	return 0;
}