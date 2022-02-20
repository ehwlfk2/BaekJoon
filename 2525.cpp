/**
* 2525. ���� �ð�
* �ð�(0~23), ��(0~59), �ʿ��� �ð�(��, maximum = 1,000)
*/

#include<iostream>
using namespace std;

void setting() {
	std::cout.tie(NULL);
	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
}

int main(void) {
	setting();
	
	int hours, minutes, times;
	cin >> hours >> minutes >> times;

	// process
	minutes += times;
	
	// minutes
	while (!(minutes < 60)) {
		minutes -= 60;
		hours++;
	}
	// hours
	while (!(hours < 24)) hours -= 24;
	
	cout << hours << " " << minutes;

	return 0;
}