#include<iostream>
using namespace std;

int nt;
string q, a[3], r, e;

string r_pnt(int n) {
	string p;
	while (n--)
		p += r;
	return p;
}

void repeat(int n) {
	r_pnt;
	if (n < nt) {
		cout << r_pnt(n) << q << r_pnt(n) << a[0] << r_pnt(n) << a[1] << r_pnt(n) << a[2];
		repeat(n+1);
		cout << r_pnt(n) << e;
	}
	else if (n == nt) {
		cout << r_pnt(n) << q << r_pnt(n) << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n" << r_pnt(n) << e;
	}
}

int main(void) {
	q = "\"����Լ��� ������?\"\n";
	a[0] = "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
	a[1] = "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
	a[2] = "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";
	r = "____";
	e = "��� �亯�Ͽ���.\n";

	cin >> nt;
	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
	repeat(0);

	return 0;
}
