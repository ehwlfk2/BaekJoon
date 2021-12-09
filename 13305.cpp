#include<cstdio>
/**
* 1. 도시의 갯수 (2 <= N <= 100,000)
* 2. 왼쪽 도로부터 도로길이 입력 N-1개 ( 1 <= distance <= 1,000,000,000 )
* 3. 왼쪽 도시부터 주유소 리터당 가격 N 개 ( 1 <= liter <= 1,000,000,000 )
*
* 최대 값 : 십억 * 십억 * 십만 = long long int ??
*/


/* 입력 속도 향상 코드 */
char buf[1 << 17];

inline char read() {
	static int idx = 1 << 17;
	if (idx == 1 << 17) {
		fread(buf, 1, 1 << 17, stdin);
		idx = 0;
	}
	return buf[idx++];
}
inline int readInt() {
	int sum = 0;
	bool flg = 1;
	char now = read();

	while (now == 10 || now == 32) now = read();
	if (now == '-') flg = 0, now = read();
	while (now >= 48 && now <= 57) {
		sum = sum * 10 + now - 48;
		now = read();
	}

	return flg ? sum : -sum;
}

// 프로세스 코드
int n, dis[100000];

long long int acculLiter(int st, int ltr, int ed) {
	long long int d = 0;
	for (int j = ed - 1; j >= st; j--) {
		d += dis[j];
	}
	return d * ltr;
}

long long int liter() {
	n = readInt();
	int tmp, ltr, i, st = 0;
	long long int rtn = 0;

	// input
	for (int i = 0; i < n - 1; i++) {
		dis[i] = readInt();
	}

	// greedy
	ltr = readInt();
	for (i = 1; i < n - 1; i++) {
		tmp = readInt();

		// 주유 갱신!
		if (ltr > tmp) {
			rtn += acculLiter(st, ltr, i);
			ltr = tmp;
			st = i;
		}
	}
	// 마지막 도시의 주유값은 필요없는 정보다.
	tmp = readInt();

	// 주유 갱신!
	rtn += acculLiter(st, ltr, i);
	return rtn;
}

int main(void) {
	printf("%lld", liter());

	return 0;
}