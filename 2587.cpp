/**
* 2587. ��ǥ��2
* ���� 5���� ��հ��� �߾Ӱ��� ���Ͽ���.
*/
#include<iostream>
#define num 5
using namespace std;

int main(void) {
	int arr[num + 1] = { 0, };
	int repeat, tmp, sum, size, swap;
	{
		repeat = num;
		sum = size = 0;
	}

	while (repeat--) {
		cin >> tmp;
		sum += tmp;


		for (int i = 0; i <= size; ++i) {
			if (arr[i] < tmp) {
				swap = arr[i];
				arr[i] = tmp;
				tmp = swap;
			}
		}
		size++;
	}

	cout << sum / num << "\n" << arr[2];

	return 0;
}