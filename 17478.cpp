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
		cout << r_pnt(n) << q << r_pnt(n) << "\"재귀함수는 자기 자신을 호출하는 함수라네\"\n" << r_pnt(n) << e;
	}
}

int main(void) {
	q = "\"재귀함수가 뭔가요?\"\n";
	a[0] = "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n";
	a[1] = "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n";
	a[2] = "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n";
	r = "____";
	e = "라고 답변하였지.\n";

	cin >> nt;
	cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";
	repeat(0);

	return 0;
}
