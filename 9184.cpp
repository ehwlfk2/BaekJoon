#include<iostream>

int w[21][21][21];

// w[a][b][c] 값을 에러없이 반환
int getW(int a, int b, int c) {
	if (a < 1 || b < 1 || c < 1) {
		return 1;
	}
	else if (a > 20 || b > 20 || c > 20) {
		return w[20][20][20];
	}
	else {
		return w[a][b][c];
	}
}

// w[a][b][c] 에 해당하는 value를 반환.
int insertValue(int a, int b, int c) {
	int value;
	if (a < 1 || b < 1 || c < 1) {
		value = 1;
	}
	else if (a < b && b < c) {
		value = getW(a - 1, b, c) + getW(a, b - 1, c) - getW(a - 1, b, c - 1);
	}
	else { // otherwise
		value = getW(a - 1, b, c) + getW(a - 1, b - 1, c) + getW(a - 1, b, c - 1) - getW(a - 1, b - 1, c - 1);
	}
	return value;
}

// w 배열을 만들어두고 사용한다. 처음 만들 때만 시간이 걸리고 다음부터는 O(1)의 속도.
void createWArray() {
	for (int a = 1; a < 21; a++) {
		for (int b = 1; b < 21; b++) {
			for (int c = 1; c < 21; c++) {
				w[a][b][c] = insertValue(a, b, c);
			}
		}
	}
}



int main() {
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL);

	// create w Array.
	createWArray();

	// declare  variable
	int a, b, c;

	// input
	do {
		std::cin >> a >> b >> c;

		// while 탈출 조건
		if (a == -1 && b == -1 && c == -1) break;

		printf("w(%d, %d, %d) = %d\n", a, b, c, getW(a, b, c));
	} while (1);

	return 0;
}