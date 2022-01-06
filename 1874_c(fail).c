#include <stdio.h>
#include <stdbool.h>
#pragma warning(disable: 4996)
#define max 100000

// std::string pnt;
char pnt[max * 4];
int stack[max], si, n, pi;

void push(char c) {
	pnt[pi++] = c;
	pnt[pi++] = '\n';
}

int escape(int a) {
	if (si > 0) {
		if (stack[si - 1] == a) {
			push('-');
			si--;
			return 1;
		}
		else if (stack[si - 1] > a) {
			return -1;
		}
	}
	return 0;
}

bool process() {
	int i = 1, a = 0, inCnt = 0;
	scanf("%d", &n);

	while (a < n) {
		scanf("%d", &a);
		inCnt++;

		// escape, si == 0 : empty
		switch (escape(a)) {
		case -1:
			return false;
		case 1:
			continue;
		}

		while (i < a) {
			push('+');
			stack[si++] = i++;
		}
		push('+');
		push('-');
		i++;
	}
	// i == n == a ÀÏ¶§ Å»Ãâ.
	while (inCnt++ < n) {
		scanf("%d", &a);
		if (escape(a) == -1) return false;
	}
	return true;
}

int main(void) {
	if (process()) {
		puts(pnt);
	}
	else {
		puts("NO");
	}
	return 0;
}