/*
* 2981 검문
* 나누었을 때 같은 나머지를 같는 m을 구하라.
*
* 주어진 수 n ( 1,000,000,000 >= n, 자연수 )
* n[i] - n[j] = m 의 배수
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

	// 향상된 for문에서 int 대신 auto 라는 type으로 받아서 처리가능.
	// 출력 순서가 점점 큰 수로 진행하기 위해!
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