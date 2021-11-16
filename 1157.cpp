#include<iostream>
using namespace std;

int main(void) {
	string word;
	int alphabet[26] = { 0 }, max = 0, count = 0, index;

	cin >> word;

	for (int i = 0; i < word.length(); i++) {
		if (word[i] > 96) word[i] -= 32; // 대문자화
		int* p = &alphabet[word[i] - 65]; 
		if (++ * p > max) {
			max = *p;
			count = 1;
			index = i;
		}
		else if (*p == max) count++;
	}

	if (count == 1) printf("%c", word[index]);
	else printf("?");
	return 0;
}