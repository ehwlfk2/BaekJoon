// 1629. ����
/**
* �ܼ� Ƚ�� �ݺ������δ� �ð� �ʰ�, O(n)
* �ذ�å: recursive, O(n/2)
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
	// ¦��
	if (time % 2 == 0) {
		return square(rest(num, time / 2, mod) % mod) % mod;
	}
	// Ȧ��
	return ((square(rest(num, time / 2, mod) % mod) % mod) * (num % mod)) % mod;
}



// ����� �ӵ� ����ȭ
void setting() {
	std::cout.tie(NULL);
	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
}