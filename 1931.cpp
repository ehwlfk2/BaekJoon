#include<iostream>
#include<algorithm>

typedef struct Time {
	// ȸ�ǽ� ���۰� �� �ð�.
	int start;
	int end;
} Time;

int n;
Time dp[100001];

// ���ð��� ���� ����, ���ð��� ������ ���۽ð��� ���� ����
bool compare(Time f, Time s) {
	if (f.end == s.end)
		return f.start < s.start;
	else
		return f.end < s.end;
}

// �Է� �� ó��
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

// ������ ������� �׸��� �˰���
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