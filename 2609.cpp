/*
* 2609 �ִ������� �ּҰ����
* 
* �� ���ڰ� �־�����. 10,000������ �ڿ���
* �ִ� ������� �ּ� ������� ���ض�.
*/

#include<iostream>

void swap(int* p1, int* p2) {
	int tmp = *p2;
	*p2 = *p1;
	*p1 = tmp;
}

int main(void) {
	// divisor : �ִ�����
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