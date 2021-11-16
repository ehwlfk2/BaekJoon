#include<iostream>
#define ab 1000000
using namespace std;

int arr[2000002];

int main(void) {

	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int n, num, i = 0;
	cin >> n;

	do{
		cin >> num;
		arr[num + ab] = 1;
	} while (++i < n);

	i = 0;
	do {
		if (arr[i++] == 1) {
			printf("%d\n", i - ab - 1);
			n--;
		}
	} while (n);

	return 0;
}