/**
* 1 <= 숫자 카드의 개수 N <= 500,000
* -10,000,000 <= Number Size <= 10,000,000
* 1 <= 확인할 숫자 카드의 개수 M <= 500,000
*/
#include <iostream>
#include <map>

void fastIO() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

int main(void) {
	fastIO();

	int n, m, t;
	std::map<int, int> card;

	std::cin >> n;
	while (n--) {
		std::cin >> t;
		if (card.find(t) != card.end()) {
			card[t] = card.find(t)->second + 1;
		}
		else {
			card[t] = 1; //card.insert({ t, 1 });
		}
	}

	std::cin >> m;
	while (m--) {
		std::cin >> t;
		std::cout << card[t] << " ";
	}

	return 0;
}