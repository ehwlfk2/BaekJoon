/*
* 1037 약수
* 
* 첫 줄에 1과 자신을 제외한 모든 약수의 갯수가 입력된다
* 둘 째 줄에 해당 약수들이 입력된다.
* 
* 풀이 : 그냥 입력된 모든 약수중 가장 작은 수와 가장 큰 수를 곱하면 원래의 수가 된다.
*/

#include<iostream>

int main(void) {
	int n, divisor, min, max;

	min = 1000000;
	max = 2;

	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> divisor;
		if (divisor > max) max = divisor;
		if (divisor < min) min = divisor;
	}

	printf("%d", min * max);
	return 0;
}