#include<iostream>

// 연산자 중복 없고, 숫자의 최대 자리수는 5자리, 식의 최대 길이 50.
int main(void) {
	int sum = 0, tmp;
	bool flag = true; // 음수가 한번이라도 나왔으면 flag = false;

	// process
	while(1){
		// input
		std::cin >> tmp;
		if (std::cin.eof()) break;

		if (flag) {
			if (tmp < 0)
				flag = !flag;
			sum += tmp;
		}
		else {
			sum += tmp < 0 ? tmp : -tmp;
		}
	}

	printf("%d", sum);

	return 0;
}