#include<iostream>
#include<algorithm>

/**
* 1 <= n <= 1000 : �ڿ���
* m : �ɸ��� �ð�.
*/
int n, m[1000];

// �Է°� ����(��������)
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

// ���� �� ���
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