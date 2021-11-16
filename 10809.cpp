#include<iostream>
using namespace std;

int main(void) {
	string word;
	int alphabet[26];
	fill_n(alphabet, 26, -1);

	cin >> word;
	for (int i = 0; i < word.length(); i++) {
		int* p = &alphabet[word[i] - 'a'];
		if (*p < 0) *p = i;
	}

	for (int i = 0; i < 26; i++)
		printf("%d ", alphabet[i]);
	return 0;
}