#include<iostream>
#define SWAP(x,y,temp) ((temp) = (x), (x) = (y), (y) = (temp))
using namespace std;

void quickSort(int* data, int start, int end) {
	if (start >= end) return;

	// key �� ù ��° ����
	int key = start; 
	int i = start, j = end + 1, temp;

	// ������ ������ �ݺ�
	while (i <= j) { 
		do {
			i++;
		} while (i <= end && data[i] <= data[key]);
		
		do {
			j--;
		} while (j > start && data[j] >= data[key]);
	
		// ���� ������ ���¸� Ű ���� ��ü
		if (i > j) {
			SWAP(data[j], data[key], temp);
		}
		// �������� �ʾҴٸ� i�� j�� ��ü
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