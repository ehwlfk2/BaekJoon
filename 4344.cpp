#include<iostream>
using namespace std;

int main(void) {
	int T;
	cin >> T;

	while (T--) {
		int totalStudent;
		double avg = 0, count = 0;
		int student[1000];
		cin >> totalStudent;

		for (int i = 0; i < totalStudent; i++) {
			cin >> student[i];
			avg += student[i];
		}

		avg /= totalStudent;
		for (int i = 0; i < totalStudent; i++) {
			if (student[i] > avg) count++;
		}

		printf("%.3lf%%\n", count * 100 / totalStudent);
	}

	return 0;
}