#include<iostream>
using namespace std;
	
int m,n,field[8];
 
void NM(int start, int end, int index) {
	for (int i = start; i < end; i++) {
		field[index] = i;
		if (index + 1 < n) {
			NM(i + 1, m - n + index + 3, index + 1);
		}
		else {
			for (int j = 0; j < n; j++) {
				printf("%d ", field[j]);
			}
			printf("\n");
		}
	}
}

int main(void) {
	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		field[i] = i + 1;
	}

 	NM(1, m - n + 2, 0);

	return 0;
}