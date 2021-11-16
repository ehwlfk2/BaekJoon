#include<iostream>
using namespace std;

class BigBody {
private:
	int size;
	int m[51][4];

public:
	BigBody() {
		cin >> size;
		for (int i = 0; i < size; i++) {
			m[i][0] = i;
			cin >> m[i][1] >> m[i][2];
		}

		for (int i = 0; i < size; i++) {
			int rank = 1;
			for (int j = 0; j < size; j++) {
				if (m[i][1] < m[j][1] && m[i][2] < m[j][2]) rank++;
			}
			m[i][3] = rank;
		}

		for (int i = 0; i < size; i++) {
			printf("%d\n", m[i][3]);
		}
	}


};

int main(void) {

	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	BigBody* p = new BigBody;
	delete(p);

	return 0;
}