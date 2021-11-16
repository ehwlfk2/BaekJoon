#include<iostream>
using namespace std;

int main(void) {
	int total, max = 0, i;
	double score[1000], sum = 0;

	cin >> total;

	for(i = 0; i < total; i++ ) {
		cin >> score[i];
		if (max < score[i]) max = score[i];
	}
	
	for (i = 0; i < total; i++) {
		score[i] = score[i] * 100 / max;
		sum += score[i];
	}

	printf("%lf\n", sum / total);
	return 0;
}