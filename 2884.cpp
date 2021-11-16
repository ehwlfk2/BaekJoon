#include<iostream>
using namespace std;

int main(void) {
	int h, m;
	cin >> h >> m;

	if ((m = m - 45) < 0) {
		h--;
		m += 60;
	}
	if (h < 0) h = 23;
	printf("%d %d", h, m);
	return 0;
}