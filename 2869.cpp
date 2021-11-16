#include<iostream>
using namespace std;

int main(void) {
	int up, down, length;
	cin >> up >> down >> length;

	length -= up;
	up -= down;
	printf("%d", length / up + (length % up == 0 ? 0 : 1) + 1);
}