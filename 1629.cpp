// 1629. 곱셈
/**
* 단순 횟수 반복문으로는 시간 초과, O(n)
* 해결책: recursive, O(n/2)
*/
#include<iostream>
using namespace std;

// Field

void setting();
long long int square(long long int num);
long long int rest(int num, int time, int mod);

int main() {
	// setting();
	
	int A, B, C;
	cin >> A >> B >> C;
	
	cout << rest(A, B, C);

	return 0;
}

long long int square(long long int num) {
	return num * num;
}

long long int rest(int num, int time, int mod) {
	if (time == 0) return 1;
	// 짝수
	if (time % 2 == 0) {
		return square(rest(num, time / 2, mod) % mod) % mod;
	}
	// 홀수
	return ((square(rest(num, time / 2, mod) % mod) % mod) * (num % mod)) % mod;
}



// 입출력 속도 최적화
void setting() {
	std::cout.tie(NULL);
	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
}