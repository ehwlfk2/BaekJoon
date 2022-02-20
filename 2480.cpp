/**
* 2480. 주사위 세개
* 주사위 3개를 던져서
* (1). 모두 같은 값이면 10,000 + 값 * 1,000
* (2). 2개가 같은 값이면 1,000 + 같은 값 * 100
* (3). 모두 다른 값이면 (가장 큰 값) * 100
*/

#include<iostream>
#define max(a,b) ((a) > (b) ? (a) : (b))
using namespace std;

void setting() {
	std::cout.tie(NULL);
	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
}

int main(void) {
	setting();

	int a, b, c, pay = 0;
	cin >> a >> b >> c;
	
	// process
	if (a == b || b == c || c == a) {
		if (a == b && b == c) pay = 10000 + a * 1000;
		else pay = (a == b || a == c) ? pay = 1000 + a * 100 : pay = 1000 + b * 100;
	}
	else {
		pay = max(max(a, b), max(b, c)) * 100;
	}

	cout << pay;
	return 0;
}