#include<iostream>
using namespace std;

int main(void) {
	string word;
	int count = 0;

	do {
		cin >> word;
		count++;
	} while (!cin.eof());

	printf("%d", count - 1);
	return 0;
}