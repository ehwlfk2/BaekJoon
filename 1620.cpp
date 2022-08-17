/**
* 1620.
* n: ���ϸ� ����
* m: ����� �ϴ� ���� ����
* 1 <= n, m <= 100,000 (�ڿ���)
* 1 < ���ϸ� �̸��� ���� < 21
*/

#include <iostream>
#include <string>
#include <map>
#define max 100001
using namespace std;

// �ٽ� �ҽ�
map<string, int> pokemon;
string pokemonIdx[max];

bool isNumber(char tmp) {
	return (tmp >= 48 && tmp <= 57);
}
bool isCharacter(char tmp) {
	return (tmp >= 65 && tmp <= 90) || (tmp >= 97 && tmp <= 122);
}

int main(void) {
	// ���� ������� ����
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

		// �ڿ���, �ҹ���, �빮��
		if (isNumber(tmp[0])) {
			cout << pokemonIdx[stoi(tmp) - 1] << "\n";
		}
		else { // isCharacter
			cout << pokemon[tmp] + 1 << "\n";
		}
	}

	return 0;
}