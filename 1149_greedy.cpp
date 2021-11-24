#include<iostream>

// rgb 비용과 최소비용누산값.
int cost[1001][4], n, min;

// 최소값 출력
int minVal(int a, int b) {
	return a < b ? a : b;
}
int minVal(int a, int b, int c) {
	return a < b ? a < c ? a : c : b < c ? b : c;
}

// (index, value)...
int* minIndexVal(int a, int b) {
	int* arr = new int[4];
	if (a < b) {
		arr[0] = 0;
		arr[1] = a;
		arr[2] = 1;
		arr[3] = b;
	}
	else {
		arr[0] = 1;
		arr[1] = b;
		arr[2] = 0;
		arr[3] = a;
	}
	return arr;
}
int* minIndexVal(int a, int b, int c) {
	int* arr = new int[6];
	if (a < b) { // a, b
		if (a < c) { // a, b?c
			arr[0] = 0;
			arr[1] = a;
			if (b < c) { // a, b, c
				arr[2] = 1;
				arr[3] = b;
				arr[4] = 2;
				arr[5] = c;
			}
			else { // a, c, b
				arr[2] = 2;
				arr[3] = c;
				arr[4] = 1;
				arr[5] = b;
			}
		}
		else { // c, a, b
			arr[0] = 2;
			arr[1] = c;
			if (a < b) { // c, a, b
				arr[2] = 0;
				arr[3] = a;
				arr[4] = 1;
				arr[5] = b;
			}
		}
	}
	else { // b, a
		if (b < c) { // b, a?c
			arr[0] = 1;
			arr[1] = b;
			if (a < c) { // b, a, c
				arr[2] = 0;
				arr[3] = a;
				arr[4] = 2;
				arr[5] = c;
			}
			else { // b, c, a
				arr[2] = 2;
				arr[3] = c;
				arr[4] = 0;
				arr[5] = a;
			}
		}
		else { // c, b, a
			arr[0] = 2;
			arr[1] = c;
			arr[2] = 1;
			arr[3] = b;
			arr[4] = 0;
			arr[5] = a;
		}
	}
	return arr;
}

// 입력값 처리 : cost
void input() {
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
	}
}

// 현재 최소비용과 누산값 연산 : min, cost[i][3]
void calculateMinCost() {
	int i = n - 1, j;

	// 초기 값.
	int* temp = minIndexVal(cost[i][0], cost[i][1], cost[i][2]);
	min = cost[i][3] = temp[1];
	j = temp[0];

	while (i > 0) {
		// 다음 행
		i--;

		// 현재최소비용 값 연산 : 규칙을 지키되 작은 수만 찾아서 더해준다.
		temp = minIndexVal(cost[i][(j + 1) % 3], cost[i][(j + 2) % 3]);
		j = temp[0] == 0 ? (j + 1) % 3 : (j + 2) % 3;
		min += temp[1];

		// 최소비용 누산 값 : cost[i][3]
		cost[i][3] = cost[i + 1][3] + minVal(cost[i][0], cost[i][1], cost[i][2]);
	}
}

// i = 배열의 index, j = 선택한 열 index, sum = 누산값.
void search(int i, int j, int sum) {
	if (i == n) {
		min = min < sum + cost[i][j] ? min : sum + cost[i][j];
		return;
	}

	int col1 = (j + 1) % 3, col2 = (j + 2) % 3;
	int sum1 = sum + cost[i][col1], sum2 = sum + cost[i][col2];
	// 최소비용 기대값 = sum + add
	int add = cost[i + 1][3];

	// 기대값이 작은 것부터
	if (sum1 < sum2) {
		if (sum1 + add < min) search(i + 1, col1, sum1);
		if (sum2 + add < min) search(i + 1, col2, sum2);
	}
	else {
		if (sum2 + add < min) search(i + 1, col2, sum2);
		if (sum1 + add < min) search(i + 1, col1, sum1);
	}
}

void search() {
	int* temp = minIndexVal(cost[0][0], cost[0][1], cost[0][2]);
	int add = cost[1][3];

	if (temp[1] + add < min) search(1, temp[0], temp[1]);
	if (temp[3] + add < min) search(1, temp[2], temp[3]);
	if (temp[5] + add < min) search(1, temp[4], temp[5]);
}

int main() {
	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	// input 값 받아오기
	input();

	// 최소비용 누산값 및 기대값 연산
	calculateMinCost();

	// 완전 탐색
	search();

	// 출력
	printf("%d\n", min);
	return 0;
}