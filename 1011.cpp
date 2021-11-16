#include<iostream>
#include<string.h>
using namespace std;

//int* val = new int[46346];

int main(void) {
	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int num, flag = 0;
	long long int val;
	cin >> num;
	//memset(val, 0, 46346 * sizeof(int));

	while (num--) {
		int x, y, i;
		cin >> x >> y;

		y -= x; // y = °Å¸®

		i = 1, flag = 0;
		do {
			if (flag = !flag) {
				x = i / 2 + 1;
				val = (long long int)x * x;
			}
			else {
				x = i / 2;
				val = (long long int)x * (x + 1);
			}

			if (y <= val) break;

		} while (++i);

		printf("%d\n", i);
	}
	//delete(val);
	return 0;
}