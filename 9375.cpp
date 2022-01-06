/*
* 9375 �мǿ� ���غ�
* Q. �ǻ��� ������ �� �����ΰ�?
*
* �Է�
*	1. �׽�Ʈ ���̽� ( max : 100 )
*	2. �ǻ��� �� ( 0 <= n <= 30 )
*	3. �ǻ��� �̸� + ���� + �ǻ��� ����
* ����
*	1. ���� ������ �ǻ��� �ϳ��� ���� �� �ִ�.
*	2. ���� �̸��� �ǻ��� ����. -> �ǻ��� �ߺ� ����
*	3. �˸��̸� �ȵȴ�.
* Ǯ��
*	1. �ǻ��� ������ ���� ������ ���Ѵ�
*	2. �� ������ + 1 �Ͽ� ���Ѵ�.
*	3. �˸��� �� - 1 �Ͽ� ���.
*/
#include<iostream>
using namespace std;

int main(void) {
	int testcase;
	cin >> testcase;

	// testcase ����ŭ �ݺ�
	while (testcase--) {

		// �ʱ�ȭ
		int n, i, cnt[30] = { 0 }, size = 0;
		string clothes[30], tmp;

		// �ǻ��� ����ŭ �ݺ�
		cin >> n;
		while (n--) {
			// �ǻ��� �ߺ����� �ʱ� ������ �̸� ������ �ʿ� ����.
			cin >> tmp >> tmp;

			for (i = 0; i < size; i++) {
				if (tmp.compare(clothes[i]) == 0) {
					cnt[i]++;
					break;
				}
			}
			if (i == size) {
				clothes[size] = tmp;
				cnt[size++]++;
			}
		}

		// ���
		n = 1;
		for (i = 0; i < size; i++) {
			n *= (cnt[i] + 1);
		}
		printf("%d\n", n - 1);
	}

	return 0;
}