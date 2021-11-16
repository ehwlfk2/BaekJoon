#include<iostream>
#define big 5
#define small 3
using namespace std;

int main(void) {
	int n, count;
	cin >> n;

	count = n / big;
	n %= big;
	while(n % small && count >= 0) {
		n += big;
		count--;
	}

	if (count < 0) printf("-1");
	else printf("%d", count + n / small);
	return 0;
}