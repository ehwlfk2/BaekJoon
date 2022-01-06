/*
* 4949. �������� ����
*
* () [] ��ȣ�� üũ�ض�.
* ���� ������ ���ڴ� '.'
*/
#include<cstdio>
#pragma warning(disable: 4996)

char brackets[50];

bool process(char tmp) {
	// brackets
	int b = 0;
	do {
		switch (tmp) {
		case '(':
			brackets[b++] = '(';
			break;
		case '[':
			brackets[b++] = '[';
			break;
		case ')':
			if (!(b > 0 && brackets[--b] == '(')) {
				while (tmp != '\n') scanf("%c", &tmp);
				return false;
			}
			break;
		case ']':
			if (!(b > 0 && brackets[--b] == '[')) {
				while (tmp != '\n') scanf("%c", &tmp);
				return false;
			}
			break;
		case '.':
			while (tmp != '\n') scanf("%c", &tmp);
			return b == 0 ? true : false;
		}
		scanf("%c", &tmp);
	} while (1);
}

int main(void) {

	// ��ü ���� �Է�
	do {
		char tmp;
		scanf("%c", &tmp);
		if (tmp == '.') break;
		// ��º�
		if (process(tmp))
			printf("yes\n");
		else
			printf("no\n");
	} while (1);

	return 0;
}