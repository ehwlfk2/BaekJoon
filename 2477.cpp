/**
* 2477. 참외밭
* 반시계 방향으로 곡지점이 주어진다
* line = 다각형은 반드시 육각형이다. -> 변의 길이는 여섯 번 들어온다. (1<= line <= 500)
* 다각형의 모양을 ㄱ자를 회전시킨 모양이다.
* -> 긴 가로, 세로로 넓이를 구하고 작은 가로와 세로로 구한 넓이를 뺴준다.
* cnt = 1m^2 에 참외가 들어가는 수가 주어진다. (1<= cnt <= 20)
* 반시계반향으로 왼쪽 1, 오른쪽 2, 아래쪽 3, 위쪽 4
* total = cnt * square. (max total is 5,000,000.)
*/
#include<iostream>
using namespace std;
/*
[0][0]: 긴 가로 길이
[0][1]: 긴 세로 길이
[1][0]: 짧은 가로 길이
[1][1]: 짧은 가로 길이
*/
#define polygon 6
#define idx(a, i) ((a) - (i) < 0 ? (a) - (i) + polygon : (a)-(i))

int cnt, lines[polygon] = { 0, }, directs[polygon] = { 0, }, small_rect;

int main(void) {

	// 1m^2의 참외 수 입력
	cin >> cnt;

	// 변 입력
	int direct, line, long_width = 0, long_height = 0;
	for (int i = 0; i < polygon; ++i) {
		cin >> direct >> line;
		
		// 방향 카운트로 모양 예측
		directs[i] = direct;
		lines[i] = line;

		switch (direct) {
		case 1:
		case 2:
			// 가로
			if (long_width < line) long_width = line;
			break;
		case 3:
		case 4:
			// 세로
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
	
	// 출력
	cout << (long_width * long_height - small_rect) * cnt;
	
	return 0;
}