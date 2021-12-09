#include<iostream>
#include<algorithm>

typedef struct Time {
	// 회의실 시작과 끝 시간.
	int start;
	int end;
} Time;

int n;
Time dp[100001];

// 끝시간이 빠를 수록, 끝시간이 같으면 시작시간이 늦을 수록
bool compare(Time f, Time s) {
	if (f.end == s.end)
		return f.start < s.start;
	else
		return f.end < s.end;
}

// 입력 값 처리
void input() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> dp[i].start >> dp[i].end;
	}

	std::sort(dp, dp + n, compare);
}

// 정렬을 기반으로 그리디 알고리즘
int maxSection() {
	int tmp, cnt;
	cnt = 1, tmp = dp[0].end;
	for (int i = 1; i < n; i++) {
		if (tmp <= dp[i].start) {
			tmp = dp[i].end;
			cnt++;
		}
	}
	return cnt;
}

int main(void) {
	input();
	printf("%d", maxSection());

	return 0;
}