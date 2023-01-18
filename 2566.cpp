/**
* 2566. 최댓값
* 9x9 격자판에 쓰여진 81개의 자연수 또는 0이 주어질 때, 
* 최댓값과 해당 값의 행과 열이 어디 위치했는지 출력해라.
* [값\n 행 열]
*/
#include<iostream>
#define size 9
using namespace std;

int main(void) {
	// 변수 선언 및 초기화
	int row, col, tmp, max;
	{
		row = col = tmp = max = -1;
	}

	// 입력 부
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			cin >> tmp;
			// 최댓값의 순서는 상관없다.
			if (max < tmp) {
				max = tmp;
				row = i;
				col = j;
			}
		}
	}

	// 출력 부
	cout << max << "\n" << row + 1 << " " << col + 1;

	return 0;
}