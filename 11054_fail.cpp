#include<iostream>
int n, m[1001];
int incIdx, decIdx;

void input() {
	// initial
	m[0] = 0;

	// input
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> m[i];
	}
}

bool compare(int x, int y, int b) {
	switch (b){
	case 0:
		return x < y;
	case 1:
		return x > y;
	case 2:
		return x <= y;
	}
}

void process(int arr[][2], int* p, int b) {
	*p = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = *p; j > 0; j--) {
			if (compare(arr[j - 1][0], m[i], b)) {
				// 초기상태
				if (arr[j][0] == 0) {
					arr[j][0] = m[i];
					arr[j][1] = i;
					*p = *p + 1;
				}
				// 갱신
				else if (compare(arr[j][0], m[i], b + 1)) {
					arr[j][0] = m[i];
					arr[j][1] = i;
				}
				break;
			}
		}
	}
}

int concatArray(int inc[][2], int dec[][2]) {
	// inc -> dec 순서로 연결
	int length = 1, i = incIdx - 1, j = decIdx;
	dec[j][1] = 1001;

	while (i >= 0 && j >= 0) {
		if (inc[i][1] < dec[j][1] && inc[i][0] > dec[j][0]) {
			length = i + decIdx - j;
			j--;
		}
		else {
			i--, j--;
		}
	}
	return length;
}

int main(void) {
	input();

	//[0] = value, [1] = index
	int inc[1001][2] = { 0 }, dec[1001][2] = { 0 };
	int* p;

	// initial, increase array
	p = &incIdx;
	process(inc, p, 0);

	// initial, descrease array
	dec[0][0] = 1001;
	p = &decIdx;
	process(dec, p, 1);

	// concat increase array and decrease array.
	printf("%d", concatArray(inc, dec));
	return 0;
}