/*
* 3036 ��
* 
* Ǯ�� : a[0], a[1], a[2] ....
* a[0] �� a[i] �� gcd�� ���ϰ� ���� ������ �װ��� '���м�'
* 
* ��� : a[i] / a[0] .... 
*/
#include<iostream>

int GCD(int a, int b) {
	if (a % b == 0)
		return b;
	return GCD(b, a % b);
}

int main(void) {
	// ���� ������� ����
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	// 3 <= n <= 100
	int n, pivot, gear;
	std::cin >> n >> pivot;
	for (int i = 1; i < n; i++) {
		std::cin >> gear;
		int gcd = GCD(pivot, gear);
		//printf("gcd : %d\n", gcd);
		printf("%d/%d\n", pivot / gcd, gear / gcd);
	}

	return 0;
}