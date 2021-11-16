#include<iostream>
using namespace std;

int main(void) {
    int a, b, c;
    cin >> a >> b >> c;
    printf("%d\n%d\n%d\n%d", (a + b) % c, (a + b) % c, (a * b) % c, (a * b) % c);
    return 0;
}