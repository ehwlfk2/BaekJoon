#include<iostream>

// ������ �ߺ� ����, ������ �ִ� �ڸ����� 5�ڸ�, ���� �ִ� ���� 50.
int main(void) {
	int sum = 0, tmp;
	bool flag = true; // ������ �ѹ��̶� �������� flag = false;

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