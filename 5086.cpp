/**
* 5086 배수와 약수
*
* 숫자 2개 입력 n1, n2 < 10,000 자연수
* 종료 숫자 n1 = n2 = 0
* 조건 : 두 숫자가 같은 경우는 없다.
*
* n1이 n2의 약수인가?
* n1이 n2의 배수인가?
* 둘다 아닌가?
*/
#include<iostream>

bool isFactor(int n1, int n2) {
	return n2 % n1 == 0 ? true : false;
}

int main(void) {
	int n1, n2;

	// 빠른 입출력을 위해
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	// 프로세스 부분
	while (true) {
		std::cin >> n1 >> n2;

		if (n1 == n2) { // 두 숫자가 같은 경우는 0 인 경우 뿐!
			break;
		}

		// 출력부
		if (isFactor(n1, n2)) {
			printf("factor\n");
		}
		else if (isFactor(n2, n1)) {
			printf("multiple\n");
		}
		else {
			printf("neither\n");
		}
	} // while

	return 0;
}