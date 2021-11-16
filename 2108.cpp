#include<iostream>
#define size 4000
#define length 8001
using namespace std;

int main(void) {

	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int num, i, n, * m = new int[length] {0};
	double sum = 0;

	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> num;
		sum += num;
		m[num + size]++;
	}
	
	int min, max, cnt, mid = n / 2 + 1, maxCnt[4] = { 0 }; // cnt, num
	i = -1;

	// min
	while (m[++i] == 0);
	maxCnt[0] = cnt = m[i]; // cnt
	maxCnt[1] = min = i - size; // num

	
	// mid
	while (cnt < mid) {
		cnt += m[++i];
		if (maxCnt[0] <= m[i]) {
			if (maxCnt[0] < m[i]) {
				maxCnt[0] = m[i]; // cnt
				maxCnt[1] = i - size; // num
				maxCnt[2] = 0;
			}
			else {
				if (maxCnt[2] == 0) {
					maxCnt[2] = m[i];
					maxCnt[3] = i - size;
				}
			}
		}
	}
	mid = i - size;

	// max
	while (cnt < n) {
		cnt += m[++i];
		if (maxCnt[0] <= m[i]) {
			if (maxCnt[0] < m[i]) {
				maxCnt[0] = m[i]; // cnt
				maxCnt[1] = i - size; // num
				maxCnt[2] = 0;
			}
			else {
				if (maxCnt[2] == 0) {
					maxCnt[2] = m[i];
					maxCnt[3] = i - size;
				}
			}
		}
	}
	max = i - size;

	printf("%d\n%d\n%d\n%d\n", 
		sum > 0 ? (int)(sum / n + 0.5) : (int)(sum / n - 0.5),
		mid, maxCnt[2] == 0 ? maxCnt[1] : maxCnt[3], max - min);

	return 0;
}