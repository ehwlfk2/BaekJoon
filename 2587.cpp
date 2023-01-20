/**
* 2587. 대표값2
* 숫자 5개의 평균값과 중앙값을 구하여라.
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