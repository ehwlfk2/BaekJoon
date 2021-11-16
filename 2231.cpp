#include<iostream>
using namespace std;

class divSum {
private:
	int num, tmp, dis, min;

	void find(int st) {

		for (int i = st; i < num; i++) {
			tmp = dis = i;
			do {
				tmp += dis % 10;
			} while (dis /= 10);

			if (tmp == num) {
				min = i;
				return;
			}
		}

		min = 0;
	}	

public:
	divSum(int num) {
		this->num = tmp = num, dis = 0;

		// dis = 나올 수 있는 가장 작은 수.
		do {
			dis += 9;
		} while (tmp /= 10);

		find(num - dis <= 0 ? 1 : num - dis);
	}

	int getMin() { return min; }
};


int main(void) {

	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int num;
	cin >> num;

	divSum* p = new divSum(num);
	printf("%d\n", p->getMin());
	delete(p);

	return 0;
}