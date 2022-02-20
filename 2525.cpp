/**
* 2525. 오븐 시계
* 시간(0~23), 분(0~59), 필요한 시간(분, maximum = 1,000)
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