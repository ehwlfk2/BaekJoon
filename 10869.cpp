#include<iostream>
using namespace std;

int main(void) {
    int a, b;
    cin >> a >> b;
    
    printf("%d\n%d\n%d\n%d\n%d", a + b, a - b, a * b, a / b, a % b);
    return 0;
}