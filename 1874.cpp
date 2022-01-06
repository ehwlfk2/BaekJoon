#include<iostream>
// 스택 수열

#define max 100000

// std::string pnt;
char pnt[max * 4];
int stack[max], si, n, pi;

void setting() {
	std::cout.tie(NULL);
	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
}

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
		else {
			return 0;
		}
	}
}

bool process() {
	int i = 1, a = 0, inCnt = 0;
	std::cin >> n;


	while (a < n) {
		std::cin >> a;
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
	// i == n == a 일때 탈출.
	while (inCnt++ < n) {
		std::cin >> a;
		if(escape(a) == -1) return false;
	}
	return true;
}

int main(void) {
	setting();

	if (process()) {
		printf("%s", pnt);
	}
	else {
		printf("NO");
	}

	return 0;
}