#include<iostream>
#define POS_SIZE 3
#define TOWER_SIZE 20
using namespace std;



class TowerOfHanoi {
private:
	void move(int spos, int epos) {
		printf("%d %d\n", spos, epos);
	}

	void countMethod(int height) {
		int count = 0;

		do {
			count = count * 2 + 1;
		} while (--height);

		printf("%d\n", count);
	}
public:
	TowerOfHanoi() {
		int height;
		cin >> height;

		countMethod(height);
		mechanism(height, 1, 3);
	}

	//spos: 출발지, mpos: 경유지, epos: 도착지
	void mechanism(int height, int spos, int epos) {
		//탈출 조건
		if (!(height > 1)) {
			move(spos, epos);
		}
		else {
			int mpos = spos == 1 ? epos == 2 ? 3 : 2 : spos == 2 ? epos == 1 ? 3 : 1 : epos == 1 ? 2 : 1;
			mechanism(height - 1, spos, mpos);
			move(spos, epos);
			mechanism(height - 1, mpos, epos);
		}
	}
};

int main(void) {
	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	TowerOfHanoi* p = new TowerOfHanoi();
	delete(p);
	return 0;
}