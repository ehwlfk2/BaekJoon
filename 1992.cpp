/* 1922. ����Ʈ��
* ������ ũ�� : N
* 1 <= N <= 64, 2�� ������*
*/
#include<iostream>
#define max 65
using namespace std;

int n, bufIdx;
char field[max][max], buffer[2 << 13];

void setting();
void insert();
void quadTree(int row, int col, int size);

// main
int main(void) {
	setting();

	// process... 
	insert();
	quadTree(0, 0, n);
	cout << buffer;

	return 0;
}

// ����� �ӵ� ����ȭ
void setting() {
	std::cout.tie(NULL);
	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
}

// �Է�
void insert() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> field[i];
	}
}

// Recursive Ż�⹮
bool isAllSameValue(int row, int col, int size) {
	int value = field[row][col];
	for (int i = row; i < row + size; i++) {
		for (int j = col; j < col + size; j++) {
			if (value != field[i][j]) return false;
		}
	}
	return true;
}

// Process
void quadTree(int row, int col, int size) {
	if (isAllSameValue(row, col, size)) {
		buffer[bufIdx++] = field[row][col];
		return;
	}
	buffer[bufIdx++] = '(';
	// recursive
	int half = size / 2;
	quadTree(row, col, half);
	quadTree(row, col + half, half);
	quadTree(row + half, col, half);
	quadTree(row + half, col + half, half);
	buffer[bufIdx++] = ')';
}
