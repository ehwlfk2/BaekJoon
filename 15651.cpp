/*
น้มุ 15651
https://www.acmicpc.net/problem/15651
https://coding-factory.tistory.com/606 
*/
#include<iostream>
using namespace std;

int m, n, field[8];

void Duplicate_permutation_nm(int deep) {

	for (int i = 0; i < m; i++) {
		field[deep] = i + 1;
		if (deep + 1 < n)
			Duplicate_permutation_nm(deep + 1);
		else {
			for (int j = 0; j < n; j++)
				printf("%d ", field[j]);
			printf("\n");
		}
	}
}


int main(void) {
	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	cin >> m >> n;

	Duplicate_permutation_nm(0);

	return 0;
}