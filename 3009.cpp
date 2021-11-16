#include<iostream>
#define choose(a,b,c) ((a) == (b) ? (c) : (a) == (c) ? (b) : (a))
using namespace std;

/*
	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
*/

int main(void) {
	int x[3], y[3];
	for (int i = 0; i < 3; i++)
		cin >> x[i] >> y[i];
	printf("%d %d\n", choose(x[0], x[1], x[2]), choose(y[0], y[1], y[2]));
	return 0;
}