#include<iostream>
#define size 15
using namespace std;

int main(void) {
	int test_case, k, n, field[size][size] = { 0 };
	cin >> test_case;
	
	// 0��.
	for (int i = 1; i < size; i++) field[0][i] = i;

	// ��� ���� ��� ���� ���Ѵ�.
	for (int i = 1; i < size; i++) {
		for (int j = 1; j < size; j++) {
			field[i][j] = field[i - 1][j] + field[i][j - 1];
		}
	}

	while (test_case--) {
		cin >> k >> n;
		printf("%d\n", field[k][n]);
	}
}