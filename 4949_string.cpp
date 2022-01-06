/*
* 4949. 균형잡힌 세상
*
* () [] 괄호를 체크해라.
* 한줄 마무리 문자는 '.'
*/
#include<cstdio>
#pragma warning(disable : 4996)

int main(void) {
	while (1) {
		// input
		char s[101] = {};
		scanf("%[^\n]s", s);

		// exit
		if (s[0] == '.') return 0;

		// init
		char st[100];
		int i = 0;
		bool b = true;

		// process
		for (char c : s) {
			if (c == '(' || c == '[') st[i++] = c;
			else if (c == ')') {
				if (!(i > 0 && st[--i] == '(')) {
					b = false;
					break;
				}
			}
			else if (c == ']') {
				if (!(i > 0 && st[--i] == '[')) {
					b = false;
					break;
				}
			}
			else if (c == '.') break;
		}// for
		if (i == 0 ? b : false)
			printf("yes\n");
		else
			printf("no\n");

		// 버퍼 비우기
		scanf("%*c");
	}// while
}