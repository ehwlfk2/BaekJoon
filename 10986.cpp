/*
10986. ������ ��
	1 <= N <= 10^6, N���� ��
	2 <= M <= 10^3, ���� M ��

	���ӵ� ���� M���� ������������ ������?
*/
#include<iostream>
using namespace std;

// ============================== �а��� ==============================
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
	bool sign = false; // �����̸� true

	while (now == ' ' || now == '\n') now = read();
	if (now == '-')  sign = true, now = read();
	while (now >= '0' && now <= '9') {
		sum = sum * 10 + now - 48;
		now = read();
	}
	return sign ? -sum : sum;
}

// ============================== ���μ��� ==============================
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