#include<iostream>
#define max(a,b) ((a) > (b) ? (a) : (b))

int main(void) {
	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int n, value, m[4] = { 0 }; // 1<= n <= 10,000
	std::cin >> n;

	for (int i = 1; i <= n; i++) {
		std::cin >> value;

		/* i번째
		0: 선택x(연속), [i-1, i]
		1: 선택x,
		2: 선택0,
		3: 선택(연속), [i-1, i]
		*/

		m[0] = m[1];
		m[1] = max(max(m[2], m[3]), max(m[1], m[0]));
		m[3] = m[2] + value;
		m[2] = m[0] + value;
	}
	printf("%d", max(max(m[2], m[3]), max(m[1], m[0])));

	return 0;
}