/**
* 1620.
* n: ���ϸ� ����
* m: ����� �ϴ� ���� ����
* 1 <= n, m <= 100,000 (�ڿ���)
* 1 < ���ϸ� �̸��� ���� < 21
*/

#include <iostream>
#include <map>
#define max 100001
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
// �ڿ����̱� ������ ��ȣ Ȯ�� ������ �ʿ����.
inline int readInt(char now) {
	int sum = 0;
	// char now = read();
	// bool flg = false;

	while (now <= 32) now = read();
	// if (now == 45) flg = true, now = read();
	while (now >= 48) sum = sum * 10 + now - '0', now = read();

	// return flg ? -sum : sum;
	return sum;
}
inline string readString(char now) {
	int i = 0;
	// char now = read();
	char flg = '\n';

	while (now <= 32) now = read();
	while (now >= 97 && now <= 122 || now >= 65 && now <= 90) { // �ҹ��� || �빮��
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
void writeString(string s) {
	int isz = s.length();
	if (isz + widx >= (1 << 20)) bflush();

	s.copy(&wbuf[widx++], isz);
	widx += isz;
}

// �ٽ� �ҽ�
map<string, int> pokemon;
string pokemonIdx[max];

bool isNumber(char tmp) {
	return (tmp >= 48 && tmp <= 57);
}
bool isCharacter(char tmp) {
	return (tmp >= 65 && tmp <= 90) || (tmp >= 97 && tmp <= 122);
}
int main(void) {
	int n, m;

	n = readInt(read());
	m = readInt(read());

	string name;
	for (int i = 0; i < n; i++) {
		name = readString(read());
		pokemon.insert({ name, i });
		pokemonIdx[i] = name;
	}

	char tmp;
	while (m--) {
		do { tmp = read(); } while (tmp <= 32);
		// �ڿ���, �ҹ���, �빮��
		if (isNumber(tmp)) {
			writeString(pokemonIdx[readInt(tmp) - 1]);
			write('\n');
		}
		else if (isCharacter(tmp)) { // isCharacter
			writeInt(pokemon[readString(tmp)] + 1);
			write('\n');
		}
	}

	bflush();
	return 0;
}