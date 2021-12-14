/*
* 1934 최소공배수
*
* 속도를 만들어주기 위해서 "유클리드 호제법"을 이용해야 한다.
*/
#include<iostream>

int GCD(int a, int b) {
	if (a % b == 0)
		return b;
	return GCD(b, a % b);
}

int main(void) {
	// 빠른 입출력을 위해
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	// n번 반복.
	int n;
	std::cin >> n;

	for (int i = 0; i < n; i++) {
		int n1, n2, gcd;
		std::cin >> n1 >> n2;
		
		// 유클리드 호제법의 n1 > n2 를 지키지 않아도 GCD 안에서 자연히 뒤집힌다.
		gcd = GCD(n1, n2);

		// 최소 공배수 = 최대공약수 * (n1 / 최대공약수) * (n2 / 최대공약수)) = n1 / 최대공약수 * n2
		printf("%d\n", (n1 / gcd) * n2);
	}
	return 0;
}