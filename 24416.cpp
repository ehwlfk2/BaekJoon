/* 24416. �˰��� ���� - �Ǻ���ġ �� 1 */
#include <iostream>
using namespace std;

int fib_num(int n) {
	int a = 3, b = 5, idx = 4;
	while (++idx < n) {
		int swp = a + b;
		a = b;
		b = swp;
	}
	return b;
}

int main() {
	int num;
	cin >> num;

	cout << fib_num(num) << " " << num - 2 << "\n";
	return 0;
}