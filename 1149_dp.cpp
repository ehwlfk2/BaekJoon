#include<iostream>
// 최소 값 찾는 전처리기 정의
#define min(a,b) ((a) < (b) ? (a) : (b))

int main() {
	// 출력 속도 향상
	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	// 필요 변수 선언
	int cost[3], dp[2][3] = { 0 }, n;

	// 전체 갯수 입력
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		// 각 행의 rgb 도색 비용 입력
		std::cin >> cost[0] >> cost[1] >> cost[2];

		// 이전 집까지의 최소 비용 + 현재 도색 비용 = 현재 집까지의 최소 비용.
		dp[i % 2][0] = cost[0] + min(dp[(i + 1) % 2][1], dp[(i + 1) % 2][2]);
		dp[i % 2][1] = cost[1] + min(dp[(i + 1) % 2][0], dp[(i + 1) % 2][2]);
		dp[i % 2][2] = cost[2] + min(dp[(i + 1) % 2][0], dp[(i + 1) % 2][1]);
	}

	// dp 배열에서 최근 변동된 부분에 접근하기위해 n - 1 이 필요하다.
	n--;
	
	// 출력
	printf("%d", min(min(dp[n % 2][0], dp[n % 2][1]), dp[n % 2][2]));
	return 0;
}