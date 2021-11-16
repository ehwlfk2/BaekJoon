#include<iostream>
using namespace std;

int main(void) {
	int mul, number[10] = { 0 };
	{
		int a, b, c;
		cin >> a >> b >> c;
		mul = a * b * c;
	}
	while (mul > 0) {
		number[mul % 10]++;
		mul /= 10;
	}
	for (int e : number) printf("%d\n", e);

	return 0;
}