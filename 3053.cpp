#include<iostream>
using namespace std;
/*
	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
*/
int main(void) {
	constexpr double my_pi = 3.141592653589793238462643383279502884L;

	int r;
	cin >> r;
	printf("%lf\n", (double)r * r * my_pi);
	printf("%lf\n", (double)r * r * 2);
}