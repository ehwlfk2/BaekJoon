/* 16139. 인간-컴퓨터 상호작용 
입력
	1. 특정 문자열: S
		(1) 0부터 센다.
		(2) 0 <= 문자열 길이 <= 200,000
		(3) 알파벳 소문자로 이뤄져있다.
	2. 질문의 수: q
		(1) 알파벳, 검색 시작 Index, 검색 종료 Index
		(2) 해당 알파벳은 검색 시작, 종료 Index도 포함한다.
		(3) 범위는 다음과 같다. 0 <= 시작 Index <= 종료 Index <= 문자열 길이
	3. 질문
	...
	q+2. 질문
처리
	배열[알파벳 수: 26][문자가 들어올 수 있는 최대 수: 200,000]에 문자열(S)를 뜯어서 분해해 넣는다.
	ex) seungjaehwang
		a[0] = {6, 10}
출력
	질문에 대한 답변을 진행한다. (알파벳 = 알파벳 아스키 코드 - 97)
	검색 시작 index <= a[알파벳] <= 검색 종료 index
	위 범위에 적합한 수를 출력한다.
*/

#include <iostream>
#include <string>
using namespace std;

// ============================== 읽고쓰기 ==============================
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
	bool sign = false; // 음수이면 true

	while (now == ' ' || now == '\n') now = read();
	if (now == '-')  sign = true, now = read();
	while (now >= '0' && now <= '9') {
		sum = sum * 10 + now - 48;
		now = read();
	}
	return sign ? -sum : sum;
}

// ============================== 프로세스 ==============================
const int MAX = 200001, TOTAL_ALPHA = 26;

string S;
int arr[MAX][TOTAL_ALPHA], q;

int main() {
	
	// (1) 입력
	
	/*
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	*/
	cin >> S;
	q = readInt();
	
	// (2) 처리
	for (int i = 0; i < S.size(); i++) {
		const int alpha_code = S[i] - 97;
		
		for (int j = 0; j < TOTAL_ALPHA; j++) {
			arr[i + 1][j] = arr[i][j];
		}
		++arr[i + 1][alpha_code];
	}

	// (3) 출력
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