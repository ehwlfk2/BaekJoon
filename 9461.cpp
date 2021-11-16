#include<iostream>

long long int m[102] = { 0,1,1,1,2,2 };

void wave() {
	for (int i = 6; i <= 100; i++) {
		m[i] = m[i-1] + m[i-5];
	}
}

int main() {
	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	
	wave();
	int repeat;
	std::cin >> repeat;

	while (repeat--) {
		int n;
		std::cin >> n;
		std::printf("%d\n",m[n]);
	}

	return 0;
}