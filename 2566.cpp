/**
* 2566. �ִ�
* 9x9 �����ǿ� ������ 81���� �ڿ��� �Ǵ� 0�� �־��� ��, 
* �ִ񰪰� �ش� ���� ��� ���� ��� ��ġ�ߴ��� ����ض�.
* [��\n �� ��]
*/
#include<iostream>
#define size 9
using namespace std;

int main(void) {
	// ���� ���� �� �ʱ�ȭ
	int row, col, tmp, max;
	{
		row = col = tmp = max = -1;
	}

	// �Է� ��
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			cin >> tmp;
			// �ִ��� ������ �������.
			if (max < tmp) {
				max = tmp;
				row = i;
				col = j;
			}
		}
	}

	// ��� ��
	cout << max << "\n" << row + 1 << " " << col + 1;

	return 0;
}