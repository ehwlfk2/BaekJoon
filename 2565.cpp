#include<iostream>

// 전기줄 개수는 "n <= 100"인 자연수이고 그 위치는 "pos <= 500"인 자연수
int n, pos[501], lastNumber;

void input() {
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;

		// 시작 위치 = index
		std::cin >> tmp;
		if (tmp > lastNumber) lastNumber = tmp;

		// 도착 위치 = pos -> 같은 위치에 두개 이상의 전기줄이 있을 수 없다.
		std::cin >> pos[tmp];
	}
}

int findLis() {
	int l[101] = { 0 }, lis = 1, tmp;

	// Repeat until lastNumber index 
	for (int i = 0; i <= lastNumber; i++) {
		
		// '0' 이면 의미없는 값.
		if (!(tmp = pos[i])) continue;

		// LIS 계산!
		for (int j = lis; j > 0; j--) {
			if (l[j - 1] < tmp) {
				if (l[j] == 0) {
					l[j] = tmp;
					lis++;
				}
				else if (l[j] > tmp) {
					l[j] = tmp;
				}
				break;
			}
		}
	}

	return lis - 1;
}

int main(void) {

	input();
	printf("%d", n - findLis());

	return 0;
}