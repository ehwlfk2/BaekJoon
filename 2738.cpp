/**
* 2738. 행렬 덧셈
* N*M 행렬인 A, B를 더해보자.
* (1) N, M <= 100
* (2) -100 <= 행렬의 원소 <= +100
*/
#include<iostream>
#define max 100
using namespace std;

int main(void) {
	// 빠른 입출력을 위해
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n, m, matrix[max][max];
	int i, j, tmp;
	
	// n, m 입력
	cin >> n >> m;

	// 첫번째 행렬
	for(i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j) {
			cin >> matrix[i][j];
		}
	}

	// 두번째 행렬
	for (i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j) {
			cin >> tmp;
			matrix[i][j] += tmp;
		}
	}

	// 출력
	for (i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j) {
			cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}