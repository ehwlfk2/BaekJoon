/*
* 1676 ���丮�� 0�� ����
* Q. 1�� �ڸ����� 0�� ��ΰ�? (+1 �ؼ� ���)
* 
* �Է� �ִ� �� 500.
* ���� ������ ���� �Ű澲�� ���� ������?
*/
#include<iostream>

int main(void) {
	int n, cnt, mul;
	std::cin >> n;

	cnt = 0, mul = 1;
	for (int i = 2; i <= n; i++) {
		mul *= i;
		while (mul % 10 == 0) {
			cnt++;
			mul /= 10;
		}
		mul %= 1000;
	}
	printf("%d", cnt);

	return 0;
}