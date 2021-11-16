#include<iostream>
using namespace std;

class DevilNumbering {
private:
	int nth, num = 666;
	//중간 연산
	int after = 0, after_digit = -1, before;

public:
	DevilNumbering() {
		cin >> nth;
		//nth = 5000;

		for (int i = 1; i < nth; i++) {
			nextDevilNumber();
			//printf("%d -> %d\n", i, num);
		}

		printf("%d\n", num);
	}

	void nextDevilNumber() {
		if (!(after_digit < 0)) {
			if (++after < after_digit) {
				num++;
			}
			else {
				after_digit = -1;
				num = before * 1000 + 666;
			}
			return;
		}
		
		before = num / 1000;

		before++;
		num = before * 1000 + 666;

		int t_digit = divideNumber(num);
		if (t_digit == 1) return;
		else {
			after_digit = t_digit;
			after = 0;
			before++;
			num = (num / (t_digit * 1000)) * t_digit * 1000 + 666 * t_digit + after;
		}
	}

	int divideNumber(int num) {
		int tnum = num, digit = 1000, count = 0;

		while (tnum / digit) {
			digit *= 10;
		}

		do {
			digit /= 10;
			if (tnum / digit == 6) {
				count++;
				if (count == 3)	return digit;
			}
			else count = 0;
			tnum %= digit;
		} while (1);
	}
};

int main(void) {

	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	DevilNumbering* p = new DevilNumbering();
	delete(p);

	return 0;
}