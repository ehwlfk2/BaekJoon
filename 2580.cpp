#include<iostream>
#include<algorithm>
#define size 9
using namespace std;

typedef struct zero {
	// 좌표와 들어갈 수 있는 수.
	int x, y, i, n[10];
} zero;

class Sudoku {
private:
	int m[size][size], zi = 0;
	zero blank[size * size], * p;

	void insert() {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				// 스도쿠 수를 입력받는다.
				cin >> m[i][j];
				// 공란일 경우 좌표를 저장한다.
				if (!m[i][j]) {
					p = &blank[zi++];
					p->x = i;
					p->y = j;
					p->i = 0;
				}
			}
		}
	}

	void canInsertNumber(zero* pivot) {
		// 가로, 세로, 3x3 박스
		int number[10] = { 0 }, row = pivot->x, col = pivot->y;
		int boxRow = row / 3 * 3, boxCol = col / 3 * 3;

		for (int i = 0; i < size; i++) {
			number[m[row][i]] = 1;
			number[m[i][col]] = 1;
			number[m[boxRow + i / 3][boxCol + i % 3]] = 1;
		}

		for (int i = 0; i < 10; i++) {
			if (!number[i]) {
				pivot->n[pivot->i++] = i;
			}
		}
	}

	void checkNumberZero() {
		for (int i = 0; i < zi; i++) {
			canInsertNumber(&blank[i]);
		}
	}

	void heapSort(int st, int ed) {
		int n = (ed + st) / 2;
		if (n != st) {
			heapSort(st, n);
			heapSort(n + 1, ed);
		}

		int i = st, k = st, j = n + 1;
		while (1) {
			if (i > n || j > ed) break;
			if (blank[i].i < blank[j].i)
				p[k++] = blank[i++];
			else
				p[k++] = blank[j++];
		}

		while (!(i > n)) p[k++] = blank[i++];
		while (!(j > ed)) p[k++] = blank[j++];

		for (int i = st; i <= ed; i++) blank[i] = p[i];
	}

	void sort() {
		p = new zero[zi];
		heapSort(0, zi - 1);
	}

	bool isRight(int x, int y, int n) {
		int num[10] = { 0 }, bx = x / 3 * 3, by = y / 3 * 3;
		for (int i = 0; i < size; i++) {
			num[m[x][i]] = 1;
			num[m[i][y]] = 1;
			num[m[bx + i / 3][by + i % 3]] = 1;
		}
		if (num[n] == 0) return true;
		return false;
	}

	void print() {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				printf("%d ", m[i][j]);
			}
			printf("\n");
		}
	}

	void backTracking(int blank_index) {
		if (blank_index == zi) {
			print();
			exit(0);
		}
		zero* temp = &blank[blank_index];
		for (int i = 0; i < temp->i; i++) {
			if (isRight(temp->x, temp->y, temp->n[i])) {
				m[temp->x][temp->y] = temp->n[i];
				backTracking(blank_index + 1);
				m[temp->x][temp->y] = 0;
			}
		}
	}

public:
	Sudoku() {
		insert();
		checkNumberZero();
		//sort();
		backTracking(0);
	}
};

int main(void) {
	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	Sudoku* p = new Sudoku();
	delete(p);

	return 0;
}