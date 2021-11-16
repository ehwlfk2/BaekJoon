#include<iostream>
using namespace std;

int main(void) {
	constexpr int size = 10001;
	int num[size] = { 0 };

	for (int i = 1; i < size; i++) {
		int index = i, tmp = i;
		while (tmp > 0) {
			index += tmp % 10;
			tmp /= 10;
		}
		if (index < size) num[index]++;
	}

	for (int i = 1; i < size; i++) {
		if(!(num[i]))	printf("%d\n", i);
	}

	return 0;
}