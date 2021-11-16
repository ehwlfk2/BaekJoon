#include<iostream>
using namespace std;
/*
	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
*/
int main(void) {
	int num;
	cin >> num;
	for (int i = 2; num > 1; i++) {
		if (!(num % i)) {
			num /= i;
			printf("%d\n", i--);
		}
	}
}