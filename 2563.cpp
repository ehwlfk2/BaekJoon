/**
* 2563. 색종이
* 색종이의 크기는 가로, 세로 10으로 고정.
* 주어지는 값: 색종이의 수, 색종이의 좌하측 좌표값
* 조건: 바탕의 크기 100x100, 색종이는 바탕을 벗어나지 않는다.
* 1. 쉽게 생각하자. 
	- 색종이로 덮어지면 1.
	- 이미 덮어져있으면 pass.
*/
#include<iostream>
#define size 10

using namespace std;

int main(void) {
	// 변수 선언	
	bool drawPaper[100][100] = { false, };
	int cnt, colorPaper, x, y;
	{
		cin >> colorPaper;
		cnt = 0;
	}

	// 입력 및 프로세스
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

	// 출력 부
	cout << cnt;

	return 0;
}