#include<iostream>
using namespace std;

int main(void) {
	int piece[] = { 1, 1, 2, 2, 2, 8 };
	int find;

	for (int i = 0; i < 6; i++) {
		cin >> find;
		cout << piece[i] - find << " ";
	}

	return 0;
}