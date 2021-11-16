#include<iostream>
#define size 10001
using namespace std;

int main(void) {

	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int t, n, i, m[size] = { 0 };

	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> t;
		m[t]++;
	}
	for (i = 0; i < size; i++) {
		while(m[i]--) printf("%d\n", i);
	}

	return 0;
}