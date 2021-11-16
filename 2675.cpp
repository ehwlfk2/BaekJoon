#include<iostream>
using namespace std;

int main(void) {
	int T;
	cin >> T;
	for (int test_case = 0; test_case < T; test_case++) {
		int repeat;
		string word;
		
		cin >> repeat >> word;

		for (int i = 0; i < word.length(); i++) {
			for (int j = 0; j < repeat; j++) printf("%c", word[i]);
		}

		printf("\n");
	}
	return 0;
}