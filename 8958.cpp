#include<iostream>
using namespace std;

int main(void) {
	int T;
	cin >> T;

	while (T--) {
		int count = 0, sum = 0;
		string tmp;
		cin >> tmp;

		for (int i = 0; i < tmp.length(); i++) {
			switch (tmp[i]){
			case 'O': count++; sum += count;
				break;
			case 'X': count = 0;
			}
		}

		printf("%d\n", sum);
	}

	return 0;
}