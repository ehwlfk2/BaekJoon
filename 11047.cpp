#include<iostream>
#define MAX 100000001
#define min(a, b) ((a) > (b) ? (b) : (a))

// coin�� ������������ �־�����.
int n, k, coin[10];

void input() {
	std::cin >> n >> k;
	for (int i = 0; i < n; i++) {
		std::cin >> coin[i];
	}
}

int minCoinCount() {
	int ret = MAX, tmp, cnt;
	// ���� ������ ��ġ�� �����ؾߵǴ� ��ġ���� ���� �������� �ݺ�.
	for (int i = 0; i < n && k >= coin[i]; i++) {
		// cnt : ���� ����, tmp : �ܾ�
		cnt = 0, tmp = k;
		// ���� �������� ��� �� �ܾ��� ������ �� ���� ��ġ�� ���� �������� �ܵ� ���.
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