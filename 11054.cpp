#include<iostream>
#define size 1000

int n, m[size], d[size], a[size];

void input() {
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> m[i];
	}
}

void increase() {
	for (int i = 0; i < n; i++) {
		int cnt = 1;
		for (int j = 0; j < i; j++) {
			if (m[i] > m[j] && cnt <= d[j]) cnt = d[j] + 1;
		}
		d[i] = cnt;
	}
}

void decrease() {
	for (int i = n - 1; i > -1; i--) {
		int cnt = 1;
		for (int j = n - 1; j > i; j--) {
			if (m[i] > m[j] && cnt <= a[j]) cnt = a[j] + 1;
		}
		a[i] = cnt;
	}
}

int bytonic() {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum = sum < d[i] + a[i] ? d[i] + a[i] : sum;
	}
	return sum - 1;
}

int main(void) {

	input();
	
	increase();
	decrease();

	printf("%d", bytonic());
	
	return 0;
}