#include<iostream>
using namespace std;

bool maxSqu(int a, int b, int c) {
	int max, min;
	if (a > b) {
		max = a;
		min = b;
	}
	else {
		max = b;
		min = a;
	}
	if (max > c) {
		min = min * min + c * c;
		max *= max;
	}
	else {
		min = max * max + min * min;
		max = c * c;
	}

	if (max == min) return true;
	else return false;
}

int main(void) {

	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int a, b, c;

	do {
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0) break;
		if (maxSqu(a,b,c)) printf("right\n");
		else printf("wrong\n");
	} while (1);

	return 0;
}