/**
* 2738. ��� ����
* N*M ����� A, B�� ���غ���.
* (1) N, M <= 100
* (2) -100 <= ����� ���� <= +100
*/
#include<iostream>
#define max 100
using namespace std;

int main(void) {
	// ���� ������� ����
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n, m, matrix[max][max];
	int i, j, tmp;
	
	// n, m �Է�
	cin >> n >> m;

	// ù��° ���
	for(i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j) {
			cin >> matrix[i][j];
		}
	}

	// �ι�° ���
	for (i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j) {
			cin >> tmp;
			matrix[i][j] += tmp;
		}
	}

	// ���
	for (i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j) {
			cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}