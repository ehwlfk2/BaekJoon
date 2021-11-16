#include<iostream>
using namespace std;

int main(void) {
	constexpr int div = 42, tc = 10;
	int divArray[tc] = { 0 }, di = 0;
	
	for (int i = 0, j; i < tc; i++) {
		int num;
		cin >> num;

		num %= div;


		for (j = 0; j < di; j++)
			if (divArray[j] == num) break;

		if (j == di) {
			divArray[di++] = num;
		}
	}
	printf("%d\n", di);

	return 0;
}