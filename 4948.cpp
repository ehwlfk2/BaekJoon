#include<iostream>
using namespace std;

class Bertrand {
private:
	const int size = 300000;
	int* p;

public:
	Bertrand() {
		p = new int[size];
		memset(p,0,size);

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

	int howManyPrime(int n) {
		int count = 0, squ = n + n + 1;
		for (int i = n + 1; i < squ; i++) {
			if (p[i] != 1) count++;
		}
		return count;
	}

	~Bertrand() {
		delete p;
	}
};


int main(void) {
	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int number;
	Bertrand* p = new Bertrand();
	while (1) {
		cin >> number;
		if (!number) break;
		printf("%d\n", p->howManyPrime(number));
	}
	delete(p);
	return 0;
}