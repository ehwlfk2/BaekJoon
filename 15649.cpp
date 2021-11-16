#include<iostream>
#define factorial 40320
#define size 8
using namespace std;

typedef struct node {
	int num;
	struct node* link;
}node;

class CombinationFactorial {
private:
	int stack[size], sp;
	int m, n;
public:
	CombinationFactorial() {
		cin >> m >> n;
		sp = 0;
	}

	void recursive(int deep) { // deep until n
		if (!(deep < n)) {
			printStack();
			return;
		}

		for (int i = 1, j; i <= m; i++) {
			//search number
			for (j = 0; j < sp; j++) {
				if (stack[j] == i) break;
			}
			if (j < sp) continue;
			else {
				//recursive;
				stack[sp++] = i;
				recursive(deep + 1);
				sp--;
			}
		}
	}

	void printStack() {
		for (int i = 0; i < sp; i++) printf("%d ", stack[i]);
		printf("\n");
	}
};

int main(void) {
	CombinationFactorial* cb = new CombinationFactorial();

	cb->recursive(0);

	delete cb;
	return 0;
}