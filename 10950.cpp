#include<iostream>
using namespace std;

int main(void) {
    int T;
    cin >> T;
    for (int testcase = 0; testcase < T; testcase++) {
        int a, b;
        cin >> a >> b;

        printf("%d\n", a + b);
    }
    return 0;
}