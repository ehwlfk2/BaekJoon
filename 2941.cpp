#include<iostream>
using namespace std;

/*
č	c=
ć	c-

dž	dz=
đ	d-

lj	lj

nj	nj

š	s=
ž	z=
*/

int main(void) {
	string word;

	//input data: [a-z][-][=]
	cin >> word;

	int count = 0;
	for (int i = 0; i < word.length(); i++) {
		if (i + 1 < word.length()) {
			switch (word[i]) {
			case 'c':
				if (word[i + 1] == '-' || word[i + 1] == '=') i++;
				break;
			case 'd':
				if (word[i + 1] == '-') i++;
				else if (i + 2 < word.length() && word[i + 1] == 'z' && word[i + 2] == '=') i += 2;
				break;
			case 'l':
			case 'n':
				if (word[i + 1] == 'j') i++;
				break;
			case 's':
			case 'z':
				if (word[i + 1] == '=') i++;
				break;
			}
		}
		count++;
	}
	printf("%d\n", count);

	return 0;
}