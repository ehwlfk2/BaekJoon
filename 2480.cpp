/**
* 2480. �ֻ��� ����
* �ֻ��� 3���� ������
* (1). ��� ���� ���̸� 10,000 + �� * 1,000
* (2). 2���� ���� ���̸� 1,000 + ���� �� * 100
* (3). ��� �ٸ� ���̸� (���� ū ��) * 100
*/

#include<iostream>
#define max(a,b) ((a) > (b) ? (a) : (b))
using namespace std;

void setting() {
	std::cout.tie(NULL);
	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
}

int main(void) {
	setting();

	int a, b, c, pay = 0;
	cin >> a >> b >> c;
	
	// process
	if (a == b || b == c || c == a) {
		if (a == b && b == c) pay = 10000 + a * 1000;
		else pay = (a == b || a == c) ? pay = 1000 + a * 100 : pay = 1000 + b * 100;
	}
	else {
		pay = max(max(a, b), max(b, c)) * 100;
	}

	cout << pay;
	return 0;
}