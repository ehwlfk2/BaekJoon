/**
* 11401. 이항 계수
* (N, K) % 1,000,000,007로 나눈 나머지를 구하라.
* condition.
* (1). 1 <= N <= 4,000,000
* (2). 0 <= K <= N
*/

#include<iostream>
using ll = long long;
const ll M = 1000000007;

ll factorial(ll n);
ll mpow(ll base, ll expo);

int main(void) {
	ll n, k, N, K;
	std::cin >> n >> k;

	N = factorial(n);
	K = mpow(factorial(k) * factorial(n - k) % M, M - 2);
	std::cout << N * K % M;
}

ll factorial(ll n) {
	ll fac = 1L;

	while (n > 1) {
		fac = (fac * n) % M;
		n--;
	}
	return fac;
}

ll mpow(ll base, ll expo) {
	ll res = 1;

	while (expo > 0) {
		if (expo % 2 == 1) {
			res = (res * base) % M;
		}
		base = (base * base) % M;
		expo /= 2;
	}
	return res;
}

