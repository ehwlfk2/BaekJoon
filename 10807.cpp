/**
* 10807. ���� ����
* �Է��� ������ � �ΰ�?
* -100 <= ������ ������ ũ�� <= 100
*/
#include<iostream>
using namespace std;

int main(void) {
	// ���� ������� ����
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	// �Է�
	int arr[2 << 7] = { 0,};
	int input, repeat;
	
	cin >> repeat;
	while (repeat--) {
		cin >> input;
		++arr[input + 100];
	}

	// ���
	int v;
	
	cin >> v;
	cout << arr[v + 100];

	return 0;
}