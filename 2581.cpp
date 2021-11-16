#include<iostream>
using namespace std;

bool isPrimeValue(int n) {
	if (n <= 1) return false;
	for (int i = 2; i * i <= n; i++)
		if (!(n % i)) return false;
	return true;
}

int main(void) {
	int m, n, minPrime = -1, sumPrime = 0;
	
	cin >> m >> n;
	do {
		if (isPrimeValue(m)) {
			sumPrime += m;
			if (minPrime < 0) minPrime = m;
		}
	} while (m++ < n);

	if (minPrime < 0) printf("%d\n", minPrime);
	else printf("%d\n%d\n", sumPrime, minPrime);
	return 0;
}