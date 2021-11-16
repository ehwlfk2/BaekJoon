#include<iostream>
using namespace std;

int main(void) {
	/*
	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	*/
	int num, n[10] = { 0 };
	cin >> num;

	while (num) {
		n[num % 10]++;
		num /= 10;
	}

	for (int i = 9; i > -1; i--) {
		while (n[i]--) printf("%d", i);
	}

	return 0;
}