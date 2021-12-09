// ¿¬¼ÓÇÕ
#include<iostream>

int n; // 1 <= n <= 100,000
int m[100000]; // -1000 <= i <= 1000


void input() {
	std::cin >> n;

	for (int i = 0; i < n; i++)
		std::cin >> m[i];
}

int main(void) {

	input();

	int max, tmp;
	max = tmp = m[0];
	
	for (int i = 1; i < n; i++) {
		tmp += m[i];
		if (tmp < m[i]) tmp = m[i];

		if (max < tmp) max = tmp;
	}

	printf("%d", max);
	
	return 0;
}