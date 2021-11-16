#include<iostream>
using namespace std;

int n, m[20][20], min_diff, half;
int a[10], b[10];

int score(int arr[], int index, int sum) {
	for (int i = index; i < half - 1; i++) {
		for (int j = i + 1; j < half; j++) {
			sum += m[arr[i]][arr[j]] + m[arr[j]][arr[i]];
		}
	}
	return sum;
}

int compare() {
	int temp = score(a, 0, 0) - score(b, 0, 0);
	if (temp < 0) return -temp;
	return temp;
}

void pick(int index, int value) {
	if (index == half) {
		for (int i = 0, j = 0, k = 0; i < n; i++) {
			if (a[j] == i) j++;
			else b[k++] = i;
		}

		int temp = compare();
		if (min_diff > temp) min_diff = temp;
		return;
	}

	for (int i = value ; i <= n - half + index; i++) {
		a[index] = i;
		pick(index + 1, i + 1);
	}
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	// n = Â¦¼ö, 4 <= n <= 20, 

	// insert
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> m[i][j];
		}
	}
	// init
	// min_diff = INT_MAX; // comfile error
	min_diff = 2000000000;
	half = n / 2;

	pick(0, 0);
	printf("%d", min_diff);

	return 0;
}