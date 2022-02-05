/* 1780. 종이의 개수
* 종이의 크기 : N
* 1 <= N <= 3^7, 3^k
*/
#include<iostream>
#define max 2187 // 2 << 11 // 4096
#define div 3
using namespace std;

int field[max][max], n, one, two, three;

void setting();
void insert();
void quadTree(int row, int col, int size);

// main
int main(void) {
	setting();

	// process... 
	insert();
	quadTree(0, 0, n);
	cout << one << "\n" << two << "\n" << three;

	return 0;
}

// 입출력 속도 최적화
void setting() {
	std::cout.tie(NULL);
	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
}

// 입력
void insert() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> field[i][j];
	}
}

// Recursive 탈출문
bool isAllSameValue(int row, int col, int size) {
	int value = field[row][col];
	for (int i = row; i < row + size; i++) {
		for (int j = col; j < col + size; j++) {
			if (value != field[i][j]) return false;
		}
	}
	return true;
}

// Cnt
void cnt(int val) {
	switch (val) {
	case -1: one++; break;
	case 0: two++; break;
	case 1: three++;
	}
}

// Process
void quadTree(int row, int col, int size) {
	if (isAllSameValue(row, col, size)) {
		cnt(field[row][col]);
		return;
	}
	// recursive
	int pos = size / div;
	for (int i = 0; i < div; i++) {
		for (int j = 0; j < div; j++) {
			quadTree(row + pos * i, col + pos * j, pos);
		}
	}
}
