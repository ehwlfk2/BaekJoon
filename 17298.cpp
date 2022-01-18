// 17298. 오큰수
// Copyright 2020 <jehan.yoon>
#include <cstdio>
#include <algorithm>
namespace fio {
    constexpr size_t BUF_SIZ = 0x8'0000, SPARE = 20;
    char buf_i[BUF_SIZ], * p_in = buf_i, * p_max = p_in;

    inline char getCh(void) {
        if (p_in == p_max) {
            p_max = buf_i + fread(buf_i, 1, BUF_SIZ, stdin);
            p_in = buf_i;
        }
        return (p_in != p_max) ? *(p_in++) : -1;
    }

    template<typename T>
    inline T get(void) {
        int t, sign = 1;
        T r = 0;
        do {
            t = getCh();
        } while (t != '-' && (t < '0' || t > '9'));
        if (t == '-')  sign = -1, t = getCh();
        while (true) {
            r = r * 10 + t - '0'; t = getCh();
            if (t < '0' || t > '9')    break;
        }
        return r * sign;
    }

    char buf_o[BUF_SIZ + SPARE], * p_out = buf_o;

    template<typename T>
    void prt(T n, char delim = ' ') {
        if (n < 0) n = -n, * p_out++ = '-';
        char* ptr = p_out;
        do { *ptr++ = n % 10 + '0';  n /= 10; } while (n);
        std::reverse(p_out, ptr); // header : algorithm 필요.
        *ptr++ = delim;
        if (ptr < buf_o + BUF_SIZ) {
            p_out = ptr;
        }
        else {
            fwrite(buf_o, ptr - buf_o, 1, stdout); p_out = buf_o;
        }
    }

    inline void prtn(void) {
        *p_out++ = '\n';
        if (p_out >= buf_o + BUF_SIZ)
        {
            fwrite(buf_o, p_out - buf_o, 1, stdout); p_out = buf_o;
        }
    }

    void flush(void) {
        fwrite(buf_o, p_out - buf_o, 1, stdout);
        p_out = buf_o;
    }
};  // namespace fio

#define max 1000000
int n, a;
int print[max], valStk[max], idxStk[max], idx;

void push(int i) {
	valStk[idx] = a;
	idxStk[idx++] = i;
}

void pop() {
	int index = idxStk[--idx];
	print[index] = a;
}

int main(void) {
    n = fio::get<int>();

	for (int i = 0; i < n; i++) {
        a = fio::get<int>();
        // 해당 수 왼쪽에 있는 값들을 대상으로 현재 값이 오큰수인 경우
		while (idx > 0 && valStk[idx - 1] < a) { 
			pop();
		}
		// 현재 입력된 값은 이제부터 오큰수를 찾는 대기열에 들어간다.
		push(i);
	}

	// 오큰수가 없는 값들
	a = -1;
	while (idx > 0) pop();

    for (int i = 0; i < n; i++)
        fio::prt(print[i]);
    fio::flush();

	return 0;
}