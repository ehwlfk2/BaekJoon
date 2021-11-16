#include<iostream>
using namespace std;

bool isPrimeValue(int n) {
	if (n <= 1) return false;
	for (int i = 2; i * i <= n; i++)
		if (!(n % i)) return false;
	return true;
}

int main() {
	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int num, count = 0, n;
	cin >> num;
	while (num--) {
		cin >> n;
		if (isPrimeValue(n)) count++;
	}
	
	printf("%d\n", count);
	return 0;
}