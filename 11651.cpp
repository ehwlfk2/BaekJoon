/**
* 11650. 좌표 정렬하기
* a, b 쌍으로 값이 주어진다.
* (1) a의 오름차순
* (2) a 값이 같을 때, b 오름차순
*/
#include<iostream>
#include<string>
#include<algorithm>
#define max 100001
using namespace std;

pair<int, int> pos[max];

void setting() {
	std::cout.tie(NULL);
	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
}

int main(void) {
	setting();

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> pos[i].first >> pos[i].second;
	}

	sort(pos, pos + n, [](const pair<int, int>& lhs, const pair<int, int>& rhs) {
		if (lhs.second == rhs.second)
			return lhs.first < rhs.first;
		else
			return lhs.second < rhs.second;
		});

	string printStr;
	for (int i = 0; i < n; i++) {
		printStr += to_string(pos[i].first) + " " + to_string(pos[i].second) + '\n';
	}

	cout << printStr;
	return 0;
}