/* 11478. 서로 다른 문자열의 개수
* (1) 단순하게 SET에 넣고 개수 출력.
*/

/*
// (1) 단순하게 SET에 넣고 개수 출력.
#include <iostream>
#include <string>
#include <set>
using namespace std;

const string::size_type max_capacity = 1 << 10;

//============================== 프로세스 ==============================
int main() {
    string word;
	word.reserve(max_capacity);

	cin >> word;

	set<string> subWord;
	const int size = word.size() + 1;

	for (int i = 0; i < size; ++i) {
		for (int j = 1; j < size - i; ++j) {
			subWord.insert(word.substr(i, j));
		}
	}

	cout << subWord.size();

	return 0;
}
*/

#include <algorithm>
#include <iostream>
#include <string>
#define max 1 << 10

using namespace std;

const string::size_type max_capacity{ max };

//============================== 프로세스 ==============================
int main() {
	string word;
	word.reserve(max_capacity);

	cin >> word;

	
	string subWord[max * max];
	int idx = 0;

	const int size = word.size() + 1;

	for (int i = 0; i < size; ++i) {
		for (int j = 1; j < size - i; ++j) {
			subWord[idx++] = word.substr(i, j);
		}
	}

	sort(subWord, subWord + idx);

	// cout << subWord.size();

	return 0;
}