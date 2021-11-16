#include<iostream>
using namespace std;
/*
	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
*/

int factorial(int n) {
	if (n == 0) return 1;
	return factorial(n - 1) * n;
}

int main(void) {
	int n;
	cin >> n;
	printf("%d\n", factorial(n));
	return 0;
}