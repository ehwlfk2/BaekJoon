#include<iostream>
using namespace std;

int alphabetToInt(char c) {
	int num = c - 65;
	switch (num / 3) {
	case 0: case 1: case 2: case 3: case 4: case 5:
		return num / 3 + 3;
		break;
	case 6: case 7:
		return num % 3 == 0 ? num / 3 + 2 : num / 3 + 3;
		break;
	case 8:
		return 10;
	}
}

int main(void) {
	string word;
	int time = 0;
	
	cin >> word;
	for (int i = 0; i < word.length(); i++) {
		time += alphabetToInt(word[i]);
		//printf("%c : %d\n", word[i], alphabetToInt(word[i]));
	}
	
	printf("%d", time);
	return 0;
}