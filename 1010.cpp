/*
* 1010 �ٸ� ����
* 0 < r <= m < 30
* (m, r) ���װ�� ���ϱ�
*/
#include<iostream>
#define ll long long int

int n, m, r;

ll binaryCoefficient(int n, int k) {
	ll sum = 1;
	for (int i = 0; i < k; i++) {
		sum = ((ll)n - i) * sum / ((ll)i + 1);
	}
	return sum;
}

int main(void) {
	// ���� ������� ����
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> n;
	while (n--) {
		std::cin >> m >> r;
		printf("%lld\n", binaryCoefficient(r, m < r - m ? m : r - m));
	}

	return 0;
}