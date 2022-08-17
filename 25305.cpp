#include<iostream>
#include<algorithm>
using namespace std;

bool compare(int a, int b) {
	return a > b;
}

int main(void) {
	int n, k, x;
	int scores[1000];
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> scores[i];
	}

	sort(scores, scores + n, compare);
	cout << scores[k - 1];

	return 0;
}