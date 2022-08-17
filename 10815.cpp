/**
* 10815.
* 숫자 카드 N개, 정수 M개
* 1 <= N(count), M <= 500,000
* -10,000,000 <= N(value) <= 10,000,000
*/

// 메모리 6024KB, 시간 84ms (출력만 버퍼쓰면 200ms, 입출력 버퍼쓰면 100ms, 핵심 코드를 재귀에서 반복문으로 바꾸면 현재 84ms)
#include<iostream>
#include<algorithm>
#define max 500000
using namespace std;

// 입출력 소스
char rbuf[1 << 20];
char wbuf[1 << 20];
int widx, ridx, nidx;
inline char read() {
	if (ridx == nidx) {
		nidx = fread(rbuf, 1, 1 << 20, stdin);
		if (!nidx) return 0;
		ridx = 0;
	}
	return rbuf[ridx++];
}

inline int readInt() {
	int sum = 0;
	char now = read();
	bool flg = false;

	while (now <= 32) now = read();
	if (now == 45) flg = true, now = read();
	while (now >= 48) sum = sum * 10 + now - '0', now = read();

	return flg ? -sum : sum;
}

int unitSize(int n) { // 자리 수
	if (n < 0)n = -n;
	int ret = 1;
	while (n >= 10) {
		ret++;
		n /= 10;
	}
	return ret;
}

void bflush() {
	fwrite(wbuf, 1, widx, stdout);
	widx = 0;
}

void write(char c) {
	if (widx == (1 << 20)) bflush();
	wbuf[widx++] = c;
}

void writeInt(int n) {
	int isz = unitSize(n);
	if (isz + widx >= (1 << 20)) bflush();

	if (n < 0) {
		wbuf[widx++] = '-';
		n = -n;
	}

	int next = widx + isz;
	while (isz--) {
		wbuf[widx + isz] = n % 10 + '0';
		n /= 10;
	}
	widx = next;
	write(' '); // 구분자
}

// 핵심 소스
int n, m, number;
int na[max];

bool search() {
	int st = 0, ed = n - 1, p;

	while (st <= ed) {
		p = (st + ed) / 2;
		if (number < na[p]) { // 왼쪽 검색
			ed = p - 1;
		}
		else if (number > na[p]) { // 오른쪽 검색
			st = p + 1;
		}
		else { // number == na[p]
			return true;
		}
	}
	return false;
}

int main(void) {
	int i, j;

	n = readInt();
	for (i = 0; i < n; i++) {
		na[i] = readInt();
	}

	sort(na, na + n);

	m = readInt();
	for (j = 0; j < m; j++) {
		number = readInt();
		writeInt((search() ? 1 : 0));
	}

	bflush();

	return 0;
}


/*
// 메모리 3972 KB, 시간 236 ms
#include<iostream>
#include<algorithm>
#define max 500000
using namespace std;

int n, m, number;
int na[max];

bool search(int st, int p, int ed) {

	if (number < na[p]) { // 왼쪽 검색
		return (p == ed ? false : search(st, (p + st) / 2, p));
	}
	else if (number > na[p]) { // 오른쪽 검색
		return (st == p ? false : search(p, (p + ed) / 2, ed));
	}
	else {
		return true;
	}
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int i, j;

	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> na[i];
	}

	sort(na, na + n);

	cin >> m;
	for (j = 0; j < m; j++) {
		cin >> number;
		cout << (search(0, n/2, n) ? 1 : 0) << " ";
	}

	return 0;
}
*/


/*
// 시간 초과!!
#include<iostream>
#include<algorithm>
#define max 500000
using namespace std;

int n, m;
int na[max];

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int i, j, number;

	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> na[i];
	}

	sort(na, na + n);

	cin >> m;
	for (j = 0; j < m; j++) {
		cin >> number;
		for (i = 0; i < n; i++) {
			if (na[i] == number) {
				cout << 1 << " ";
				break;
			}
		}
		if (i == n) cout << 0 << " ";
	}

	return 0;
}
*/


/*
// 메모리 9836 KB, 시간 280 ms
#include<iostream>
#include<algorithm>
#define max 500000
using namespace std;

typedef struct node {
	int index, value, answer;
}node;

int n, m;
int na[max];
node ma[max];

bool compare(node a, node b) {
	return a.value < b.value;
}

bool restore(node a, node b) {
	return a.index < b.index;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int i, j;

	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> na[i];
	}

	cin >> m;
	for (i = 0; i < m; i++) {
		cin >> ma[i].value;
		ma[i].index = i;
		ma[i].answer = 0;
	}

	sort(na, na + n);
	sort(ma, ma + m, compare);

	i = j = 0;
	while(i < n && j < m) {
		if (na[i] < ma[j].value) {
			i++;
		} else if (na[i] > ma[j].value) {
			j++;
		} else { // na[i] == ma[j].value
			ma[j].answer = 1;
			j++;
		}
	}

	sort(ma, ma + m, restore);

	for (i = 0; i < m; i++) {
		cout << ma[i].answer << " ";
	}

	return 0;
}
*/