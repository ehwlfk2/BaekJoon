#include<iostream>

// ������ ������ "n <= 100"�� �ڿ����̰� �� ��ġ�� "pos <= 500"�� �ڿ���
int n, pos[501], lastNumber;

void input() {
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;

		// ���� ��ġ = index
		std::cin >> tmp;
		if (tmp > lastNumber) lastNumber = tmp;

		// ���� ��ġ = pos -> ���� ��ġ�� �ΰ� �̻��� �������� ���� �� ����.
		std::cin >> pos[tmp];
	}
}

int findLis() {
	int l[101] = { 0 }, lis = 1, tmp;

	// Repeat until lastNumber index 
	for (int i = 0; i <= lastNumber; i++) {
		
		// '0' �̸� �ǹ̾��� ��.
		if (!(tmp = pos[i])) continue;

		// LIS ���!
		for (int j = lis; j > 0; j--) {
			if (l[j - 1] < tmp) {
				if (l[j] == 0) {
					l[j] = tmp;
					lis++;
				}
				else if (l[j] > tmp) {
					l[j] = tmp;
				}
				break;
			}
		}
	}

	return lis - 1;
}

int main(void) {

	input();
	printf("%d", n - findLis());

	return 0;
}