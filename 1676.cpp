/*
* 1676 팩토리얼 0의 개수
* Q. 1의 자리부터 0이 몇개인가? (+1 해서 출력)
* 
* 입력 최대 수 500.
* 제일 마지막 수만 신경쓰면 되지 않을까?
*/
#include<iostream>

int main(void) {
	int n, cnt, mul;
	std::cin >> n;

	cnt = 0, mul = 1;
	for (int i = 2; i <= n; i++) {
		mul *= i;
		while (mul % 10 == 0) {
			cnt++;
			mul /= 10;
		}
		mul %= 1000;
	}
	printf("%d", cnt);

	return 0;
}