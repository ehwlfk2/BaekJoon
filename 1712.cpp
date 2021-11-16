#include<iostream>
using namespace std;

int main(void) {
	int a, b, c;
	cin >> a >> b >> c;

	if (c - b <= 0) {
		printf("-1\n");
		return 0;
	}
	
	printf("%d\n", a / (c - b) + 1);
	return 0;
}