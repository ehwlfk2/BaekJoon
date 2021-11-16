#include<iostream>
#define space printf(" ")
#define dia printf("*")
#define enter printf("\n")
using namespace std;

/*
	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
*/

class diaMond {
private:
	int n;
	bool field[2188][2188] = { 0 };

	void star(int row, int col) {
		int size = 3;
		for (int i = row; i < row + size; i++) {
			for (int j = col; j < col + size; j++) {
				if (i == row + 1&& j == col + 1) continue;
				field[i][j] = 1;
			}
		}
	}

	void recursive(int x, int y, int size) {

		if (size > 3) {
			size /= 3;
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					if (i == 1 && j == 1) continue;
					recursive(x + i * size, y + j * size, size);
				}
			}
			/*
			size /= 3;
			recursive(x, y, size);
			recursive(x, y + size, size);
			recursive(x, y + size + size, size);

			x += size;
			recursive(x, y, size);
			//recursive(x + size, y + size, size);
			recursive(x, y + size + size, size);

			x += size;
			recursive(x, y, size);
			recursive(x, y + size, size);
			recursive(x, y + size + size, size);
			*/
		}
		else {
			star(x, y);
		}
	}

public:
	diaMond() {
		cin >> n;

		recursive(0, 0, n);
		print();
	}

	void print() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (field[i][j]) {//0
					dia;
				}
				else {//1
					space;
				}
			}
			enter;
		}
	}
};


int main(void) {
	int n;
	diaMond* p = new diaMond();
	delete(p);
	return 0;
}