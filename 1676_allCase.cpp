/*
* 1676 팩토리얼 0의 개수
* Q. 1의 자리부터 0이 몇개인가? (+1 해서 출력)
*
* 모든 수 상정.
*	1. 10은 2와 5의 곱으로 이뤄져있다.
*	2. 팩토리얼이기때문에 2가 부족할 가능성은 없다.
*	3. 문제에서 요구하는 답은 5의 갯수와 동일하다.
*/
#include<iostream>

int main(void) {
	int n, cnt, tmp;
	std::cin >> n;

	cnt = 0;
	for (int i = 5; i <= n; i++) {
		tmp = i;
		while (tmp % 5 == 0) {
			cnt++;
			tmp /= 5;
		}
	}
	printf("%d", cnt);

	return 0;
}