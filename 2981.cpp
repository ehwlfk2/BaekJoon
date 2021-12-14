/*
* 2981 �˹�
* �������� �� ���� �������� ���� m�� ���϶�.
*
* �־��� �� n ( 1,000,000,000 >= n, �ڿ��� )
* n[i] - n[j] = m �� ���
*/
#include<iostream>
#include<vector> // vector ���
#include<cmath> // sqrt, ceil ���
#define gab(a,b) ((a) - (b) > 0 ? (a) - (b) : (b) - (a))


int GCD(int a, int b) {
	if (a % b == 0) return b;
	return GCD(b, a % b);
}

void printDividor(int n) {
	int i;
	std::vector<int> v;
	for (i = 2; i < ceil(sqrt(n)); i++) {
		if (n % i == 0) {
			printf("%d ", i);
			v.push_back(n / i);
		}
	}

	if (i * i == n) printf("%d ", i);

	// ���� for������ int ��� auto ��� type���� �޾Ƽ� ó������.
	// ��� ������ ���� ū ���� �����ϱ� ����!
	for (int i = v.size() - 1; i >= 0; i--) {
		printf("%d ", v[i]);
	}
	printf("%d ", n);

}

int main(void) {
	int n, n1, n2, gcd;

	// 2 <= n <= 100
	std::cin >> n >> n1 >> n2;
	gcd = gab(n1, n2);
	for (int i = 2; i < n; i++) {
		std::cin >> n2;
		gcd = GCD(gcd, gab(n1, n2));
	}
	printDividor(gcd);

	return 0;
}