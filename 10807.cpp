/**
* 10807. 개수 세기
* 입력한 정수가 몇개 인가?
* -100 <= 정수의 갯수와 크기 <= 100
*/
#include<iostream>
using namespace std;

int main(void) {
	// 빠른 입출력을 위해
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	// 입력
	int arr[2 << 7] = { 0,};
	int input, repeat;
	
	cin >> repeat;
	while (repeat--) {
		cin >> input;
		++arr[input + 100];
	}

	// 출력
	int v;
	
	cin >> v;
	cout << arr[v + 100];

	return 0;
}