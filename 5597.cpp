/**
* 5597. ���� �� ���� ��..?
* �л��� �� 30��.
* ���� ���� ���� 2���� ã�ƶ�.
*/
#include<iostream>
#define taskDone 28
using namespace std;

int main(void) {
	// ���� ������� ����
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	const int student = 31;
	int tmp;
	int cls[student] = { 0, };

	// �Է� �� ���μ���
	for (int i = 0; i < taskDone; ++i) {
		cin >> tmp;
		++cls[tmp];
	}

	// ���
	for (int i = 1; i < student; ++i) {
		if(cls[i] < 1){
			cout << i << "\n";
		}
	}

	return 0;
}