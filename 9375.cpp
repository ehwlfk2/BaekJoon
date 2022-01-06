/*
* 9375 패션왕 신해빈
* Q. 의상의 조합은 몇 종류인가?
*
* 입력
*	1. 테스트 케이스 ( max : 100 )
*	2. 의상의 수 ( 0 <= n <= 30 )
*	3. 의상의 이름 + 공백 + 의상의 종류
* 조건
*	1. 같은 종류의 의상은 하나만 입을 수 있다.
*	2. 같은 이름의 의상은 없다. -> 의상의 중복 배제
*	3. 알몸이면 안된다.
* 풀이
*	1. 의상의 종류에 따른 갯수를 구한다
*	2. 각 갯수에 + 1 하여 곱한다.
*	3. 알몸의 수 - 1 하여 출력.
*/
#include<iostream>
using namespace std;

int main(void) {
	int testcase;
	cin >> testcase;

	// testcase 수만큼 반복
	while (testcase--) {

		// 초기화
		int n, i, cnt[30] = { 0 }, size = 0;
		string clothes[30], tmp;

		// 의상의 수만큼 반복
		cin >> n;
		while (n--) {
			// 의상이 중복되지 않기 때문에 이름 정보는 필요 없다.
			cin >> tmp >> tmp;

			for (i = 0; i < size; i++) {
				if (tmp.compare(clothes[i]) == 0) {
					cnt[i]++;
					break;
				}
			}
			if (i == size) {
				clothes[size] = tmp;
				cnt[size++]++;
			}
		}

		// 출력
		n = 1;
		for (i = 0; i < size; i++) {
			n *= (cnt[i] + 1);
		}
		printf("%d\n", n - 1);
	}

	return 0;
}