#include<iostream>
#define size 8
using namespace std;

class Chess {
private:
	int row, col, min;
	bool m[51][51];

	void insert() {
		cin >> row >> col;
		char tmp;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				cin >> tmp;
				if (tmp == 'B') m[i][j] = true;
				else m[i][j] = false;
			}
		}
	}

	int numRepaint(int row, int col) {
		bool tmp = !m[row][col];
		int num = 0, tmpNum;

		for (int i = row; i < row + size; i++) {
			for (int j = col; j < col + size; j++) {
				if (tmp == m[i][j]) num++;
				tmp = !tmp;
			}
			tmp = !tmp;
		}
		tmpNum = size * size - num;
		return num > tmpNum ? tmpNum : num;
	}

public:


	Chess() {
		insert();

		min = 64;
		for (int i = 0; i <= row - 8; i++) {
			for (int j = 0; j <= col - 8; j++) {
				int tmp = numRepaint(i, j);
				if (min > tmp) min = tmp;
			}
		}

		printf("%d\n", min);
	}

};

int main(void) {

	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	Chess* p = new Chess;
	delete(p);

	return 0;
}