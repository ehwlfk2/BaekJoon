#include<iostream>
#include<cstring>
using namespace std;

class Goldbach {
private:
	const int size = 10000;
	int* p;

public:
	Goldbach() {
		p = new int[size];
		memset(p, 0, size);

		p[0] = p[1] = 1;
		for (int i = 2; i < size; i++) {
			if (p[i] != 1) {
				int j = i + i;
				while (j < size) {
					p[j] = 1;
					j += i;
				}
			}
		}//for
	}
	void partition(int num) {
		for (int i = num / 2; i < num; i++) {
			if (!p[i] && !p[num - i]) {
				printf("%d %d\n", num - i, i);
				return;
			}
		}
	}
	~Goldbach() {
		delete p;
	}
};


int main(void) {
	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	Goldbach* p = new Goldbach();

	int testcase;
	cin >> testcase;
	while (testcase--) {
		int num;
		cin >> num;
		p->partition(num);
	}
	delete(p);
	return 0;
}