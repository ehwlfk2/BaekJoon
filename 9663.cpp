#include<iostream>
using namespace std;

class Queen {
private:
	int n, putQueen = 0, m[15][15] = { 0 };

	// 왼쪽 위에서 오른쪽 아래로
	void fill(int row, int col, bool b) {
		// row
		if (b) {
			m[row][col]++;
			// col, dia
			for (int i = 1; i < n - row; i++) {
				m[row + i][col]++;
				if (col + i < n) m[row + i][col + i]++;
				if (col - i >= 0) m[row + i][col - i]++;
			}
		}
		else {
			m[row][col]--;
			// col, dia
			for (int i = 1; i < n - row; i++) {
				m[row + i][col]--;
				if (col + i < n) m[row + i][col + i]--;
				if (col - i >= 0) m[row + i][col - i]--;
			}
		}
	}

	void numberOfQueen(int row) {
		/*
		int empty = n;
		for (int i = 0; i < n; i++) {
			if(m[row][i] == 0)
		}
		*/
		if (row == n) {
			putQueen++;
			return;
		}

		for (int i = 0; i < n; i++) {
			if (m[row][i] == 0) {
				fill(row, i, true);
				numberOfQueen(row + 1);
				fill(row, i, false);
			}
		}
	}

public:
	Queen() {
		cin >> n;	// 1 ~ 14

		numberOfQueen(0);
	}

	int howManyQueen() { return putQueen; }
};


int main(void) {

	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	Queen* p = new Queen;
	printf("%d", p->howManyQueen());
	delete(p);

	return 0;
}