#include<iostream>
using namespace std;

int main(void) {
	int count = 0, max = 0, num[10];

	for (int i = 0; i < 9; i++) {
		cin >> num[i];

		if (num[i] > max) {
			max = num[i];
			count = i;
		}
	}
	printf("%d\n%d\n", max, count + 1);
	return 0;
}