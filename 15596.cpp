#include<iostream>
#include<vector>


long long sum(std::vector<int>& a) {
	long long int sum = 0;
	for (int i = 0; i < a.size(); i++) {
		sum += a[i];
	}
	return sum;
}


int main(void) {
	int num;
	std::cin >> num;
	std::vector<int> v;
	for (int i = 0; i < num; i++) {
		v.push_back(i);
	}
	printf("%lld", sum(v));
	return 0;
}