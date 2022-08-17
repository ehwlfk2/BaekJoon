#include<iostream>
using namespace std;

int main(void) {
	int x, n, s, v, c;
	cin >> x >> n;

	s = 0;
	while (n--) {
		cin >> v >> c;
		s += v * c;
	}

	cout << ((s == x) ? "Yes" : "No");
	
	return 0;
}