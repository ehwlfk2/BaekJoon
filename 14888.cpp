#include<iostream>
/*
oper[0] plus
oper[1] minus
oper[2] multi
oper[3] divide
*/
using namespace std;
int n, m[100], oper[4], max_num, min_num;

int operator_plan(int op, int a, int b) {
	switch (op) {
	case 0:
		return a + b;
	case 1:
		return a - b;
	case 2:
		return a * b;
	case 3:
		return a / b;
	}
}

void back_tracking(int index, int sum) {
	if (index == n) {
		if (max_num < sum) max_num = sum;
		if (min_num > sum) min_num = sum;
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (oper[i] != 0) {
			oper[i]--;
			back_tracking(index + 1, operator_plan(i, sum, m[index]));
			oper[i]++;
		}
	}
}

int main(void) {

	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);


	//insert
	cin >> n;
	for (int i = 0; i < n; i++) cin >> m[i];
	cin >> oper[0] >> oper[1] >> oper[2] >> oper[3];
	
	//init
	max_num = -1000000000, min_num = 1000000000;

	back_tracking(1, m[0]);

	printf("%d\n%d", max_num, min_num);

	return 0;
}