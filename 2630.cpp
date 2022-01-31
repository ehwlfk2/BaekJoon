/* 2630. 색종이 만들기
 *
 * field의 type : 2, 4, 8, 16, 32, 64, 128
 * color type : white, blue
 */
#include<iostream>
#define max 128
#define WHITE 0
#define BLUE 1
using namespace std;

int field[max][max], n, whiteCnt, blueCnt;

void divide(int x1, int x2, int y1, int y2);

void insert() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> field[i][j];
		}
	}
}

void colorCount(int color) {
	switch (color) {
	case WHITE:
		whiteCnt++;
		break;
	case BLUE:
		blueCnt++;
	}
}

bool isAllSameColor(int x1, int x2, int y1, int y2, int color) {
	while (x1 != x2) {
		for (int i = y1; i < y2; i++) {
			if (field[x1][i] != color) return false;
		}
		x1++;
	}
	return true;
}

// 정사각형
void conquer(int x1, int x2, int y1, int y2) {
	int color = field[x1][y1];
	if (isAllSameColor(x1, x2, y1, y2, color)) {
		colorCount(color);
	}
	else {
		divide(x1, x2, y1, y2);
	}
}

void divide(int x1, int x2, int y1, int y2) {
	int half_x = (x1 + x2) / 2, half_y = (y1 + y2) / 2;
	conquer(x1, half_x, y1, half_y);
	conquer(half_x, x2, y1, half_y);
	conquer(x1, half_x, half_y, y2);
	conquer(half_x, x2, half_y, y2);
}

void print() {
	cout << whiteCnt << "\n" << blueCnt;
}

void setting() {
	std::cout.tie(NULL);
	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
}

int main(void) {

	insert();
	conquer(0, n, 0, n);
	print();

	return 0;
}