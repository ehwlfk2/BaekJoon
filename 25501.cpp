/** 25501.
* 테스트케이스 개수: 1<= T <= 100
* 알파벳 대문자로 이뤄진 문자열 S: 1 <= |S| <= 1000
*/
#include <stdio.h>
#include <string.h>
// #pragma warning(disable: 4996)

int cnt;

int recursion(const char* s, int l, int r) {
    cnt++; 

    if (l >= r) return 1;
    else if (s[l] != s[r]) return 0;
    else return recursion(s, l + 1, r - 1);
}

int isPalindrome(const char* s) {
    return recursion(s, 0, strlen(s) - 1);
}

int main() {
    int t, b;
    char c[1001];
    scanf("%d", &t);

    while (t--) {
        scanf("%s", c);

        cnt = 0;
        b = isPalindrome(c);
        printf("%d %d\n", b, cnt);
    }
    
    return 0;
}