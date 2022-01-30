#include<iostream>
#define max 100001
#define shift direct ? p = p->left : p = p->right
using namespace std;

typedef struct node {
	int value;
	struct node* left;
	struct node* right;
}node;

node memory[max], * p;
char word[max];
bool direct; // true : left, false : right.
int arrSize;

void initMemory() {
	char tmp;
	int val;
	cin >> tmp;
	for (int i = 0; i < arrSize; i++) {
		cin >> val >> tmp;
		memory[i].left = &memory[(i - 1) < 0 ? arrSize - 1 : i - 1];
		memory[i].value = val;
		memory[i].right = &memory[(i + 1) >= arrSize ? 0 : i + 1];
	}
	if (arrSize == 0) cin >> tmp; // ']' 처리
	p = memory;
}

int countDelete() {
	int cnt = 0;
	for (int i = 0; word[i] != '\0'; i++) {
		if (word[i] == 'D') cnt++;
	}
	return cnt;
}

void print(bool b = false) {
	if (b) { // true
		printf("error\n");
	}
	else { // false
		printf("[");
		for (int i = 0; i < arrSize - 1; i++) {
			printf("%d,", p->value);
			shift;
		}
		arrSize == 0 ? printf("]\n") : printf("%d]\n", p->value);
	}
}

void pop() {
	p->left->right = p->right;
	p->right->left = p->left;
	shift;
	arrSize--;
}

void setting() {
	// std::cout.tie(NULL);
	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
}

int main(void) {
	setting();

	int N;
	cin >> N;

	while (N--) {
		// 명령 입력
		cin >> word;

		// 배열의 사이즈
		cin >> arrSize;

		// 배열 입력 받기, 초기화
		initMemory();
		direct = false;

		// process
		if (arrSize < countDelete()) print(true);
		else {
			for (int i = 0; word[i] != '\0'; i++) {
				switch (word[i]) {
				case 'R':
					direct = !direct;
					shift;
					break;
				case 'D':
					pop();
				}
			}
			print();
		}
		cin.clear();
	}

	return 0;
}