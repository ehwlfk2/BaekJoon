#pragma warning(disable: 4996)
#include<stdio.h>
#include<algorithm>

using namespace std;

int a[10][10], i, j, b[10][10], c[10][10], d[10][10];

void f(int x)
{
	int k, z;

	if (x == 82) {
		for (k = 1; k <= 9; k++) {
			for (z = 1; z <= 9; z++) {
				printf("%d ", a[k][z]);
			}
			printf("\n");
		}
		exit(0);
	}

	if (a[(x - 1) / 9 + 1][(x - 1) % 9 + 1] != 0) f(x + 1);
	for (k = 1; k <= 9; k++) {
		if (
			a[(x - 1) / 9 + 1][(x - 1) % 9 + 1] == 0 
			&& b[k][(x - 1) / 9 + 1] == 0 
			&& c[k][(x - 1) % 9 + 1] == 0 
			&& d[k][(x - 1) / 9 / 3 * 3 + (x - 1) % 9 / 3 + 1] == 0
			) {
			b[k][(x - 1) / 9 + 1]++;  
			c[k][(x - 1) % 9 + 1]++;  
			d[k][(x - 1) / 27 * 3 + (x - 1) % 9 / 3 + 1]++; 
			a[(x - 1) / 9 + 1][(x - 1) % 9 + 1] = k;

			f(x + 1);
			
			b[k][(x - 1) / 9 + 1]--;  
			c[k][(x - 1) % 9 + 1]--;  
			d[k][(x - 1) / 27 * 3 + (x - 1) % 9 / 3 + 1]--;  
			a[(x - 1) / 9 + 1][(x - 1) % 9 + 1] = 0;
		}
	}
}
int main() {
	for (i = 1; i <= 9; i++)
		for (j = 1; j <= 9; j++) {
			scanf("%d", &a[i][j]);
			b[a[i][j]][i] = 1;
			c[a[i][j]][j] = 1;
			d[a[i][j]][(j - 1) / 3 + (i - 1) / 3 * 3 + 1] = 1;
		}
	f(1);
}