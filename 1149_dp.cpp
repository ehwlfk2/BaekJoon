#include<iostream>
// �ּ� �� ã�� ��ó���� ����
#define min(a,b) ((a) < (b) ? (a) : (b))

int main() {
	// ��� �ӵ� ���
	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	// �ʿ� ���� ����
	int cost[3], dp[2][3] = { 0 }, n;

	// ��ü ���� �Է�
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		// �� ���� rgb ���� ��� �Է�
		std::cin >> cost[0] >> cost[1] >> cost[2];

		// ���� �������� �ּ� ��� + ���� ���� ��� = ���� �������� �ּ� ���.
		dp[i % 2][0] = cost[0] + min(dp[(i + 1) % 2][1], dp[(i + 1) % 2][2]);
		dp[i % 2][1] = cost[1] + min(dp[(i + 1) % 2][0], dp[(i + 1) % 2][2]);
		dp[i % 2][2] = cost[2] + min(dp[(i + 1) % 2][0], dp[(i + 1) % 2][1]);
	}

	// dp �迭���� �ֱ� ������ �κп� �����ϱ����� n - 1 �� �ʿ��ϴ�.
	n--;
	
	// ���
	printf("%d", min(min(dp[n % 2][0], dp[n % 2][1]), dp[n % 2][2]));
	return 0;
}