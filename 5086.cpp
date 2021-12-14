/**
* 5086 ����� ���
*
* ���� 2�� �Է� n1, n2 < 10,000 �ڿ���
* ���� ���� n1 = n2 = 0
* ���� : �� ���ڰ� ���� ���� ����.
*
* n1�� n2�� ����ΰ�?
* n1�� n2�� ����ΰ�?
* �Ѵ� �ƴѰ�?
*/
#include<iostream>

bool isFactor(int n1, int n2) {
	return n2 % n1 == 0 ? true : false;
}

int main(void) {
	int n1, n2;

	// ���� ������� ����
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	// ���μ��� �κ�
	while (true) {
		std::cin >> n1 >> n2;

		if (n1 == n2) { // �� ���ڰ� ���� ���� 0 �� ��� ��!
			break;
		}

		// ��º�
		if (isFactor(n1, n2)) {
			printf("factor\n");
		}
		else if (isFactor(n2, n1)) {
			printf("multiple\n");
		}
		else {
			printf("neither\n");
		}
	} // while

	return 0;
}