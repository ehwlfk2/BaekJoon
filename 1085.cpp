#include<iostream>
#define max(x, y) ((x) < (y) ? (x) : (y))
using namespace std;

/*
	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
*/

int main() {
	int x, y, w, h;
	cin >> x >> y >> w >> h;
	printf("%d\n", max((x < y ? x : y), w - x < h - y ? w - x : h - y));
}