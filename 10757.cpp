#include<iostream>
using namespace std;

int sum(int a, int b, int* over) {
	int tmp = a + b + *over - 48;
	tmp > 57 ? *over = 1, tmp -= 10 : *over = 0;
	return (char)(tmp % 58);
}

int main(void) {
	int l, s, over;
	string a, b;
	cin >> a >> b;

	// a -> long, b -> short
	if (a.length() < b.length()) {
		string c = a;
		a = b;
		b = c;
	}

	l = a.length();
	s = b.length();
	over = 0;

	while (s--) {
		a[--l] = sum(a[l], b[s], &over);
	}

	while (l-- && over) {
		a[l] = sum(a[l], 48, &over);
	}

	if(over > 0) a.("1");
	printf("%s", a.c_str());
}