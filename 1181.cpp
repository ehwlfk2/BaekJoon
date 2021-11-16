#include<iostream>
#define word_size 27

using namespace std;

bool compareWord(string a, string b, int size) {
	for (int i = 0; i < size; i++) {
		if (a[i] != b[i]) {
			if (a[i] < b[i]) return true;
			else return false;
		}
	}
	return false;
}

void swap(string* i, string* j) {
	string* k = i;
	i = j;
	j = k;
}

void qsortWord(string* m, int st, int ed) {
	if (st >= ed) return;

	int pivot = st, size = m[st].size();
	int i = st, j = ed + 1;

	while (i <= j) {
		do {
			i++;
		} while (i <= ed && m[i].size() < size || m[i].size() == size && compareWord(m[i], m[pivot], size));
		do {
			j--;
		} while (j >= st && m[j].size() > size || m[j].size() == size && compareWord(m[pivot], m[j], size));


		// 현재 엇갈린 상태면 j와 pivot 과 교체
		if (i > j) {
			swap(m[j], m[pivot]);
		}
		// 엇갈리지 않았다면 i와 j 를 교체
		else {
			swap(m[i], m[j]);
		}
	}

	qsortWord(m, st, j - 1);
	qsortWord(m, j + 1, ed);
}

void print(string* m, int n) {
	int j = 0, i = 0;
	printf("%s\n", m[i++].c_str());
	while (i < n) {
		if (m[i] != m[j])
			printf("%s\n", m[i].c_str());
		i++, j++;
	}
}

int main(void) {

	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	string* word = new string[20000];

	for (int i = 0; i < n; i++) {
		cin >> word[i];
	}

	qsortWord(word, 0, n - 1);
	print(word, n);

	return 0;
}