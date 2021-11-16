#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


class blackJack {
private:
	int n, m, numList[101] = { 0 }, best;

	void bestSum(int index, int sum, int depth) {
		if (depth == 3){
			if(sum > best)
				best = sum;
			return;
		}

		int temp;
		for (int i = index; i < n; i++) {
			temp = sum + numList[i];
			if (temp > m) return;
			bestSum(i + 1, temp, depth + 1);
		}
	}

public:
	blackJack() {
		int i;
		cin >> n >> m;
		for (i = 0; i < n; i++) {
			cin >> numList[i];
		}

		sort(numList, numList + n);

		bestSum(0, 0, 0);

		printf("%d\n", best);
	}
};

int main(void) {

	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	blackJack* p = new blackJack;
	delete(p);

	return 0;
}