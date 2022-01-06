/*
* 2004 ���� 0�� ����
* Q. ���װ���� ���ڸ� 0�� ������?
*
* 2�� ������ 5�� ������ ��� �Ű����Ѵ�.
* ����: 0 <= k <= n <= 2,000,000,000
*/
#include<iostream>
#define ll long long int
ll two, five;

// true -> ���ϱ�, false -> ����
void factorization(int n, bool b) {
	ll tmp = 5;
	// 5^1 �� �! -> 5^2 �� �! -> 5^3 �� � ������ ������ ���Ѵ�.
	while (tmp <= n) {
		b ? five += (n / tmp) : five -= (n / tmp);
		tmp *= 5;
	}
	tmp = 2;
	while (tmp <= n) {
		b ? two += (n / tmp) : two -= (n / tmp);
		tmp *= 2;
	}
}

int main(void) {
	int n, k;
	std::cin >> n >> k;

	factorization(n, true);
	factorization(k, false);
	factorization(n - k, false);

	printf("%lld", two < five ? two : five);

	return 0;
}