/**
* 11659. 구간 합 구하기 4
* 수 N개가 주어졌을 때, i부터 j번째 수까지 합을 구하자.
* 1 <= N <= 100,000
* 1 <= M <= 100,000
* 1 <= i <= j <= N
* sum 의 최대값 100,000,000
*/
#include<iostream>
#define max 100001
using namespace std;

// int arr[max][max] = { 0, };
// 쉽게 가볼까?
int arr[max] = { 0, };

int main(void) {
	//fastIO
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int  n, m;
	cin >> n >> m;

	// 입력
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}

	// 프로세스
	while(m--){
		int i, j;
		cin >> i >> j;
		
		// 출력
		cout << arr[j] - arr[i-1] << "\n";
	}

	return 0;
}