#include<iostream>
using namespace std;

int main(void) {
	int num;
	string number;
	cin >> num >> number;
	num = 0;
	for (int i = 0; i < number.length(); i++) {
		num += number[i] - 48;
	}
	printf("%d\n", num);
	return 0;
}