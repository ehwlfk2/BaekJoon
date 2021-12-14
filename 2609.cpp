/*
* 2609 최대공약수와 최소공배수
* 
* 두 숫자가 주어진다. 10,000이하의 자연수
* 최대 공약수와 최소 공배수를 구해라.
*/

#include<iostream>

void swap(int* p1, int* p2) {
	int tmp = *p2;
	*p2 = *p1;
	*p1 = tmp;
}

int main(void) {
	// divisor : 최대공약수
	int min, max, divisor = -1;
	std::cin >> min >> max;

	if (min > max) {
		swap(&min, &max);
	}

	if (max % min == 0) {
		divisor = min;
	}

	int tmp = min / 2;
	while (divisor < 0) {
		if (max % tmp == 0 && min % tmp == 0) {
			divisor = tmp;
		}
		tmp--;
	}

	printf("%d\n%d", divisor, divisor * (max / divisor) * (min / divisor));

	return 0;
}