/**
* 2563. ������
* �������� ũ��� ����, ���� 10���� ����.
* �־����� ��: �������� ��, �������� ������ ��ǥ��
* ����: ������ ũ�� 100x100, �����̴� ������ ����� �ʴ´�.
* 1. ���� ��������. 
	- �����̷� �������� 1.
	- �̹� ������������ pass.
*/
#include<iostream>
#define size 10

using namespace std;

int main(void) {
	// ���� ����	
	bool drawPaper[100][100] = { false, };
	int cnt, colorPaper, x, y;
	{
		cin >> colorPaper;
		cnt = 0;
	}

	// �Է� �� ���μ���
	for (int i = 0; i < colorPaper; ++i) {
		cin >> x >> y;
		for (int j = x; j < x + size; ++j) {
			for (int k = y; k < y + size; ++k) {
				if (!drawPaper[j][k]) {
					drawPaper[j][k] = true;
					++cnt;
				}
			}
		}
	}

	// ��� ��
	cout << cnt;

	return 0;
}