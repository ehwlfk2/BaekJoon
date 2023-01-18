/* 11478. ���� �ٸ� ���ڿ��� ����
* (1) �ܼ��ϰ� SET�� �ְ� ���� ���.
*/

/*
// (1) �ܼ��ϰ� SET�� �ְ� ���� ���.
#include <iostream>
#include <string>
#include <set>
using namespace std;

const string::size_type max_capacity = 1 << 10;

//============================== ���μ��� ==============================
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

//============================== ���μ��� ==============================
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