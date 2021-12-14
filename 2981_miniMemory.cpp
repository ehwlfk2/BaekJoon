/*
* 2981 �˹�
* �������� �� ���� �������� ���� m�� ���϶�.
*
* �־��� �� n ( 1,000,000,000 >= n, �ڿ��� )
* n[i] - n[j] = m �� ���
*/
#include<cstdio>
#define gab(a,b) ((a) - (b) > 0 ? (a) - (b) : (b) - (a))
#pragma warning(disable:4996)


int GCD(int a, int b) {
	if (a % b == 0) return b;
	return GCD(b, a % b);
}

void printDividor(int n) {
	int i = 2, m[150], j = 0;
	while (i * i < n) {
		if (n % i == 0) {
			printf("%d ", i);
			m[j++] = n / i;
		}
		i++;
	}

	if (i * i == n) printf("%d ", i);

	// ���� for������ int ��� auto ��� type���� �޾Ƽ� ó������.
	// ��� ������ ���� ū ���� �����ϱ� ����!
	for (int i = j - 1; i >= 0; i--) {
		printf("%d ", m[i]);
	}
	printf("%d ", n);

}

int main(void) {
	int n, n1, n2, gcd;

	// 2 <= n <= 100
	scanf("%d %d %d", &n, &n1, &n2);
	gcd = gab(n1, n2);
	for (int i = 2; i < n; i++) {
		scanf("%d", &n2);
		gcd = GCD(gcd, gab(n1, n2));
	}
	printDividor(gcd);

	return 0;
}