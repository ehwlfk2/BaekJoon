#include<iostream>
#define max(a,b) ((a) > (b) ? (a) : (b))

// 문자열 최장 길이 = 1000
int lcs[1001][1001];

int main(void) {
	std::string A, B;
	std::cin >> A >> B;

	// LCS 공식
	int aSize = A.size(), bSize = B.size();
	for (int i = 1; i <= aSize; i++) {
		for (int j = 1; j <= bSize; j++) {
			if (A[i - 1] == B[j - 1]) {
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			}
			else {
				lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
			}
		}
	}

	printf("%d", lcs[aSize][bSize]);
	return 0;
}