/*
* 1037 ���
* 
* ù �ٿ� 1�� �ڽ��� ������ ��� ����� ������ �Էµȴ�
* �� ° �ٿ� �ش� ������� �Էµȴ�.
* 
* Ǯ�� : �׳� �Էµ� ��� ����� ���� ���� ���� ���� ū ���� ���ϸ� ������ ���� �ȴ�.
*/

#include<iostream>

int main(void) {
	int n, divisor, min, max;

	min = 1000000;
	max = 2;

	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> divisor;
		if (divisor > max) max = divisor;
		if (divisor < min) min = divisor;
	}

	printf("%d", min * max);
	return 0;
}