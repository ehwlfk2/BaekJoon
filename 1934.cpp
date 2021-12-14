/*
* 1934 �ּҰ����
*
* �ӵ��� ������ֱ� ���ؼ� "��Ŭ���� ȣ����"�� �̿��ؾ� �Ѵ�.
*/
#include<iostream>

int GCD(int a, int b) {
	if (a % b == 0)
		return b;
	return GCD(b, a % b);
}

int main(void) {
	// ���� ������� ����
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	// n�� �ݺ�.
	int n;
	std::cin >> n;

	for (int i = 0; i < n; i++) {
		int n1, n2, gcd;
		std::cin >> n1 >> n2;
		
		// ��Ŭ���� ȣ������ n1 > n2 �� ��Ű�� �ʾƵ� GCD �ȿ��� �ڿ��� ��������.
		gcd = GCD(n1, n2);

		// �ּ� ����� = �ִ����� * (n1 / �ִ�����) * (n2 / �ִ�����)) = n1 / �ִ����� * n2
		printf("%d\n", (n1 / gcd) * n2);
	}
	return 0;
}