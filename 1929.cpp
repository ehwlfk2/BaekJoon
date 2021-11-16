#include<iostream>
using namespace std;

bool isPrimeValue(int n) {
	for (int i = 2; i * i <= n; i++) 
		if (!(n % i)) return false;
	return true;
}

int main(void) {
	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int m, n, i;
	cin >> m >> n;

	for (m > 1 ? i = m : i = 2; i <= n; i++) {
		if(isPrimeValue(i)) printf("%d\n", i);
	}

	return 0;
}