#include<iostream>
#define SWAP(x,y,temp) ((temp) = (x), (x) = (y), (y) = (temp))
using namespace std;

void quickSort(int* data, int start, int end) {
	if (start >= end) return;

	// key 는 첫 번째 원소
	int key = start; 
	int i = start, j = end + 1, temp;

	// 엇갈릴 때까지 반복
	while (i <= j) { 
		do {
			i++;
		} while (i <= end && data[i] <= data[key]);
		
		do {
			j--;
		} while (j > start && data[j] >= data[key]);
	
		// 현재 엇갈린 상태면 키 값과 교체
		if (i > j) {
			SWAP(data[j], data[key], temp);
		}
		// 엇갈리지 않았다면 i와 j를 교체
		else {
			SWAP(data[i], data[j], temp);
		}
	}

	quickSort(data, start, j - 1);
	quickSort(data, j + 1, end);
}

int main(void) {

	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int n, m[1000];
	cin >> n;
	
	for (int i = 0; i < n ; i++) cin >> m[i];
	quickSort(m, 0, n - 1);

	for (int i = 0; i < n; i++)
		printf("%d\n", m[i]);

	return 0;
}