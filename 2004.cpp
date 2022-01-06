/*
* 2004 조합 0의 개수
* Q. 이항계수의 끝자리 0의 갯수는?
*
* 2의 지수와 5의 지수를 모두 신경써야한다.
* 조건: 0 <= k <= n <= 2,000,000,000
*/
#include<iostream>
#define ll long long int
ll two, five;

// true -> 더하기, false -> 빼기
void factorization(int n, bool b) {
	ll tmp = 5;
	// 5^1 이 몇개! -> 5^2 이 몇개! -> 5^3 이 몇개 순서로 갯수를 구한다.
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