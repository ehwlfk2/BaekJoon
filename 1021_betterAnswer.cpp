#include<stdio.h>
#include<unistd.h>
using namespace std;

constexpr int BSIZE = 524288;
char buffer[BSIZE], oper[100005], output[BSIZE];
char its[105][4];

char* p = buffer + BSIZE, * pe = buffer + BSIZE, * o = output, * oe = output + BSIZE;
inline char readChar() {
    if (p == pe) {
        syscall(0, 0, buffer, BSIZE);
        p = buffer;
    }
    return *p++;
}
int readInt() {
    char c = readChar();
    while (c < '0' || c > '9') {
        c = readChar();
    }
    int ret = 0;
    while (c >= '0' && c <= '9') {
        ret = ret * 10 + c - '0';
        c = readChar();
    }
    return ret;
}
int readOp() {
    char c = readChar();
    while (c != 'R' && c != 'D') {
        c = readChar();
    }
    int i = 0, r = 0;
    for (; c == 'R' || c == 'D'; i++) {
        r += c == 'D';
        oper[i] = c;
        c = readChar();
    }
    oper[i] = 0;
    return r;
}
inline void flush() {
    syscall(1, 1, output, o - output);
    o = output;
}

inline void putC(char x) {
    if (o == oe) flush();
    *o++ = x;
}

void putS(const char* str) {
    while (*str) {
        if (o == oe) flush();
        *o++ = *str++;
    }
}

int s[100005];

int main() {
    for (int i = 0; i <= 999; i++)
        sprintf(its[i], "%d", i);
    int t = readInt();
    while (t--) {
        int drop = readOp();
        int n = readInt();
        int l = 0, r = n - 1;
        for (int i = 0; i < n; i++) s[i] = readInt();
        if (drop > n) {
            putS("error\n");
            continue;
        }
        else if (drop == n) {
            putS("[]\n");
            continue;
        }
        bool f = true;
        for (int i = 0; oper[i]; i++) {
            if (oper[i] == 'R') f = !f;
            else {
                if (f) l++;
                else r--;
            }
        }

        putC('[');
        if (f) {
            putS(its[s[l]]);
            while (++l <= r) {
                putC(',');
                putS(its[s[l]]);
            }
        }
        else {
            putS(its[s[r]]);
            while (l <= --r) {
                putC(',');
                putS(its[s[r]]);
            }
        }
        putS("]\n");
    }
    flush();
}
