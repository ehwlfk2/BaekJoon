/**
* 14425
* �Է� N M
* 1 <= N <= 10,000
* N -> ���� S, ���� ����.
* 1 <= M(value) <= 10,000
* 1 <= M(size) <= 500
* M -> ���� S�� �ִ��� Ȯ���� ���ڿ�
* ���ڿ� -> �ҹ��ڷ� �̷���.
* �Է� ���� >>> Ctrl + z
*/
#include<iostream>
#include<unordered_set>
using namespace std;

// ����� �ҽ�
char rbuf[1 << 20];
char wbuf[1 << 20];
char sbuf[1 << 10];
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
inline string readString() {
	int i = 0;
	char now = read();
	char flg = '\n';
	
	while (now <= 32) now = read();
	while (now >= 97 && now <= 122) {
		sbuf[i++] = now;
		now = read();
	}
	
	sbuf[i] = '\0';
	string word = sbuf;
	return word;
}

int unitSize(int n) { // �ڸ� ��
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
	wbuf[widx++] = c; // ���� ������(https://bodhi-sattva.tistory.com/42), (https://crazyj.tistory.com/6)
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
	write(' '); // ������
}


// �ٽ� �ҽ�
int main(void) {
	unordered_set<string> s; // set�� ����غ��� (https://hwan-shell.tistory.com/130)
	string w;

	int n, m, cnt = 0;
	n = readInt();
	m = readInt();
	while (n--) {
		s.insert(readString());
	}

	while (m--) {
		if (s.find(readString()) != s.end()) cnt++;
	}

	writeInt(cnt);
	bflush();
	return 0;
}

/*
// memory: 11844kb, tlrks: 412ms
#include<iostream>
#include<algorithm>
#include<vector>
#define max 10000
#define size 501
using namespace std;

int n, m, sum;
string word, s[max];

int compare(const string& a, const string& b) {
	int i = 0, j = 0;
	do {
		if (a[i] == b[j]) {
			i++;
			j++;
		}
		else {
			return (a[i] < b[j] ? 1 : -1);
		}
	// } while (a[i] != '\0' || b[j] != '\0');
	} while (i < a.length() || j < b.length());
	return 0;
}

void search() {
	int st, p, ed;
	st = 0, ed = n-1;

	while (st <= ed) {
		p = (st + ed) / 2;
		
		int move = compare(word, s[p]);
		if (move > 0) { // ����
			ed = p - 1;
		}
		else if (move < 0) { // ������
			st = p + 1;
		}
		else { // move == 0
			sum++;
			return;
		}
	}
}

int main(void) {

	int i;
	cin >> n >> m;

	sum = 0;
	for (i = 0; i < n; i++) {
		cin >> s[i];
	}

	sort(s, s + n);

	for (i = 0; i < m; i++) {
		cin >> word;
		search();
	}
	cout << sum;

	return 0;
}
*/