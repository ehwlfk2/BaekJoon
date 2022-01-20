// 2164
#include<cstdio>
#define max 500'001
#pragma warning(disable:4996)

int arr[max];

int main(void) {
	int n, cnt = scanf("%d", &n);

	if (cnt > 0) {
		// init
		cnt = n;
		for (int i = 1; i < n+1; i++) {
			arr[i] = i;
		}
		// Â¦¼ö : false, È¦¼ö : true
		bool b;

		while (cnt > 1) {
			b = cnt % 2 == 0 ? false : true;
			if (b) arr[1] = arr[cnt];

			for (int i = 1, j = b ? 2 : 1; i < cnt; i += 2) {
				arr[j++] = arr[i + 1];
			}
			cnt /= 2;
			if (b) cnt++;
		}
	}
	printf("%d", arr[1]);

	return 0;
}