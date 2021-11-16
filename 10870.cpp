#include<iostream>
using namespace std;

/*
	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
*/

typedef struct node {
	int first = 0;
	int second = 1;
};

int fibonacciNumbers(node key,int n) {
	if (!(--n > 0)) return key.second;
	int tmp = key.second;
	key.second += key.first;
	key.first = tmp;
	return fibonacciNumbers(key, n);
}

int main(void) {
	int n; // n >= 0
	node key;
	cin >> n;
	if (n == 0) printf("0\n");
	else printf("%d\n", fibonacciNumbers(key, n));

	return 0;
}