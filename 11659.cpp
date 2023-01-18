/**
* 11659. ���� �� ���ϱ� 4
* �� N���� �־����� ��, i���� j��° ������ ���� ������.
* 1 <= N <= 100,000
* 1 <= M <= 100,000
* 1 <= i <= j <= N
* sum �� �ִ밪 100,000,000
*/
#include<iostream>
#define max 100001
using namespace std;

// int arr[max][max] = { 0, };
// ���� ������?
int arr[max] = { 0, };

int main(void) {
	//fastIO
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int  n, m;
	cin >> n >> m;

	// �Է�
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}

	// ���μ���
	while(m--){
		int i, j;
		cin >> i >> j;
		
		// ���
		cout << arr[j] - arr[i-1] << "\n";
	}

	return 0;
}