#include<iostream>
using namespace std;

int main(void) {
	int test_case, width, height, num;
	cin >> test_case;

	while (test_case--) {
		cin >> height >> width >> num;
		printf("%d\n", ((num % height) ? num % height : height) * 100 + (num-1) / height + 1);
	}

	return 0;
}