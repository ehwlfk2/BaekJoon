/**
* 5597. 과제 안 내신 분..?
* 학생은 총 30명.
* 과제 제출 안한 2명을 찾아라.
*/
#include<iostream>
#define taskDone 28
using namespace std;

int main(void) {
	// 빠른 입출력을 위해
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	const int student = 31;
	int tmp;
	int cls[student] = { 0, };

	// 입력 및 프로세스
	for (int i = 0; i < taskDone; ++i) {
		cin >> tmp;
		++cls[tmp];
	}

	// 출력
	for (int i = 1; i < student; ++i) {
		if(cls[i] < 1){
			cout << i << "\n";
		}
	}

	return 0;
}