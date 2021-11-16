#include<iostream>
using namespace std;

int countArithmeticSequence(int num) {
	int check_1 = num % 10, check_10 = num / 10 % 10, check_100 = num / 100;
	int count = 99, checkNum;
	for (int i = 1; i < check_100; i++) { // 100의 자리!
		count += 5;
	}
	for (int j = 0; j < check_10; j++) { // 10의 자리!
		checkNum = (j << 1) - check_100;
		if (0 <= checkNum && checkNum < 10) count++;
	}
	checkNum = (check_10 << 1) - check_100;
	if (0 <= checkNum && checkNum <= check_1) count++;
	return count;
}

int main(void) {
	int num, count = 0;
	cin >> num;
	if (num < 100) { // 두자리는 항상 등차수열!
		count = num;
	}
	else { // 세자리는 계산해야됩니다! 100 < num <= 1000
		count = countArithmeticSequence(num);
	}
	printf("%d\n", count);
}