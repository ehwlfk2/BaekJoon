#include<iostream>
#define max(a,b) ((a) > (b) ? (a) : (b))

int main(void) {
	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int n, m[310][3] = { 0 }, value;

	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> value;

		// 0 : i��°�� �ȹ���
		// 1 : i��°�� ó������
		// 2 : i��°�� �����ؼ����� (i-1��°�� �����)
		m[i][0] = max(m[i - 1][1], m[i - 1][2]);
		m[i][1] = m[i - 1][0] + value;
		m[i][2] = m[i - 1][1] + value;
	}
	printf("%d", max(m[n][1], m[n][2]));

	return 0;
}