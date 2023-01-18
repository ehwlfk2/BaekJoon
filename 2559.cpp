/* 수열 */
#include <iostream>
using namespace std;

// ============================== 읽고쓰기 ==============================
char buf[1 << 16];
int idx = 1 << 16;

inline char read() {
	if (idx == 1 << 16) {
		fread(buf, 1, 1 << 16, stdin);
		idx = 0;
	}
	return buf[idx++];
}
inline int readInt() {
	int sum = 0;
	char now = read();
	bool sign = false; // 음수이면 true

	while (now == ' ' || now == '\n') now = read();
	if (now == '-')  sign = true, now = read();
	while (now >= '0' && now <= '9') {
		sum = sum * 10 + now - 48;
		now = read();
	}
	return sign ? -sum : sum;
}

//============================== 프로세스 ==============================
int main() {
	const int size = 100000;

	int arr[size] = { 0, };

	int n, k, i, sum = 0, max = 0;
	n = readInt();
	k = readInt();

	for (i = 0; i < k; i++) {
		const int num = readInt();
		arr[i] = num;

		sum += num;
	}
	max = sum;
	for (; i < n; i++) {
		const int num = readInt();
		arr[i] = num;

		sum += (arr[i] - arr[i - k]);
		if (max < sum) max = sum;
	}

	printf("%d", max);

	return 0;
}