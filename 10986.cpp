/*
10986. 나머지 합
	1 <= N <= 10^6, N개의 수
	2 <= M <= 10^3, 기준 M 값

	연속된 합이 M으로 나눠떨어지는 갯수는?
*/
#include<iostream>
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

// ============================== 프로세스 ==============================
int main(void) {
	// ----- declar -----
	const int M_MAX = 1000;
	int n, m, mods[M_MAX] = { 0, };
	long long int cnt = 0;

	// ----- insert -----
	cin >> n >> m;
	for (int i = 0, sum = 0; i < n; ++i) {
		++mods[sum = (sum + readInt()) % m];
	}

	// ----- process -----
	for (int i = 0; i < m; ++i) {
		cnt +=  mods[i] * ((long long)mods[i] - 1) / 2;
	}

	cout << cnt + mods[0];
	return 0;
}