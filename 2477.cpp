/**
* 2477. ���ܹ�
* �ݽð� �������� �������� �־�����
* line = �ٰ����� �ݵ�� �������̴�. -> ���� ���̴� ���� �� ���´�. (1<= line <= 500)
* �ٰ����� ����� ���ڸ� ȸ����Ų ����̴�.
* -> �� ����, ���η� ���̸� ���ϰ� ���� ���ο� ���η� ���� ���̸� ���ش�.
* cnt = 1m^2 �� ���ܰ� ���� ���� �־�����. (1<= cnt <= 20)
* �ݽð�������� ���� 1, ������ 2, �Ʒ��� 3, ���� 4
* total = cnt * square. (max total is 5,000,000.)
*/
#include<iostream>
using namespace std;
/*
[0][0]: �� ���� ����
[0][1]: �� ���� ����
[1][0]: ª�� ���� ����
[1][1]: ª�� ���� ����
*/
#define polygon 6
#define idx(a, i) ((a) - (i) < 0 ? (a) - (i) + polygon : (a)-(i))

int cnt, lines[polygon] = { 0, }, directs[polygon] = { 0, }, small_rect;

int main(void) {

	// 1m^2�� ���� �� �Է�
	cin >> cnt;

	// �� �Է�
	int direct, line, long_width = 0, long_height = 0;
	for (int i = 0; i < polygon; ++i) {
		cin >> direct >> line;
		
		// ���� ī��Ʈ�� ��� ����
		directs[i] = direct;
		lines[i] = line;

		switch (direct) {
		case 1:
		case 2:
			// ����
			if (long_width < line) long_width = line;
			break;
		case 3:
		case 4:
			// ����
			if (long_height < line) long_height = line;
			break;
		}
	}
	for (int i = 0; i < polygon; ++i) {
		if (directs[i] == directs[idx(i, 2)] && directs[idx(i, 1)] == directs[idx(i, 3)]) {
			small_rect = lines[idx(i, 1)] * lines[idx(i, 2)];
			break;
		}
	}
	
	// ���
	cout << (long_width * long_height - small_rect) * cnt;
	
	return 0;
}