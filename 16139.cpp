/* 16139. �ΰ�-��ǻ�� ��ȣ�ۿ� 
�Է�
	1. Ư�� ���ڿ�: S
		(1) 0���� ����.
		(2) 0 <= ���ڿ� ���� <= 200,000
		(3) ���ĺ� �ҹ��ڷ� �̷����ִ�.
	2. ������ ��: q
		(1) ���ĺ�, �˻� ���� Index, �˻� ���� Index
		(2) �ش� ���ĺ��� �˻� ����, ���� Index�� �����Ѵ�.
		(3) ������ ������ ����. 0 <= ���� Index <= ���� Index <= ���ڿ� ����
	3. ����
	...
	q+2. ����
ó��
	�迭[���ĺ� ��: 26][���ڰ� ���� �� �ִ� �ִ� ��: 200,000]�� ���ڿ�(S)�� �� ������ �ִ´�.
	ex) seungjaehwang
		a[0] = {6, 10}
���
	������ ���� �亯�� �����Ѵ�. (���ĺ� = ���ĺ� �ƽ�Ű �ڵ� - 97)
	�˻� ���� index <= a[���ĺ�] <= �˻� ���� index
	�� ������ ������ ���� ����Ѵ�.
*/

#include <iostream>
#include <string>
using namespace std;

// ============================== �а��� ==============================
char buf[1 << 16];
int idx = 1 << 16;

inline char read() {
	if (idx == 1 << 16) {
		fread(buf, 1, 1 << 16, stdin);
		idx = 0;
	}
	return buf[idx++];
}
inline int readInt() {
	int sum = 0;
	char now = read();
	bool sign = false; // �����̸� true

	while (now == ' ' || now == '\n') now = read();
	if (now == '-')  sign = true, now = read();
	while (now >= '0' && now <= '9') {
		sum = sum * 10 + now - 48;
		now = read();
	}
	return sign ? -sum : sum;
}

// ============================== ���μ��� ==============================
const int MAX = 200001, TOTAL_ALPHA = 26;

string S;
int arr[MAX][TOTAL_ALPHA], q;

int main() {
	
	// (1) �Է�
	
	/*
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	*/
	cin >> S;
	q = readInt();
	
	// (2) ó��
	for (int i = 0; i < S.size(); i++) {
		const int alpha_code = S[i] - 97;
		
		for (int j = 0; j < TOTAL_ALPHA; j++) {
			arr[i + 1][j] = arr[i][j];
		}
		++arr[i + 1][alpha_code];
	}

	// (3) ���
	while (q--) {

		char alpha;
		int strIdx, endIdx, alpha_code;
		
		// cin >> alpha >> strIdx >> endIdx;
		alpha = read();
		strIdx = readInt();
		endIdx = readInt();
		alpha_code = alpha - 97;

		cout << arr[endIdx + 1][alpha_code] - arr[strIdx][alpha_code] << "\n";
	}

	return 0;
}