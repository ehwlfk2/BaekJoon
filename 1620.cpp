/**
* 1620.
* n: 포켓몬 개수
* m: 맞춰야 하는 문제 개수
* 1 <= n, m <= 100,000 (자연수)
* 1 < 포켓몬 이름의 길이 < 21
*/

#include <iostream>
#include <string>
#include <map>
#define max 100001
using namespace std;

// 핵심 소스
map<string, int> pokemon;
string pokemonIdx[max];

bool isNumber(char tmp) {
	return (tmp >= 48 && tmp <= 57);
}
bool isCharacter(char tmp) {
	return (tmp >= 65 && tmp <= 90) || (tmp >= 97 && tmp <= 122);
}

int main(void) {
	// 빠른 입출력을 위해
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n, m;

	cin >> n >> m;

	string name;
	for (int i = 0; i < n; i++) {
		cin >> name;
		pokemon.insert({ name, i });
		pokemonIdx[i] = name;
	}

	char tmp[22];
	while (m--) {
		cin >> tmp;

		// 자연수, 소문자, 대문자
		if (isNumber(tmp[0])) {
			cout << pokemonIdx[stoi(tmp) - 1] << "\n";
		}
		else { // isCharacter
			cout << pokemon[tmp] + 1 << "\n";
		}
	}

	return 0;
}