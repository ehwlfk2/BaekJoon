#include<iostream>
using namespace std;

int main(void) {
	int n, count = 0;
	cin >> n;

	for (int j = 0, i; j < n; j++) {
		int alphabet[26] = { 0 };
		string word;
		cin >> word;

		for (i = 1; i < word.length(); i++) {
			if (word[i - 1] != word[i]) {
				if (alphabet[word[i] - 'a']) break; // 그룹 단어가 아니다.
				alphabet[word[i - 1] - 'a'] = 1;
			}
		}
		if(!(i < word.length())) count++;
	}
	printf("%d\n", count);

	return 0;
}