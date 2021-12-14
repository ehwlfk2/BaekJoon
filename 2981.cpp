/*
* 2981 검문
* 나누었을 때 같은 나머지를 같는 m을 구하라.
*
* 주어진 수 n ( 1,000,000,000 >= n, 자연수 )
* n[i] - n[j] = m 의 배수
*/
#include<iostream>
#include<vector> // vector 사용
#include<cmath> // sqrt, ceil 사용
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

	// 향상된 for문에서 int 대신 auto 라는 type으로 받아서 처리가능.
	// 출력 순서가 점점 큰 수로 진행하기 위해!
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